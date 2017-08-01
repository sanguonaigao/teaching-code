/*************************************************************************
    > File Name: stack.h
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 一  6/ 6 13:02:49 2016
 ************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

#define DEFAULT_SIZE 3
#define INC	2

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef int DataType;

typedef struct Stack
{
	DataType *data;
	int size;
	int capacity;
}Stack,*pStack_t;

void InitStack(pStack_t ps);
void DestroyStack(pStack_t ps);
void Push(pStack_t ps,DataType x);
void Pop(pStack_t ps);
int IsEmpty(pStack_t ps);
DataType Top(pStack_t ps);


#endif// __STACK_H__

