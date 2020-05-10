import socket
import time

tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
tcp_socket.bind(("", 7890))
tcp_socket.listen(128)
tcp_socket.setblocking(False) # 设置套接字非堵塞

client_socket_list = list()

while True:
    time.sleep(0.5)
    try:
        new_socket, new_addr = tcp_socket.accept()
    except Exception as ret:
        print(ret)
        print("---没有新的客户端到来---")
    else:
        print("---只要没有异常，那么也就意味着来了一个新的客户端---")
        new_socket.setblocking(False)
        client_socket_list.append(new_socket)

    for client_socket in client_socket_list:
        try:
            recv_data = client_socket.recv(1024)
        except Exception as ret:
            print(ret)
            print("---这个客户端没有发来数据---")
        else:
            if recv_data:
                print("---客户端发送过来了数据---")
                print(recv_data.decode("utf-8"))
            else:
                client_socket_list.remove(client_socket)
                client_socket.close()
                print("---客户端已经关闭---")
