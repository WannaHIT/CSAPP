#include<stdio.h>
#include<stdlib.h>
// 判断一个unsigned num是否从最高有效位开始都为1
// 0xfa ==> 0
// 0x7ff ==> 1

unsigned int allOne(unsigned x)
{
	unsigned a = x + 1;
	unsigned b = ~a;
	unsigned lowbit = a & ((~a) + 1);
	unsigned result = lowbit ^ a;
	printf("result = %u\n", result);
	return !result;
}

int main(int argc, char *argv[])
{
	unsigned int x = strtoul(argv[1], NULL, 16);
	printf("%u\n", allOne(x));
	return 0;
}
