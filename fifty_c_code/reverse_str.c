/*************************************************************************
    > File Name: reverse_str.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 五  4/29 01:02:51 2016
 ************************************************************************/

#include<stdio.h>
//完成字符串的逆序
void reverse(char *str)
{
	assert(str);

	char *left = str;
	char *right = str + strlen(str)-1;
	while(left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
