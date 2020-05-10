#include "utility.h"

#define error(msg) \
    do {perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[]) {
    /**
     * TCP服务端通信
     * 1：使用 socket()创建 TCP 套接字（socket）
     * 2：将创建的套接字绑定到一个本地地址和端口上（bind）
     * 3：将套接字设为监听模式，准备接收客户端请求（listen）
     * 4：等待客户请求到来: 当请求到来后，接受连接请求，返回一个对应于此次连接的新的套接字（accept）
     * 5：用 accept 返回的套接字和客户端进行通信（使用write()/send()或send()/recv())
     * 6：返回，等待另一个客户请求
     * 7：关闭套接字
     */

    /**
     * 1:创建套接字socket
     * param1:指定地址族为IPv4;param2:指定传输协议为流式套接字;param3:指定传输协议为TCP,可设为0,由系统推导
     */
    int listener = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listener < 0) {
        error("socket error");
    }
    printf("listen socket created \n");

    //地址复用
    int on = 1;
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        error("setsockopt");
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = PF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    //绑定地址
    if (bind(listener, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {
        error("bind error");
    }

    //监听
    if (listen(listener, SOMAXCONN) < 0) {
        error("listen error");
    }

    printf("Start to listen: %s\n", SERVER_IP);

    //在内核中创建事件表
    int epfd = epoll_create(EPOLL_SIZE);
    if (epfd < 0) {
        error("epfd error");
    }
    printf("epoll created, epollfd = %d\n", epfd);
    static struct epoll_event events[EPOLL_SIZE];
    //往内核事件表里添加事件
    addfd(epfd, listener, true);

    //主循环
    while (1) {
        //epoll_events_count表示就绪事件的数目
        int epoll_events_count = epoll_wait(epfd, events, EPOLL_SIZE, -1);
        if (epoll_events_count < 0) {
            perror("epoll failure");
            break;
        }

        printf("epoll_events_count = %d\n", epoll_events_count);
        //处理这epoll_events_count个就绪事件
        for (int i = 0; i < epoll_events_count; ++i) {
            int sockfd = events[i].data.fd;
            //新用户连接
            if (sockfd == listener) {
                struct sockaddr_in client_address;
                socklen_t client_addrLength = sizeof(struct sockaddr_in);
                int clientfd = accept(listener, (struct sockaddr *) &client_address, &client_addrLength);

                printf("client connection from: %s : % d(IP : port), clientfd = %d \n",
                       inet_ntoa(client_address.sin_addr),
                       ntohs(client_address.sin_port),
                       clientfd);

                addfd(epfd, clientfd, true);

                // 服务端用list保存用户连接
                clients_list.push_back(clientfd);
                printf("Add new clientfd = %d to epoll\n", clientfd);
                printf("Now there are %d clients int the chat room\n", (int) clients_list.size());

                // 服务端发送欢迎信息
                printf("welcome message\n");
                char message[BUF_SIZE];
                bzero(message, BUF_SIZE);
                sprintf(message, SERVER_WELCOME, clientfd);
                int ret = send(clientfd, message, BUF_SIZE, 0);
                if (ret < 0) {
                    error("send error");
                }
            } else {           //处理用户发来的消息，并广播，使其他用户收到信息
                int ret = sendBroadcastmessage(sockfd);
                if (ret < 0) {
                    error("error");
                }
            }
        }
    }
    close(listener); //关闭socket
    close(epfd);    //关闭内核
    return 0;
}
