// 寻找一个无符号数最高有效位的1
// 0xe ==> 0x8
// 将 x 中最高位的那个 1，像推倒多米诺骨牌一样，
// 向右“涂抹”或“复制”，把它右边的所有位都填上 1
// 如果输入是 01011100，经过这一步，我们希望得到 01111111
#include<stdio.h>
#include <stdlib.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

unsigned high_bit(unsigned x)
{
	x = x | (x >> 1);	
	x = x | (x >> 2);	
	x = x | (x >> 4);	
	x = x | (x >> 8);	
	x = x | (x >> 16);	
	return x + (~((x>>1))+1);
}

int main(int argc, char *argv[])
{
	// printf("result = 0x%x\n", high_bit(0xe));
	// printf("result = 0x%x\n", high_bit(0x90));
	// printf("result = 0x%x\n", high_bit(0xf));
	// printf("result = 0x%x\n", high_bit(0xa0000000));
	// printf("result = 0x%x\n", high_bit(0xffffffff));

	unsigned int x = strtoul(argv[1], NULL, 16);
	unsigned int y = high_bit(x);

	printf("0x%x\n", y);

	return 0;
}
