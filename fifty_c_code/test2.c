/*************************************************************************
    > File Name: test2.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 四  5/26 16:06:45 2016
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{

	char arr[100] = {0};
	int i = 0;
	for(i = 0;i<10000000;i++)
	{
		memcpy(arr, "1234567890", 11);
	}
	return 0;
}
