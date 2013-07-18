/*************************************************************************
	> File Name: test_symlink.c
	> Author: Manson
	> Mail: manson.li3307@gmail.com 
	> Created Time: 2013年07月18日 星期四 16时04分47秒
	> test function syslink and readlink
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv) {
	int result = -1;
	//You should make a new file named 'origin' first
	result = symlink("origin", "link");
	printf("syslink result %d\n", result);

	char buf[128];
	readlink("link", buf, 128);
	printf("syslink read %s\n", buf);
	return 0;
}
