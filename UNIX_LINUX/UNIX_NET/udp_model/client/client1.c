#include "../include/unp.h"


void
dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    int n;
    char sendline[MAXLINE], recvline[MAXLINE+1];
    socklen_t len;
   // struct sockaddr *preply_addr;
   // preply_addr = Malloc(servlen);
  
    Connect(sockfd, (SA*)pservaddr, servlen);  //We use the connect in udp  
  
    while(Fgets(sendline, MAXLINE, fp) != NULL){
        //if we use connect , then we can use the write to replace the sendto
        Write(sockfd, sendline, strlen(sendline)); //use strlen(sendline) but not MAXLINE means we just transfer the real data.
        Read(sockfd, recvline, MAXLINE); //why the length is MAXLINE here? not the strlen(recvline)?
        recvline[n] = 0;
        Fputs(recvline, stdout);
    }
}

int 
main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
    if (argc != 2)
        err_quit("usage: udpcli <IPaddress>");
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    //servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_port = htons(7);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
    dg_cli(stdin, sockfd, (SA*)&servaddr, sizeof(servaddr));
    
    exit(0);
}
