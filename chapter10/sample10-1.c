/*************************************************************************
	> File Name: sample10-1.c
	> Author: Manson
	> Mail: manson.li3307@gmail.com 
	> Created Time: 2013年07月19日 星期五 10时28分59秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

static int sig_usr(int);

int main(void) {
	if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
		printf("can't catch SIGUSR1");
	}
	if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
		printf("can't catch SIGUSR2");
	}
	while(1) {
		pause();
	}
}

int sig_usr(int signo) {
	if (signo == SIGUSR1) {
		printf("receive SIGUSR1 %d\n", SIGUSR1);
	} else if (signo == SIGUSR2) {
		printf("receive SIGUSR2 %d\n", SIGUSR2);
	} else {
		printf("receive unknow %d\n", signo);
	}
}
