#include<stdio.h>
#include<stdlib.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

unsigned lowbit(unsigned x)
{
	return x & ((~x) + 1);
}

// all letters then return 1, else 0
unsigned letter_0(unsigned x)
{
	unsigned flag = 1;
	if (x==0) return !flag;
	while(x>0 && flag)
	{
		flag = !((x & 0xa)^(0xa)) | !((x & 0xc)^(0xc)); 
		x = x >> 4;
	}
	return flag;
}

unsigned all_one(unsigned x)
{
	unsigned a = x+1;
	unsigned lowbit = a & ((~a) + 1);
	a = a ^ lowbit;
	return !a;
}
unsigned letter(unsigned x)
{
	// no loop version
	// x3 x2 x1 x0
	unsigned x1 = x & 0x22222222;
	unsigned x2 = x & 0x44444444;
	unsigned x3 = x & 0x88888888;
	unsigned a;
	// x3 * (x1 + x2) <==> x3 & (x1 | x2)
	a = (x3>>3) & ((x1>>1) | (x2>>2));
	// a的值里面全是1才对, (但是个数不一定是8, 而是本身长度)
	printf("a = 0x%x\n", a);
	return !(a^0x11111111); 
}

int main(int argc, char *argv[])
{
	unsigned num = strtol(argv[1], NULL, 16);
	unsigned flag = letter_0(num);
	flag = letter(num);
	if(flag)
		printf(GREEN "result : %u\n" RESET, flag);
	else
		printf(RED "result : %u\n" RESET, flag);

	printf("0x%x is %u\n", 0x7, all_one(0x7));
	printf("0x%x is %u\n", 0x255, all_one(0x255));
	printf("0x%x is %u\n", 0xff, all_one(0xff));
	printf("0x%x is %u\n", 0xc, all_one(0xc));
	return 0;
}
