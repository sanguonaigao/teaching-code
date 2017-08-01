/*************************************************************************
    > File Name: reverse_bit.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 五  5/20 09:26:41 2016
 ************************************************************************/

#include<stdio.h>

unsigned int reverse_bit(unsigned int num)
{
	unsigned int ret = 0;
	int i = 0;
	for(i = 0; i<32; i++)
	{
		ret<<=1;
		ret |= num%2;
		num /= 2;
	}
	return ret;
}
int main()
{
	//int num = 15;
	int num = 4026531840;
	unsigned int ret = reverse_bit(num);
	printf("%u", ret);
	return 0;
}
