#include<stdio.h>
#include<stdlib.h>

unsigned LowBit(unsigned x)
{
	unsigned a = 0;
	// a = 1000
	// a = x & (-x);
	a = x & ((~x) + 1);
	return a;
}

int main(void)
{
	int a = 2147483647;
	int b = 1;
	
	printf("%d\n", LowBit(3));
	
	// printf("%d\n", (~a)+1);
	// printf("%d\n", (a)+1);
	// printf("%d\n", ~a);

	return 0;
}
