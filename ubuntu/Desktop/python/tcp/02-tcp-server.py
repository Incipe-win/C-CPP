import socket


def main():
    # 1.买个手机(创建套接字)
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 2.插入手机卡(绑定本地链接)
    tcp_socket.bind(("", 4567))

    # 3.将手机设置为响铃模式(让默认的套接字由主动变为被动)
    tcp_socket.listen(128) 
    while True:
        # 4.等待别人的电话到来(等待客户端链接)
        client_socket, client_addr = tcp_socket.accept()
        print(client_addr)

        while True:
            # 5.接收客户端发送过来的请求
            recv_data = client_socket.recv(1024)
            print(recv_data.decode("utf-8"))
            if recv_data:
                client_socket.send("you are handsome".encode("utf-8"))
            else:
                break
        
        client_socket.close()
    # 6.关闭套接字
    tcp_socket.close()

if __name__ == "__main__":
    main()
