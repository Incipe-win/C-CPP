from pymysql import *


class JD(object):
    def __init__(self):
        self.conn = connect(host='localhost', port=3306, database='jing_dong', user='root', password='www.12345.com', charset='utf8')
        self.cursor = self.conn.cursor()

    def __del__(self):
        self.cursor.close()
        self.conn.close()

    def execute_sql(self, sql):
        self.cursor.execute(sql)
        for temp in self.cursor.fetchall():
            print(temp)

    def show_all_items(self):
        """显示所有的商品"""
        sql = "select * from goods;"
        self.execute_sql(sql)

    def show_cates(self):
        sql = "select name from goods_cates;" 
        self.execute_sql(sql)

    def show_brands(self):
        sql = "select name from goods_brands;" 
        self.execute_sql(sql)

    def add_brands(self):
        item_name = input("请输入新商品的名称: ")
        sql = """insert into goods_brands (name) values("%s");""" % item_name
        self.cursor.execute(sql)
        self.conn.commit()

    def get_info_by_name(self):
        item_name = input("请输入商品名字: ")
        # sql = """select * from goods where name = "%s";""" % item_name
        # print("--------->%s<---------" % sql)
        # self.execute_sql(sql)
        sql = "select * from goods where name = %s"
        self.cursor.execute(sql, [item_name])
        print(self.cursor.fetchall())

    @staticmethod
    def print_menu():
        print("-----JD-----")
        print("1. 所有的商品")
        print("2. 所有的商品分类")
        print("3. 所有的商品品牌分类")
        print("4. 添加一个商品分类")
        print("5. 根据名字查询一个商品")
        return input("请输入功能对应的序号: ") 

    def run(self):
        while True:
            num = self.print_menu()

            if num == "1":
                # 查询所有商品
                self.show_all_items()
            elif num == "2":
                # 查询分类
                self.show_cates()
            elif num == "3":
                # 查询品牌分类
                self.show_brands()
            elif num == "4":
                # 添加一个商品分类
                self.add_brands()
            elif num == "5":
                # 根据名字查询一个商品
                self.get_info_by_name()
            else:
                print("请重新输入")


def main():
    # 1. 创建一个京东商城对象
    jd = JD()

    # 2. 调用这个对象的run方法,让其运行
    jd.run()


if __name__ == "__main__":
    main()
