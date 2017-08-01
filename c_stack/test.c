#include "stack.h"

int main()
{
	int i = 100;
	Stack st;
	InitStack(&st);

	while(i--)
	{
		Push(&st, i);
	}
	while(IsEmpty(&st))
	{
		printf("%d ", Top(&st));
		Pop(&st);
	}
	DestroyStack(&st);
	return 0;
}