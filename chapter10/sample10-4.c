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
static int sig_alarm(int);

int main(void) {
	if (signal(SIGALRM, sig_alarm) == SIG_ERR) {
		printf("can't catch SIGALRM");
		return -1;
	}
	alarm(3);
	pause();
	printf("pause trigger\n");
	return 0;
}

int sig_alarm(int signo) {
	printf("receive signal alarm %d\n", SIGUSR1);
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
