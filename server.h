#ifndef __server_h__
#define __server_h__


#include <event.h>
#include <event2/listener.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <iostream>

#define IP "127.0.0.1"
#define PORT 9999


class Server {
	private:
		struct event_base *base;

	public:
		Server();
		~Server();
		void listen(const char *, int);

		static void listener_cb(struct evconnlistener *, evutil_socket_t, struct sockaddr *, int, void *);

};

#endif
