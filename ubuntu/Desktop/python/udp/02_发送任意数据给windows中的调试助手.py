import socket

def main():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    send_data = input("请输入发送的数据:")
    # udp_socket.sendto(b"hahahha", ("192.168.1.101", 8080))
    
    udp_socket.sendto(send_data.encode("utf-8"), ("192.168.1.101", 8080))

    udp_socket.close()


if __name__ == "__main__":
    main()
