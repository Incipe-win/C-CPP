import socket
import re
import threading


def service_client(new_socket):
    """为这个客户端返回数据"""
    
    # 1. 接收浏览器发送过来的请求，即http请求
    # GET / HTTP/1.1
    request = new_socket.recv(1024).decode("utf-8")
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
        # 2. 返回http格式的数据给浏览器
        # 2.1 准备发送给浏览器的数据---header
        response = "HTTP/1.1 200 OK\r\n"
        response += "\r\n"
        # 2.2 准备发送给浏览器的数据---body
        # 发header
        new_socket.send(response.encode("utf-8"))
        # 发body
        new_socket.send(content)

    new_socket.close()


def main():
    """用来完成整体的控制"""
    # 1. 创建套接字 
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    # 2. 绑定
    tcp_socket.bind(("", 6789))

    # 3. 变为监听套接字
    tcp_socket.listen(128)

    while True:
        # 4. 等待新客户端到来
        new_socket, client_addr = tcp_socket.accept()
        # 5. 为这个客户端服务
        p = threading.Thread(target = service_client, args = (new_socket, ))
        p.start()

    tcp_socket.close()


if __name__ == "__main__": 
    main()
