/*************************************************************************
    > File Name: reverse_some_words.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 三  5/18 11:27:40 2016
 ************************************************************************/

//要求：现在又一个字符数组的内容是"student a am i",
//		想让数组的内容是："i am a student"。
//		编程实现。
//
#include <stdio.h>
#include <string.h>
#include <assert.h>

void reverse_str(char *left, char *right)
{
    assert(left);
    assert(right);
    while(left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

void reverse_some_words(char *str)
{
    char *start = str;
    char *end = NULL;
    while(*start)
    {
        end = start;
        while(*end && *end != ' ')
        {
            end++;
        }
        
        reverse_str(start, end-1);
        if(*end != '\0')
        {
            end++;
        }
        start = end;
    }
    reverse_str(str, start-1);
}

int main()
{
    char arr[] = "student a am i";
    reverse_some_words(arr);
    printf("%s\n",arr);
    return 0;
}