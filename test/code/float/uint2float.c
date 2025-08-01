#include<stdio.h>
// #include<string.h>
// 这个程序是理解IEEE-754浮点表示的一个练习，
// 它展示了如何将整数转换为对应的浮点数位表示
#include<stdint.h>
// #include<stdlib.h>

uint32_t uint2float(uint32_t u)
{
	int n = 0;
	// 32 zeros
	if(u ==0) return 0;

	uint32_t s = u & 0x80000000;
	u = u & 0x7fffffff;

	// must exists highest 1, find it ...
	for(int i=0; i<32; ++i)
	{
		if((u >> i) == 0x1)
		{
			n = i; 
			break;
		}
	}

	printf("n = %d\n", n);
	// 00001
	
	if(n <= 23)
	{
		// no near, 没有舍入
		uint32_t f;
		uint32_t e;

		s = (u >> 31) & 0x1;
		f = u & (0xffffffff >> (32+1 - n));
		e = n + 127;

		return s & (e << 23) & f;
	}
	else{

	}
	return 0;
}

int main(void)
{
	uint32_t u = 0x0008000;
	uint2float(u);

	return 0;
}
