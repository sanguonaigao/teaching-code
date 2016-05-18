/*************************************************************************
    > File Name: selection_sort.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 三  5/18 13:47:18 2016
 ************************************************************************/

#include<stdio.h>
/**************************
 *	选择排序实现
* ************************/

void selection_sort(int arr[], int n)
{
	int min = 0;//每次最小值的下标
	int tmp = 0;//用于交换两个变量
	int i = 0;//用于循环
	int j = 0;//用于循环
	for(i = 0; i<n; i++)
	{
		min = i;
		//查找最小值的下标
		for(j=i+1; j<n; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		//交换数据
		if(i != min)
		{
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	selection_sort(arr, sizeof(arr)/sizeof(arr[0]));
	for(i=0; i<sizeof(arr)/sizeof(arr[0]) ;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
