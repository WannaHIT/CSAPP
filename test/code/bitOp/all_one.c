// 检查一个long型的二进制是否全1
// strtol读取大数会导致溢出, 需要小心
// strtoul (String to Unsigned Long)
#include<stdio.h>
#include<stdlib.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int all_one(unsigned long x)
{
	printf("x = %lx\n", x);
	x = x & (x >> 32);
	x = x & (x >> 16);
	x = x & (x >>  8);
	x = x & (x >>  4);
	x = x & (x >>  2);
	x = x & (x >>  1);
	printf("x = %lx\n", x);
	return x & 1;
}

int main(int argc, char* argv[])
{
	unsigned long x = strtoul(argv[1], NULL, 16);
	
	// printf("%d\n", all_one(x));
	x = all_one(x);
	if(x == 1)
		printf(GREEN "Yes, It's all one.\n" RESET);
	else
		printf(RED "No\n" RESET);
	return 0;
}
