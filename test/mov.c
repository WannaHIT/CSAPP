#include<stdio.h>
#include<string.h> 
// mov $0x5561dca8, %rdi 
// # 我知道为什么用这个，因为字符串首地址就是指针
// mov ($0x5561dca8), %rdi 
// # 假设 s 指向 "hello\n" 的字符串，那么 (%rax) 实际指向字符串中的第一个字符 'h'

void outstring(char *s)
{
	// printf("%s\n", s);
	printf("%s", s);
}
int main(void)
{
	// s 存储的是 "hello\n" 这段字符串在内存中的地址
	// 	mov %rax, %rdi 的作用是将字符串地址传递给 outstring，而不是读取字符串的内容
	char *s = "hello\n";
	outstring(s);

	return 0;
}
