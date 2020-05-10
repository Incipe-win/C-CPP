import re
from pymysql import connect

"""
URL_FUNC_DICT = {
    "/index.html": index,
    "/center.html": center
}
"""

URL_FUNC_DICT = dict()

def linked():
    # 创建Connection连接
    conn = connect(host='localhost',port=3306,user='root',password='mysql',database='stock_db',charset='utf8')
    # 获得Cursor对象
    cs = conn.cursor()
    return conn, cs

def closed(conn, cs):
    cs.close()
    conn.close()

def route(url):
    def set_func(func):
        # URL_FUNC_DICT["/index.py"] = index
        URL_FUNC_DICT[url] = func
        def call_func(*args, **kwargs):
            return func(*args, **kwargs)
        return call_func
    return set_func


@route(r"/index.html")
def index(ret):
    with open("./templates/index.html") as f:
        content = f.read()

    # my_stock_info = "哈哈哈哈 这是你的本月名称....."
    # content = re.sub(r"\{%content%\}", my_stock_info, content)
    conn, cs = linked()
    sql = """select * from info;"""
    cs.execute(sql)
    stock_infos = cs.fetchall()
    closed(conn, cs)

    tr_template = """<tr>
        <td>%s</td>
        <td>%s</td>
        <td>%s</td>
        <td>%s</td>
        <td>%s</td>
        <td>%s</td>
        <td>%s</td>
        <td>%s</td>
        <td>
            <input type="button" value="添加" id="toAdd" name="toAdd" systemidvaule="%s">
        </td>
        </tr>
    """

    html = ""
    for line_info in stock_infos:
        html += tr_template % (line_info[0],line_info[1],line_info[2],line_info[3],line_info[4],line_info[5],line_info[6],line_info[7], line_info[1])

    # content = re.sub(r"\{%content%\}", str(stock_infos), content)
    content = re.sub(r"\{%content%\}", html, content)

    return content
     

@route(r"/center.html")
def center(ret):
    with open("./templates/center.html") as f:
        content = f.read()

    # my_stock_info = "这里是从mysql查询出来的数据。。。"
    # content = re.sub(r"\{%content%\}", my_stock_info, content)
    conn, cs = linked()
    sql = """select i.code,i.short,i.chg,i.turnover,i.price,i.highs,f.note_info from info as i inner join focus as f on i.id=f.info_id;"""
    cs.execute(sql)
    stock_infos = cs.fetchall()
    closed(conn, cs)

    tr_template = """
        <tr>
            <td>%s</td>
            <td>%s</td>
            <td>%s</td>
            <td>%s</td>
            <td>%s</td>
            <td>%s</td>
            <td>%s</td>
            <td>
                <a type="button" class="btn btn-default btn-xs" href="/update/%s.html"> <span class="glyphicon glyphicon-star" aria-hidden="true"></span> 修改 </a>
            </td>
            <td>
                <input type="button" value="删除" id="toDel" name="toDel" systemidvaule="%s">
            </td>
        </tr>
    """

    html = ""
    for line_info in stock_infos:
        html += tr_template % (line_info[0],line_info[1],line_info[2],line_info[3],line_info[4],line_info[5],line_info[6],line_info[0],line_info[0])

    # content = re.sub(r"\{%content%\}", str(stock_infos), content)
    content = re.sub(r"\{%content%\}", html, content)

    return content

# 给路由添加正则表达式的原因：在实际开发时，url中往往会带有很多参数，例如/add/000007.html中000007就是参数，
# 如果没有正则的话，那么就需要编写N次@route来进行添加 url对应的函数 到字典中，此时字典中的键值对有N个，浪费空间
# 而采用了正则的话，那么只要编写1次@route就可以完成多个 url例如/add/00007.html /add/000036.html等对应同一个函数，此时字典中的键值对个数会少很多
@route(r"/add/(\d+)\.html")
def add_focus(ret):

    # 获取股票代码
    stock_code = ret.group(1)

    conn, cs = linked()
    # 判断股票代码是否存在
    sql = """select * from info where code = %s;"""
    cs.execute(sql, (stock_code, ))
    # 如果没有这个股票代码, 认为是非法请求!
    if not cs.fetchone():
        closed(conn, cs)
        return "请手下留情! "

    # 判断是否关注
    sql = """select * from info as i inner join focus as f on i.id = f.info_id where i.code = %s;"""
    cs.execute(sql, (stock_code, ))
    # 如果已经关注了
    if cs.fetchone():
        closed(conn, cs)
        return "已经关注过了..."

    # 关注股票代码
    sql = """insert into focus (info_id) select id from info where code = %s;"""
    cs.execute(sql, (stock_code, ))
    conn.commit()
    closed(conn, cs)
    
    return "关注成功!"


@route(r"/del/(\d+)\.html")
def del_focus(ret):

    # 获取股票代码
    stock_code = ret.group(1)

    conn, cs = linked()
    # 判断股票代码是否存在
    sql = """select * from info where code = %s;"""
    cs.execute(sql, (stock_code, ))
    # 如果没有这个股票代码, 认为是非法请求!
    if not cs.fetchone():
        closed(conn, cs)
        return "请手下留情! "

    # 判断是否关注
    sql = """select * from info as i inner join focus as f on i.id = f.info_id where i.code = %s;"""
    cs.execute(sql, (stock_code, ))
    # 如果没有关注了
    if not cs.fetchone():
        closed(conn, cs)
        print("%s" % stock_code)
        return "%s 没有关注过..." % stock_code

    # 取消关注股票代码
    sql = """delete from focus where info_id = (select id from info where code = %s);"""
    cs.execute(sql, (stock_code, ))
    conn.commit()
    closed(conn, cs)
    
    return "取消成功!"


def application(env, start_response):
    start_response('200 OK', [('Content-Type', 'text/html;charset=utf-8')])
    
    file_name = env['PATH_INFO']
    # file_name = "/index.py"

    """
    if file_name == "/index.py":
        return index()
    elif file_name == "/center.py":
        return center()
    else:
        return 'Hello World! 我爱你中国....'
    """

    try:
        # func = URL_FUNC_DICT[file_name]
        # return func()
        # return URL_FUNC_DICT[file_name]()
        for url, func in URL_FUNC_DICT.items():
            # {
            #   r"/index.html":index,
            #   r"/center.html":center,
            #   r"/add/\d+\.html":add_focus
            # }
            ret = re.match(url, file_name)
            if ret:
                return func(ret)
        else:
            return "请求的url(%s)没有对应的函数...." % file_name


    except Exception as ret:
        return "产生了异常：%s" % str(ret)

