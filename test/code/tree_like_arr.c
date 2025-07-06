// 通过 lowbit 进行跳跃式的移动
// 一个数组，通过 lowbit 运算模拟出了一棵隐含的树形结构
#include<stdio.h>

#define MAX_N 100 

int n; 
int tree[MAX_N+1];
/*
 * @brief lowbit(x), 即x的二进制中,最低位的1代表的值
 * @param x 输入的整数
 * @return 返回lowbit(x)的结果
 * 这是树状数组的核心工具函数
 */

int lowbit(int  x)
{
	return x & ((~x) + 1);
}

/**
 * @brief 更新操作: 在原数组的index位置上增加一个值delta
 * 时间复杂度 O(log n)
 * @param index 要更新的位置(1-based)
 * @param delta 增加的量, 可以是负数
 */
void update(int index, int delta)
{
	// 从当前位置开始, 不断的向上级汇报
	while(index <= n){
		// 给当前节点增加delta
		tree[index] += delta;
		// 移动到下一个需要更新的父节点
		index += lowbit(index);
	}
}

/* @brief 查询操作: 计算原数组从第一个元素到第index的和(前缀和)
 * 时间复杂度 O(log n)
 * @param index 查询的位置
 * @return 返回前缀和 A[1] + ... + A[index]
 */
int query(int index)
{
	int sum = 0;
	while(index > 0)
	{
		sum += tree[index];
		index -= lowbit(index);
	}
	return sum;
}

int main(void)
{
	// 以 8 个元素为例
	n = 8;
	
	int A[] = {0, 1, 3, 5, 7, 9, 11, 13, 15}; // 原始数据，下标0未使用
	
	printf("原始数组A: ");
	for(int i=1; i<=n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	// init tree-like array
	printf("init tree-like array...\n");
	for(int i=1; i<=n; i++)
	{
		update(i, A[i]);
	}

	printf("init completed.\n\n");

	// 计算前缀和 Sum(1...7) = 1+3+5+7+9+11+13 = 49
	int sum_1_to_7 = query(7);
	printf("prefix sum 1 to 7 : %d\n", sum_1_to_7);


	int sum_1_to_4 = query(4);
	printf("prefix sum 1 to 4 : %d\n", sum_1_to_4);

	// 在原数组 A[3] 的位置上，增加 5
	update(3, 5);
	A[3] += 5; // 更新我们自己的数组A ,便于验证
	

	sum_1_to_7 = query(7);
	printf("prefix sum 1 to 7 : %d\n", sum_1_to_7);

	int sum_1_to_2 = query(2);
	printf("prefix sum 1 to 2 : %d\n", sum_1_to_2);

	return 0;
}
