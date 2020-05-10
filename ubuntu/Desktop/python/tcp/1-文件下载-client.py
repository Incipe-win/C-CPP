import socket

def main():
    # 1.创建套接字
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # 2.获取服务器的ip，port
    server_ip = input("请输入服务器的ip: ")
    server_port = int(input("请输入服务器的port: "))
    server_addr = (server_ip, server_port)

    # 3.链接服务器
    tcp_socket.connect(server_addr)

    # 4.获取下载的文件名字
    file_name = input("请输入文件名字: ")

    # 5.将文件的名字发送服务器
    tcp_socket.send(file_name.encode("utf-8"))

    # 6.接收文件中的数据
    recv_data = tcp_socket.recv(1024 * 1024)
    
    # 7.保存接收到的数据到一个文件中
    if recv_data: 
        with open(file_name, "wb") as f:
            f.write(recv_data)
    # 8.关闭套接字
    tcp_socket.close()


if __name__ == "__main__":
    main()
