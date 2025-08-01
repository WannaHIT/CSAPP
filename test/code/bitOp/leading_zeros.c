#include <stdio.h>
#include <stdint.h>

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
    unsigned x = 0xff;
    int n = count_leading_zeros(x);
    printf("%d\n", n);
    return  0;
}