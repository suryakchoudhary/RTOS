#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<linux/in.h>

int cfd;
int sfd;

struct sockaddr_in caddr;
struct sockaddr_in saddr;

int len;
unsigned char buff[1024];

int main()
{
	cfd = socket(AF_INET, SOCK_STREAM, 0);

	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("192.168.1.12");
	saddr.sin_port = htons(5678);

	connect(cfd, (struct sockaddr *)&saddr, sizeof(struct sockaddr_in));
	read(cfd, buff, sizeof(buff));
	printf("FROM SERVER: %s\n", buff);
	write(cfd, "FROM CLIENT_s\n", sizeof("FROM CLIENT\n"));

	close(cfd);
	return 0;
}
