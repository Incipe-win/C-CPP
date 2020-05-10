import socket

def send_msg_2_client(client_socket, client_addr):
    while True:
        # 5.接收客户端发送过来的请求
        file_name = client_socket.recv(1024).decode("utf-8")
        if file_name:
            print("客户端%s需要下载的文件是:[%s]" % (str(client_addr), file_name))
            file_content = None
            # 打开文件
            try:
                f = open(file_name, "rb")
                file_content = f.read()
                f.close()
            except Exception as ret:
                print("没有要下载的文件(%s)" % file_name)
            
            # 发送数据
            if file_content:
                client_socket.send(file_content)
        else:
            print("感谢您的使用!")
            return 


def main():
    # 1.买个手机(创建套接字)
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 2.插入手机卡(绑定本地链接)
    tcp_socket.bind(("", 1234))

    # 3.将手机设置为响铃模式(让默认的套接字由主动变为被动)
    tcp_socket.listen(128) 
    while True:
        # 4.等待别人的电话到来(等待客户端链接)
        client_socket, client_addr = tcp_socket.accept()
        send_msg_2_client(client_socket, client_addr)
        client_socket.close()
    # 6.关闭套接字
    tcp_socket.close()

if __name__ == "__main__":
    main()
