#include<sys/param.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

int port = 8000;

void init_daemon(void);

int main(int argc,char* argv[])
{
	int sockfd,tsockfd;
	int addr_size;
	char buf[100];
	struct sockaddr_in s;
	struct sockaddr_in p;
	char temp_buf[256];

	init_daemon();
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(-1 == sockfd){
		perror("socket building failure");
		exit(1);
	}

	bzero(&s,sizeof(s));
	s.sin_family = AF_INET;
	s.sin_addr.s_addr = INADDR_ANY;
	s.sin_port = htons(port);

	bzero(&p,sizeof(p));
	s.sin_family = AF_INET;
	s.sin_addr.s_addr = INADDR_ANY;
	s.sin_port = htons(port);
	addr_size = sizeof(p);

	if(-1 == bind(sockfd,(struct sockaddr*) &s,sizeof(s))){
		perror("bind");
		exit(1);
	}
	if(-1 == listen(sockfd,10)){
		perror("listent");
		exit(1);
	}

	for(;;){
		tsockfd = accept(sockfd,(struct sockaddr*) &p,&addr_size);
		if(tsockfd <0){
			printf("ft: %d \n",errno);
			perror("accept");
			exit(1);
		}
		if(recv(tsockfd,buf,100,0) < 0){
			perror("recv");
			exit(1);
		}
		strcpy(temp_buf,"Here is the first file of the president's office.");
		if(send(tsockfd,temp_buf,strlen(temp_buf),0) <0){
			perror("send");
			exit(1);
		}
		close(tsockfd);
		printf("send: %s",temp_buf);
	}

	return 0;

}


void init_daemon(void)
{
	pid_t pid;
	int i;
	if(-1 == (pid = fork())){
		exit(1);
	}
	if(pid > 0)
		exit(0);
	setsid();
	for(i=0;i<NOFILE;++i)
		close(i);
	chdir("/rundir");
	umask(0);
	return;
}

