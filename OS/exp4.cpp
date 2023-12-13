#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t cpid;
	if(fork()==0)
	exit(0);
	else
	cpid =wait(NULL);
	printf("parent pid=%d\n",getpid());
	printf("child pid=%d\n",cpid);
	return 0;
}