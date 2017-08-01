/*************************************************************************
    > File Name: stack.c
    > Author: peter
    > Mail: zpengwei@yeah.net 
    > Created Time: 一  6/ 6 13:20:56 2016
 ************************************************************************/

#include <stdio.h>
#include "stack.h"

void InitStack(pStack_t ps)
{
	assert(ps);
	ps->data = malloc(sizeof(DataType) * DEFAULT_SIZE);
	if(ps->data == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SIZE;
}

void CheckCapacity(pStack_t ps)
{
	if(ps->size == ps->capacity)
	{
		DataType* tmp = realloc(ps->data, sizeof(DataType) * (ps->capacity + INC));
		if(tmp == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		else 
		{
			ps->data = tmp;
			ps->capacity += INC;
		}
	}
}
void Push(pStack_t ps, DataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->data[ps->size++] = x;
}

void Pop(pStack_t ps)
{
	assert(ps);
	ps->size--;
}

int IsEmpty(pStack_t ps)
{
	return ps->size;
}


DataType Top(pStack_t ps)
{
	return ps->data[ps->size-1];
}

void DestroyStack(pStack_t ps)
{
	assert(ps);
	free(ps->data);
}


