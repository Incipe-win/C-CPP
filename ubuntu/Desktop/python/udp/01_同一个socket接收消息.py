import socket

def main():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    udp_socket.bind(("", 7791))

    # 请输入对方ip,port
    dest_ip = input("请输入对方ip:")
    dest_port = input("请输入对方端口:")
    
    while True:
        send_data = input("请输入发送的数据:")

        # exit退出
        if send_data == "exit":
            break
        # udp_socket.sendto(b"hahahha", ("192.168.1.101", 8080))
        
        udp_socket.sendto(send_data.encode("utf-8"), (dest_ip, int(dest_port)))
        
        recv_data = udp_socket.recvfrom(1024)
        print("%s：%s" % (recv_data[0].decode("utf-8"), str(recv_data[1])))
    udp_socket.close()


if __name__ == "__main__":
    main()
