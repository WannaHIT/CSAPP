#include<stdio.h>
#include<stdlib.h>

// 返回最低位的1
unsigned LowBit(unsigned x)
{
	unsigned a = 0;
	// x = 1100; // ret 100
	// a = x & (-x);
	a = x & ((~x) + 1);

	return a;
}

int main(void)
{
	int a = 2147483647;
	int b = 1;
	
	printf("0x%x\n", LowBit(0xe));
	
	// printf("%d\n", (~a)+1);
	// printf("%d\n", (a)+1);
	// printf("%d\n", ~a);

	return 0;
}
