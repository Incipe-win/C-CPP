import socket
import mini_frame
import re
import multiprocessing
import time


class WSGIServer(object):
    def __init__(self):
        # 1. 创建套接字 
        self.tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        # 2. 绑定
        self.tcp_socket.bind(("", 6789))

        # 3. 变为监听套接字
        self.tcp_socket.listen(128)

    def service_client(self, new_socket):
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

        # 如果不是以.py结尾的就是静态资源，列入html
        if not file_name.endswith(".py"):
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

        # 如果是.py结尾的, 就是动态资源
        else:

            env = dict()
            body = mini_frame.application(env, self.set_response_header)
            
            header = "HTTP/1.1 %s\r\n" % self.status
            for temp in self.headers:
                header += "%s:%s\r\n" % (temp[0], temp[1])

            header += "\r\n"

            response = header + body

            # 发送response给浏览器
            new_socket.send(response.encode("utf-8"))

        new_socket.close()


    def set_response_header(self, status, headers):
        self.status = status
        self.headers = [("server", "mini_frame V8.8")]
        self.headers += headers

    def run_forever(self):
        """用来完成整体的控制"""

        while True:
            # 4. 等待新客户端到来
            new_socket, client_addr = self.tcp_socket.accept()
            # 5. 为这个客户端服务
            p = multiprocessing.Process(target = self.service_client, args = (new_socket, ))
            p.start()
            new_socket.close()

        self.tcp_socket.close()


def main():
    """控制整体, 创建一个web服务器对象, 然后调用这个对象的run_forever方法运行"""
    wsgi_server = WSGIServer()
    wsgi_server.run_forever()


if __name__ == "__main__": 
    main()
