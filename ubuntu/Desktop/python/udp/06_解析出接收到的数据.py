import socket

def main():
    # 1. 创建套接字
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # 2. 绑定一个本地信息
    localaddr = ("", 7788)
    udp_socket.bind(localaddr)
    # 3. 接收数据
    recv_data = udp_socket.recvfrom(1024)
    # 4. 打印接收到的数据
    recv_msg = recv_data[0]
    send_add = recv_data[1]
    pirnt("%s：%s" % (str(send_add), recv_msg.decode("utf-8")))
    # 5. 关闭套接字
    udp_socket.close()

if __name__ == "__main__":
    main()


