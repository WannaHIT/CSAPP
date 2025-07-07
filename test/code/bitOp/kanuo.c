// 卡诺图
// PASS, WRONG
// Sum of Product
// 乘项之和: 对bool真值表简化的结果
#include<stdio.h>
#include<stdlib.h>

#define RESET "\33[0m"
#define RED "\33[31m"
#define GREEN  "\33[32m"

long hexAllLetters(long x)
{
	long y = x | (x >> 1); // y[1] = x[1] | x[2]
	
	y = y & (y >> 32);
	y = y & (y >> 16);
	y = y & (y >> 8);
	y = y & (y >> 4);


	x = x & (x >> 32);
	x = x & (x >> 16);
	x = x & (x >> 8);
	x = x & (x >> 4);

	return (y >> 1) & ( x >> 3) & 1;
}

int main(int argc, char *argv[])
{
	long num = strtol(argv[1], NULL, 16);
	long flag = hexAllLetters(num);
	if (flag)
		printf(GREEN "result = %ld\n" RESET, flag);
	else
		printf(RED "result = %ld\n" RESET, flag);
	return 0; 
}
