code zpw$ 
zpwdeMacBook-Pro:fifty_c_code zpw$ vim print_min_and_max.c 
zpwdeMacBook-Pro:fifty_c_code zpw$ 
zpwdeMacBook-Pro:fifty_c_code zpw$ 
zpwdeMacBook-Pro:fifty_c_code zpw$ 
zpwdeMacBook-Pro:fifty_c_code zpw$ 
zpwdeMacBook-Pro:fifty_c_code zp
    > File Name: print_min_and_max.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 四  5/19 17:27:03 2016
 ************************************************************************/

#include<stdio.h>

void print_min_and_max(int arr[], int sz)
{
	int max = arr[0];
	int min = arr[0];
	int i = 0;
	for(i = 1;i<sz;i++)
	{
		if(min > arr[i])
			min = arr[i];
		if(max < arr[i])
			max = arr[i];
	}
	if(min == max)
	{
		printf("max = %d min = -1\n", max);
	}
	else
	{
		printf("max = %d min = %d\n", max, min);
	}	
}
	
int main()
{
	int arr[20] = {0};
	int sz = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	for(i = 0;i<20;i++)
	{
		arr[i] = i;
	}
	print_min_and_max(arr, sz);
	for(i = 0;i<20;i++)
	{
		arr[i] = 20;
	}
	print_min_and_max(arr, sz);
	return 0;
}
