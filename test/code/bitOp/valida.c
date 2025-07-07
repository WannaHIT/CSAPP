#include<stdio.h>
// 是否相等呢
// 其实也可以画出真值表得到答案
int equals(unsigned a, unsigned b)
{
	int x = (~(a&b)) == ((~a)|(~b));
	int y = (~(a|b)) == ((~a)&(~b));
	return x && y;
}

int main(void)
{
	printf("%d\n", equals(2,3));
	printf("%d\n", equals(0,3));
	return 0;
}
