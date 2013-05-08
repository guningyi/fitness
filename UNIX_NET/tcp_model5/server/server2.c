#include "../include/unp.h"

void
str_echo(int sockfd)
{
    ssize_t n;
    char buf[MAXLINE];
    again:
    while((n=read(sockfd, buf, MAXLINE)) > 0)
    {
        Writen(sockfd, buf, n);
    }
    if ((n < 0) && (errno == EINTR) )
    {
        goto again;
    }
    else if ( n<0 )
    {
        err_sys("str_echo: read error");
    }
}


int 
main(int argc, char **argv)
{
    int i, maxi, maxfd, listenfd, connfd, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n;
    char buf[MAXLINE];
    socklen_t clilen;
    fd_set rset, allset;
    struct sockaddr_in cliaddr, servaddr;
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    
    Bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    Listen(listenfd, LISTENQ);
    maxfd = listenfd;
    maxi = -1;
    for(i=0; i < FD_SETSIZE; i++){
        client[i] = -1;
    }

    FD_ZERO(&allset);
    FD_SET(listenfd, &allset);
    
    for ( ; ; ){
        rset = allset;
        nready = Select(maxfd+1, &rset, NULL, NULL, NULL);
        if (FD_ISSET(listenfd,  &rset)){
            clilen = sizeof(cliaddr);
            connfd = Accept(listenfd, (SA*)&cliaddr, &clilen);
            for(i = 0; i < FD_SETSIZE; i++){
               if(client[i] < 0){
                   client[i] = connfd;
               } 
               break;
            }
            if (i == FD_SETSIZE){
                err_quit("too many clients");
            }
            FD_SET(connfd, &allset);//add new descriptor to set
            if (connfd > maxfd){
                maxfd = connfd;
            }
            if (i > maxi){
                maxi = i;
            }
            if (--nready <= 0){// no more readable descriptors. 
                continue;
            }
        }
        for (i=0; i<=maxi; i++){// check all clients for data
            if ((sockfd = client[i]) < 0){
                continue;
            }
            if (FD_ISSET(sockfd, &rset)){
                if ( (n=Read(sockfd, buf, MAXLINE)) == 0){
                    Close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                }
                else
                    Writen(sockfd, buf, n);
                if (--nready <= 0){// no more readable descriptors
                    break;
                }
            }
        }
    }
}
