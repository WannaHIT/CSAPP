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

    // 0 1 这种情况两者一样, 但是 ...
    // 我知道了, 不是 或 而是相加, 因为1 | 1 = 1, 那就丢了一个 1 
    // 1 + 1 = 10, 
    // 将32位数划分为16个2位组，计算每组中1的个数
    x = (x & 0x55555555) + ((x>>1) & 0x55555555);
    // 将结果划分为8个4位组，累加相邻2位组的结果
    x = (x & 0x33333333) + ((x>>2) & 0x33333333);
    // 将结果划分为4个8位组，累加相邻4位组的结果
    x = (x & 0x0f0f0f0f) + ((x>>4) & 0x0f0f0f0f);
    // 将结果划分为2个16位组，累加相邻8位组的结果
    x = (x & 0x00ff00ff) + ((x>>8) & 0x00ff00ff);
    // 最后累加两个16位组的结果
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





int main(int argc, char *argv[])
{
    unsigned x = strtoul(argv[1], NULL, 16);

    unsigned a = count_one(x);

    printf("\033[32m" "0x%x has %u one\n" "\033[0m",x, a );

    return 0;
}