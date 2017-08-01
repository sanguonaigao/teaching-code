/*************************************************************************
    > File Name: test.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 四  9/22 13:47:45 2016
 ************************************************************************/

#include<stdio.h>

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXCEPT_EQ_BASE(equality, except, actual, format)\
	do\
	{\
		test_count++;\
		if(equality)\
		{\
			test_pass++;\
		}\
		else\
		{
			fprintf(stderr, \
					"%s:%d : except: " format "actual:" format "\n", __FILE__, __LINE__, except, actual);\
		}\
	}\

#define EXCEPT_EQ_INT(except, actual)\
		EXCEPT_EQ_BASE((except==actual), except, actual, "%d")
int main()
{
	return 0;
}
