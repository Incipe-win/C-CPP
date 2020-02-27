import socket


def main():
    # 创建套接字
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    udp_socket.sendto(b"handsome", ("192.168.1.101", 8080))
    # 关闭套接字
    udp_socket.close()


if __name__ == "__main__":
    main()
