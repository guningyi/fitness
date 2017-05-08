#include "../include/unp.h"

#define NDG 2000    //number 
#define DGLEN 1400   //length


void
dg_cli(FILE *fp, int sockfd, const SA *pservaddr, socklen_t servlen)
{
    int i;
    char sendline[DGLEN];
   
    for (i = 0; i < NDG; i++){
        Sendto(sockfd, sendline, DGLEN, 0, pservaddr, servlen);
    } 
 #if 0 
    while(Fgets(sendline, MAXLINE, fp) != NULL){
        Sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen );
        //n = Recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
        n = Recvfrom(sockfd, recvline, MAXLINE, 0, preply_addr, &len);
        if ((len != servlen) || (memcmp(pservaddr, preply_addr, len) != 0)){
            printf("reply from %s (ignored)\n", Sock_ntop(preply_addr, len));
            continue;
        }
        recvline[n] = 0;
        Fputs(recvline, stdout);
    }
#endif
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
    servaddr.sin_port = htons(SERV_PORT);
    //servaddr.sin_port = htons(7);
    Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);
    dg_cli(stdin, sockfd, (SA*)&servaddr, sizeof(servaddr));
    
    exit(0);
}
