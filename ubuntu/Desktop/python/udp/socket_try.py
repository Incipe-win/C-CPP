import socket

def main():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    udp_socket.sendto(b"hahahha", ("192.168.1.101", 8080))

    udp_socket.close()


if __name__ == "__main__":
    main()
