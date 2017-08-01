#include <stdio.h>
//填坑法
void Swap(char* pArr, char* pPos, int nCount)
{
	int cur = 0;
	char tmp = *pArr;//记录第一个变量的值-最后存储
	int index2 = pPos[0];//给定小标数组的的起始下标
	int count = 0;
	while(--nCount)//count-1次填坑，最后一次得使用tmp赋值
	{
		pArr[cur] = pArr[index2];
		cur = index2;
		index2 = pPos[index2];
		count++;
	}
	pArr[cur] = tmp;
}

int main()
{
	char arr[] = "abcde";
	int count = strlen(arr);
	char seq[] = {3,0,1,4,2};
	Swap(arr, seq, count);
	printf("%s\n", arr);
	return 0;
}
