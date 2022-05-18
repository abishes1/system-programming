//Program to implement fifo
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#define MAX 256
using namespace std;
int main(){
	char fifoname[] = "fifotest";
	int fifofd,ret;
	char readbuff[MAX], writebuff[MAX];
	mkfifo(fifoname,0666);
	while(1){
		fifofd = open(fifoname,0_RDONLY);
		write(1,"Enter your Message: ",20);
		ret = read(0,writebuff,MAX);
		write(1,readbuff,ret);
		close(fifofd);

		fifofd = open(fifoname,0_WRONLY);
		write(1,"Enter your Message: ",20);
		ret = read(0,writebuff,MAX)
		write(1,readbuff,ret);
		close(fifofd);

