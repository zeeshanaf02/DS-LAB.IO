#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[20])
{
	printf("PDI of ex1.c=%d\n",getpid());
	char *argv[]={"Hello","Nero","SIET","NULL"};
	execv("./ex.2",argc);
	printf("Back to ex1.c");
	return 0;
}