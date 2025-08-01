#include <stdio.h>
#include <stdint.h>

// 使用SWAR同时比较4个字节
/*
* 一次性处理所有4个字节
* 单独识别出哪些字节不同
*/
int compare_four_bytes(uint32_t a, uint32_t b) {
    // 1. 计算XOR (相同位为0，不同位为1)
    uint32_t xor_result = a ^ b;
    
    // 2.位传播：使用位移和OR操作在每个字节内传播差异
    // 每个字节内部扩散任何不同的位
    // 如果任一字节中有任何位不同，对应字节的MSB将变为1
    uint32_t detector = xor_result | (xor_result << 1);
    detector |= (detector << 2);
    detector |= (detector << 4);
    
    // 3. 提取每个字节的MSB组成一个掩码
    uint32_t mask = (detector & 0x80808080) >> 7;
    
    // 4. 如果mask为0，所有字节都相同
    printf("0x%x\n", mask);
    return mask == 0;
}

int main() {
    // 包含4个字节的两个32位整数
    uint32_t a = 0x11223344; // 4个字节: 0x11, 0x22, 0x33, 0x44
    uint32_t b = 0x11223344; // 相同的4个字节
    uint32_t c = 0x11223345; // 只有最后一个字节不同
    uint32_t d = 0x01223344; // 第一个字节不同
    uint32_t e = 0x01123344; // 第1 ,2个字节不同
    
    printf("a和b的字节是否全部相同: %s\n", 
           compare_four_bytes(a, b) ? "是" : "否");
    
    printf("a和c的字节是否全部相同: %s\n", 
           compare_four_bytes(a, c) ? "是" : "否");
    
    printf("a和d的字节是否全部相同: %s\n", 
            compare_four_bytes(a, d) ? "是" : "否");
    printf("a和e的字节是否全部相同: %s\n", 
        compare_four_bytes(a, e) ? "是" : "否");

    return 0;
}