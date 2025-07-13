#include <stdint.h>
#include<stdio.h>
#include<stdlib.h>
// 判断一个unsigned num是否从最高有效位开始都为1
// 0xfa ==> 0
// 0x7ff ==> 1

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

unsigned int allOne(unsigned x)
{
	unsigned a = x + 1;
	unsigned lowbit_a = a & ((~a) + 1);
	unsigned result = lowbit_a ^ a;
	// printf("result = %u\n", result); // for test 
	return !result;
}

int main(int argc, char *argv[])
{
	unsigned int x = strtoul(argv[1], NULL, 16);
	unsigned int y = allOne(x);
	if(x &&  y==1)
		printf(GREEN "Yes, all valid num is one\n" RESET);
	else
	 	printf(RED"No\n" RESET);
	return 0;
}
