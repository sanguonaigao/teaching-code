/*************************************************************************
    > File Name: my_strcpy.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 六  5/ 7 13:03:34 2016
 ************************************************************************/

#include <stdio.h>
#include <assert.h>

char *my_strcpy(char *dest, const char *src)
{
	char *ret = dest;
	assert(dest);
	assert(src);
	//拷贝过程，包含'\0'
	while((*dest++ = *src++) != '\0')
	{
		;
	}
	return ret;
}
int main()
{
	char arr[20] = {0};
	my_strcpy(arr, "hello bit.");
	printf("%s\n",arr);
	return 0;
}
