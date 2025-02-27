#include <stdio.h>
#include <stdlib.h>
// strtol函数的使用：字符串转换为long num
// 返回被转换的长整型整数值
// 如果输入字符串不符合数字格式，strtol() 将返回 0
// endptr 将指向 "ab" 的起始位置，指示转换失败
int main() {
	//    char str[] = "12ab"; // 12345 就OK, 或strt最后一个参数是16也行
	char str[] = "12,34";
    char *endptr;
    long int num;
	
	// strtol
    num = strtol(str, &endptr, 10); // &endptr相当于地址的地址

    if (*endptr != '\0') {
        printf("转换失败：输入字符串不是一个有效的整数。未转换部分：%s, 转换部分：%ld\n", endptr, num);
    } else {
        printf("转换结果：%ld\n", num);
    }

    return 0;
}
