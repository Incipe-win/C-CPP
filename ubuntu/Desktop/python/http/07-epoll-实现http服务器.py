import socket
import select
import re


def service_client(new_socket, recv_date):
    """为这个客户端返回数据"""

    # 1. 接收浏览器发送过来的请求，即http请求
    # GET / HTTP/1.1
    request = recv_date.decode("utf-8") 
    # print(request)
    request_lines = request.splitlines()
    print("")
    print(">>>" * 10)
    print(request_lines)

    file_name = ""
    ret = re.match(r"[^/]+(/[^ ]*)", request_lines[0]) 
    if ret:
        file_name = ret.group(1)
        # print("*" * 10 + file_name)
        if file_name == "/":
            file_name = "/index.html"

    try:
        file = open("./html" + file_name, "rb")
    except:
        response = "HTTP/1.1 404 NOT FOUND\r\n"
        response += "\r\n"
        response += "NOT FOUND!"
        new_socket.send(response.encode("utf-8"))
    else:
        content = file.read()
        file.close()

        response_body = content 

        response_head = "HTTP/1.1 200 OK\r\n"
        response_head += "Content-Length:%d\r\n" % len(response_body)
        response_head += "\r\n"
        response = response_head.encode("utf-8") + response_body

        # 2. 返回http格式的数据给浏览器
        # 2.1 准备发送给浏览器的数据---header
        # 2.2 准备发送给浏览器的数据---body
        new_socket.send(response)

    # new_socket.close()


def main():
    """用来完成整体的控制"""
    # 1. 创建套接字 
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    tcp_socket.setblocking(False)  # 将套接字设置为非阻塞

    # 2. 绑定
    tcp_socket.bind(("", 6789))

    # 3. 变为监听套接字
    tcp_socket.listen(128)

    # 创建一个epoll对象
    epl = select.epoll()

    # 将监听套接字对应的fd注册到对应的epoll中
    epl.register(tcp_socket.fileno(), select.EPOLLIN)

    fd_event_dict = dict()

    while True:
        fd_event_list = epl.poll()  # 默认会堵塞，直到操作系统监测到数据到来，通过事件通知方式，告诉这个程序，解堵塞
        
        # [(fd, event), (套接字对应的文件描述符, 这个描述符到底是什么事件　例如　可以调用recv等)]
        for fd, event in fd_event_list:
            # 4. 等待新客户端到来
            if fd == tcp_socket.fileno():
                new_socket, client_addr = tcp_socket.accept()
                epl.register(new_socket.fileno(), select.EPOLLIN)
                fd_event_dict[new_socket.fileno()] = new_socket
            elif event == select.EPOLLIN:
                # 判断已经链接的客户端是否有数据
                recv_data = fd_event_dict[fd].recv(1024)
                if recv_data:
                    service_client(fd_event_dict[fd], recv_data)
                else:
                    fd_event_dict[fd].close()
                    epl.unregister(fd)
                    del fd_event_dict[fd]

    tcp_socket.close()


if __name__ == "__main__": 
    main()
