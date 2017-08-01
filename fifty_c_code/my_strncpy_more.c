/************************************************************************
    > File Name: my_strcpy.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 六  5/ 7 13:03:34 2016
 ************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <string.h>

char *my_strncpy(char *dest, const char *src, int count)
{
	char *ret = dest;
	int len_src = strlen(src);
	int more = 0;
	assert(dest);
	assert(src);
	if(count >= len_src)
	{
		more = count-len_src;
	}
	//拷贝过程，包含'\0'
	while(len_src / 4)
	{
		*(unsigned int *)dest = *(unsigned int *)src;
		dest += 4;
		src += 4;
		len_src -= 4;
	}
	int last = len_src%4;
	while(last--)
	{
		*dest++ = *src++;
	}
	while(more--)
	{
		*dest++ = '\0';
	}
	return ret;
}

int main()
{
	char arr[200] = {0};
	int i = 0;
	for(i = 0; i<100000000; i++)
		my_strncpy(arr, "hello bit.", 20);
	printf("%s\n",arr);
	return 0;
}
