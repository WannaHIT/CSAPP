#include<stdio.h>
// little tip: 在汇编代码中，内层循环的条件在上面
int main(void)
{
	int i, j, k = 0;
	for(i=0; i<2; i++)
	{
		for(j=0; j<5; j++)
		{
			++k;
		}
	}
	printf("K = %d\n", k);
	return 0;
}
