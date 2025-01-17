#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// 跳过输入字符串里面的逗号
int str2i(const char *str, char split, char **endptr)
{
    int ret = 0;
    ret = strtol(str, endptr, 10);
    if (*endptr != NULL) {
        if (**endptr == split) {
            *endptr += 1;
        }
    }

    return ret;
}

int main(void)
{
    char *test_str = "1,2,3,4,5";
    char *end = NULL;
    int res[5] = {0};
    char *p_shift = test_str;

    for (int i = 0; i < 5; i++) {
        res[i] = str2i(p_shift, ',', &end);
        p_shift = end;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", res[i]);
    }
	printf("\n");
	return 0;
}
