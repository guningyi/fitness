#include "../include/unp.h"


void 
str_cli(FILE *fp, int sockfd)
{
    int maxfdpl;
    fd_set rset;
    char sendline[MAXLINE], recvline[MAXLINE];
    FD_ZERO(&rset);
    for(; ;){
        FD_SET(fileno(fp), &rset);
        FD_SET(sockfd, &rset);
        maxfdpl = max(fileno(fp), sockfd) + 1;
        //Select watch the fp and sockfd.
        Select(maxfdpl, &rset, NULL, NULL, NULL);
        //test if the sockfd has the data receive
        if (FD_ISSET(sockfd, &rset)){
           if (Readline(sockfd, recvline, MAXLINE) == 0)
               err_quit("str_cli: server terminated prematurely");
           // put the receive data to standard output
           Fputs(recvline, stdout); 
        }
        //test if the fp has data to input
        //we define this fp is standard input, this means keyboard.
        if (FD_ISSET(fileno(fp), &rset)){
           // put the input data to sendbuffer
           if (Fgets(sendline, MAXLINE, fp) == NULL)
               return;
           //send the buffer data out by sockfd.
           Writen(sockfd, sendline, strlen(sendline));
        }
    }
}

int 
main(int argc , char **argv)
{
    int i, sockfd[5];
    struct sockaddr_in servaddr;
    if (argc != 2)
    {
        err_quit("Usage: tcpcli<IPaddress>");
    }
    for (i = 0; i < 5; i++ )
    {
        sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);
        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(SERV_PORT);
        Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
        Connect(sockfd[i], (SA*)&servaddr, sizeof(servaddr));
    } 
    str_cli(stdin, sockfd[0]);
    exit(0);
}





