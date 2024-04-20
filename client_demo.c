#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>



int main(){
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);	

	struct sockaddr_in server_info;
	server_info.sin_family = AF_INET;
	server_info.sin_port = htons(9999);
	server_info.sin_addr.s_addr = inet_addr("127.0.0.1");
	int size = sizeof(server_info);

	if(connect(sockfd, (struct sockaddr *)&server_info, size) == -1){
		perror("connect fail");
		exit(1);
	}


	while(1){

	}	

	return 0;
}
