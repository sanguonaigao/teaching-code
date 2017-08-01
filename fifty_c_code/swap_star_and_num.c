/*************************************************************************
    > File Name: swap_star_and_num.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 日  7/ 3 20:35:32 2016
 ************************************************************************/

#include <stdio.h>
#include <string.h>
/*
 *	字符数组中只有*和数字，实现程序使*号都在前面，数字都在后面
 *	1.数字不要求保持数序
 *	2.数字要求保证数序
 */
//slotion 1
//循环不变式：由前向后
//假设[0,i-1]为*，[i，j-1]为数字，[j, n-1]为未探测部分
//
void _swap(char *c1, char *c2)
{
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}
void swap_star_and_num(char *arr, int n)
{
	int i = 0;
	int j = 0;//记录*和数字的临界点
	for(; j<n; j++)
	{
		if(arr[j] == '*')
		{
			_swap(arr+i, arr+j);
			i++;
		}
	}
}

//slotion 2
//循环不变式，由后向前
//
void swap_star_and_num_2(char *arr, int n)
{
	int i = n-1;
	int j = n-1;
	for(; j>=0; j--)
	{
		if(arr[j]  != '*')
		{
			_swap(arr+i, arr+j);
			i--;
		}
	}
	for(; i>= 0; i--)
	{
		arr[i] = '*';
	}
}
int main()
{
	char arr[] = "*01*2*4";
	swap_star_and_num_2(arr, strlen(arr));
	printf("%s\n",arr);
	return 0;
}





