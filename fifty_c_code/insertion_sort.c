/*************************************************************************
    > File Name: insertion_sort.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 四  5/19 15:53:08 2016
 ************************************************************************/

#include<stdio.h>


void insertion_sort(int arr[], int first, int last)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for(i = first+1; i<=last; i++)
	{
		tmp = arr[i];//保存有序元素之后第一个元素的值
		//循环从后向前找一个小于这个值的元素，否则将这个数字后移
		for(j = i-1; j>=first && arr[j] > tmp; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = tmp;
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	int i = 0;
	insertion_sort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	for(i = 0; i<sizeof(arr)/sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}




