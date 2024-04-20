#include "server.h"

Server::Server(){
	this->base = event_base_new();
}

Server::~Server(){

}

void Server::listen(const char *ip, const int port) {
	struct sockaddr_in svr_sock_addr;
	memset(&svr_sock_addr, 0, sizeof(svr_sock_addr));
	svr_sock_addr.sin_family = AF_INET;
	svr_sock_addr.sin_addr.s_addr = inet_addr(ip);
	svr_sock_addr.sin_port = htons(port);

	struct evconnlistener *listener = evconnlistener_new_bind(base, listener_cb, NULL, LEV_OPT_CLOSE_ON_FREE, 5, (struct sockaddr *)&svr_sock_addr, sizeof(svr_sock_addr));

	if (NULL == listener ) {
		std::cout << "evconnlistener_new_bind error" << std::endl;
		exit(1);
	}

	std::cout << "server started succ" << std::endl;

	// 监听集合
	event_base_dispatch(base);

	std::cout << "server listen succ" << std::endl;

	// 释放对象
	evconnlistener_free(listener);
	event_base_free(base);
}

void Server::listener_cb(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *sa, int socklen, void *arg) {
	struct sockaddr_in *client_info =(struct sockaddr_in *)sa;
	std::cout << "[connection]";
	std::cout << " client ip: " << inet_ntoa(client_info->sin_addr);
	std::cout << " port: " << client_info->sin_port << std::endl;

	// 创建事件，放入线程池
}
