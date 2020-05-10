import socket


def send_msg(udp_socket, dest_ip, dest_port):
    """发送消息"""
    # 发送 
    send_data = input("请输入要发送的消息: ")
    if send_data == "exit":
        return False
    udp_socket.sendto(send_data.encode("utf-8"), (dest_ip, dest_port))


def recv_msg(udp_socket):
    """接收数据"""
    # 接收并显示
    recv_data = udp_socket.recvfrom(1024)
    print("%s:%s" % (str(recv_data[1]) , recv_data[0].decode("utf-8")))


def main():
    # 创建套接字
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.bind(("", 1236))

    dest_ip = input("请输入要发送的ip: ")
    dest_port = int(input("请输入要发送的port: "))
    # 循环处理来进行处理事件
    while True:
        if send_msg(udp_socket, dest_ip, dest_port) == False:
            break

        recv_msg(udp_socket)


if __name__ == "__main__":
    main()
