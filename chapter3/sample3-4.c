/*************************************************************************
	> File Name: sample3-1.c
	> Author: Manson
	> Mail: manson.li3307@gmail.com 
	> Created Time: 2013年07月17日 星期三 18时36分29秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(int argc, char *argv[]) {
	int val;
	if (argc != 2) {
		printf("usage\n");
		return -1;
	}

	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
		printf("fcntl error %d \n", atoi(argv[1]));
	}

	printf("fcntl get %d flag is 0x%x\n", atoi(argv[1]), val);

	return 0;
}
