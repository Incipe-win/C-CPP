import socket

def main():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    udp_socket.bind(("", 7890))

    while True:
        send_data = input("请输入发送的数据:")

        # exit退出
        if send_data == "exit":
            break
        # udp_socket.sendto(b"hahahha", ("192.168.1.101", 8080))
        
        udp_socket.sendto(send_data.encode("utf-8"), ("192.168.206.135", 7788))

    udp_socket.close()


if __name__ == "__main__":
    main()
