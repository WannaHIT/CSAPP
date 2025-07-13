// 计算整数中1的个数
#include <stdio.h>
#include <stdlib.h>
unsigned int count_one(unsigned int x)
{
    // x = (x & 0x55555555) | ((x>>1) & 0x55555555);
    // x = (x & 0x33333333) | ((x>>2) & 0x33333333);
    // x = (x & 0x0f0f0f0f) | ((x>>4) & 0x0f0f0f0f);
    // x = (x & 0x00ff00ff) | ((x>>8) & 0x00ff00ff);
    // x = (x & 0x0000ffff) | ((x>>16) & 0x0000ffff);

    x = (x & 0x55555555) + ((x>>1) & 0x55555555);
    x = (x & 0x33333333) + ((x>>2) & 0x33333333);
    x = (x & 0x0f0f0f0f) + ((x>>4) & 0x0f0f0f0f);
    x = (x & 0x00ff00ff) + ((x>>8) & 0x00ff00ff);
    x = (x & 0x0000ffff) + ((x>>16) & 0x0000ffff);
    return x;
}


// 整数的二进制位翻转
unsigned int reverse_bits(unsigned int x) {
    x = ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);
    x = ((x & 0xCCCCCCCC) >> 2) | ((x & 0x33333333) << 2);
    x = ((x & 0xF0F0F0F0) >> 4) | ((x & 0x0F0F0F0F) << 4);
    x = ((x & 0xFF00FF00) >> 8) | ((x & 0x00FF00FF) << 8);
    x = ((x & 0xFFFF0000) >> 16) | ((x & 0x0000FFFF) << 16);
    return x;
}

// 计算前导零的数量
int count_leading_zeros(unsigned int x) {
    if (x == 0) return 32;
    
    int n = 0;
    if ((x & 0xFFFF0000) == 0) { n += 16; x <<= 16; }
    if ((x & 0xFF000000) == 0) { n += 8; x <<= 8; }
    if ((x & 0xF0000000) == 0) { n += 4; x <<= 4; }
    if ((x & 0xC0000000) == 0) { n += 2; x <<= 2; }
    if ((x & 0x80000000) == 0) { n += 1; }
    
    return n;
}



int main(int argc, char *argv[])
{
    unsigned x = strtoul(argv[1], NULL, 16);

    unsigned a = count_one(x);

    printf("\033[32m" "0x%x has %u one\n" "\033[0m",x, a );

    return 0;
}