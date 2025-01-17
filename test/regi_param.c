#include<stdio.h>
// 直接在gdb里面查看汇编就可以看到在call之前准备了所有的参数
// 能看到所有的寄存器
// 试试多出来的存在栈的哪里？
int foo(int a, int b, int c, int d, int e, int f,int g, int h)
{
	return a + b + c + d + e + f + g + h;
}

int main(void)
{
	int sum;
	sum = foo(1, 2, 3, 4, 5, 6, 7, 8);
	printf("%d\n", sum);
	return 0;
}
