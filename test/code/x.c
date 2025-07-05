#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a = 2147483647;
	int b = 1;

	
	printf("%d\n", (~a)+1);
	printf("%d\n", (a)+1);
	printf("%d\n", ~a);

	return 0;
}
