/*************************************************************************
	> File Name: sample3-1.c
	> Author: Manson
	> Mail: manson.li3307@gmail.com 
	> Created Time: 2013年07月17日 星期三 18时36分29秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(void) {
	if (lseek(STDIN_FILENO, 0, SEEK_SET) == -1) {
		printf("Can't seek STDIN_FILENO\n");
	} else {
		printf("Can seek STDIN_FILENO\n");
	}
	return 0;
}
