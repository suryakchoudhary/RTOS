#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<linux/in.h>

int sfd;
int cfd;

struct sockaddr_in saddr;
struct sockaddr_in caddr;

int len;
unsigned char buff[1024];

int main()
{
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("192.168.1.12");
	saddr.sin_port = htons(5678);

	bind(sfd, (struct sockaddr *)&saddr, sizeof(struct sockaddr_in));
	listen(sfd, 10);

	len = (sizeof(struct sockaddr_in));
	cfd = accept(sfd, (struct sockaddr *)&caddr, &len);

	write(cfd, "FROM SERVER\n", sizeof("FROM SERVER\n"));
	read(cfd, buff, sizeof(buff));
	printf("FROM CLIENT: %s\n", buff);

	close(sfd);
	close(cfd);

	return 0;
} 
