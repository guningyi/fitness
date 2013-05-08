#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <signal.h>
#include <stdlib.h>


void daemonize(const char *cmd)
{
	int i, fd0, fd1, fd2;
	pid_t pid;
	struct rlimit rl;
	struct sigaction sa;
    /*clear file creation mask*/
    umask(0);

    if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
    {
    	printf("can't get file description limit!%s\n");
    	exit(0);
    }


    if ((pid =fork()) < 0 )
    {
    	printf("can't fork!%s\n");
    	exit(0);
    }
    else if(pid != 0)
    {
    	exit(0);
    }

    setsid();

    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGHUP, &sa, NULL) <0)
    {
    	printf("can't ignore SIGHUP%s\n");
    	exit(0);
    }
//#if 0
    
    if((pid=fork()) < 0)
    {
        printf("can't fork!%s\n");
    	exit(0);
    }
    else if(pid != 0)
    {
    	exit(0);
    }
//#endif

    if(chdir("/") <0)
    {
    	printf("can't change the dir!%s\n");
    	exit(0);
    }	

    if(rl.rlim_max == RLIM_INFINITY)
    {
        rl.rlim_max = 1024;
    }

    for (i = 0; i < rl.rlim_max; i++)
    {
    	close(i);
    }

    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    openlog(cmd, LOG_CONS, LOG_DAEMON);

    if (fd0 != 0 || fd1 != 1 || fd2 != 2)
    {
    	syslog(LOG_ERR, "unexpected file descriptiors %d %d %d", fd0, fd1, fd2);
    	exit(0);
    }

    for(;;)
    {
        syslog(LOG_INFO, "I am daemonize!");
        sleep(5);
    }


} 


int main(int argc, char *argv[])
{
	char* ptr = "aaa";
	daemonize(ptr);
	return 0;
}