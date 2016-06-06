#define _CRT_SECURE_NO_WARNINGS 1
#include "link_list.h"

void test()
{
	pList mylist;
	InitList(&mylist);
	PushBack(&mylist, 1);
	PushBack(&mylist, 2);
	PushBack(&mylist, 3);
	PushBack(&mylist, 4);
	PopBack(&mylist);
	PopBack(&mylist);
	PushFront(&mylist, 9);
	PrintList(mylist);

	PushFront(&mylist, 8);
	PrintList(mylist);

	PushFront(&mylist, 7);
	PrintList(mylist);

	PushFront(&mylist, 6);
	BubbleSort(&mylist);
	PrintList(mylist);
	printf("-----\n");
	PopFront(&mylist);
	PrintList(mylist);

	PopFront(&mylist);
	PrintList(mylist);

	PopFront(&mylist);
	PrintList(mylist);
	pLinkNode pos = Find(mylist, 9);
	Insert(&mylist, pos, 10);
	Insert(&mylist, pos, 10);
	PrintList(mylist);
	pos = Find(mylist, 10);
	PrintList(mylist);

	Erase(&mylist,pos);
	PrintList(mylist);
	printf("~~~~~\n");
	pos = Find(mylist, 10);
	InsertFrontNode(pos,12);
	//EraseNotTail(pos);
	//Erase(&mylist, pos);
	//RemoveAll(&mylist, 10);
	PrintList(mylist);
	ReverseList(&mylist);
	PrintList(mylist);

	DestroyList(&mylist);
}

void test2()
{
	pList mylist1;
	pList mylist2;
	InitList(&mylist1);
	InitList(&mylist2);
	PushBack(&mylist1, 1);
	PushBack(&mylist1, 3);
	PushBack(&mylist2, 2);
	PushBack(&mylist2, 4);
	PushBack(&mylist2, 6);
	pList newList = _Merge(mylist1,mylist2);
	//PrintList(newList);
	//Find(newList, 4)->next = newList;
	//pLinkNode last =  JosephCycle(&newList,3);
	//printf("%d\n", last->data);
	//pLinkNode now = FindMidNode(newList);
	//printf("%d\n", now->data);
	//PrintList(newList);
	//DelKNode(&newList,7);
	PrintList(newList);

	DestroyList(&newList);
}


void test3()
{
	pList mylist;
	InitList(&mylist);
	PushBack(&mylist, 1);
	PushBack(&mylist, 2);
	PushBack(&mylist, 3);
	PushBack(&mylist, 4);
	pLinkNode pos = Find(mylist,3);
	Find(mylist, 4)->next = pos;
	pLinkNode meet = CheckCycle(mylist);
	
	printf("meet data:%d\n", meet->data);

	int len = GetCircleLength(meet);
	printf("len = %d\n", len);
	pLinkNode entry = GetCycleEntryNode2(mylist,meet);
	printf("%d\n", entry->data);
}

void test4()
{
	pList mylist1;
	InitList(&mylist1);
	PushBack(&mylist1, 1);
	PushBack(&mylist1, 2);
	PushBack(&mylist1, 3);
	PushBack(&mylist1, 4);

	pList mylist2;
	InitList(&mylist2);
	PushBack(&mylist2, 5);
	PushBack(&mylist2, 6);
	PushBack(&mylist2, 7);
	PushBack(&mylist2, 8);

	pLinkNode pos = Find(mylist1,3);
	pLinkNode last = Find(mylist2, 8);
	last->next = pos;

	int ret = CheckCross(mylist1, mylist2);
	printf("%d\n", ret);
}

void test5()
{
	pList mylist1;
	InitList(&mylist1);
	PushBack(&mylist1, 1);
	PushBack(&mylist1, 1);
	PushBack(&mylist1, 2);
	PushBack(&mylist1, 3);
	//PopBack(&mylist1);
	RemoveAll(&mylist1, 1);
	PrintList(mylist1);
}

void test6()
{
	pList mylist1;
	InitList(&mylist1);
	int i = 0;
	for(i = 1;i<=41;i++)
	{
		PushBack(&mylist1, i);
	}
	PrintList(mylist1);
	pLinkNode pos = Find(mylist1, 41);
	pos->next = mylist1;
	printf("%d ",(JosephCycle(&mylist1, 3)->data));
}
int main()
{
	test6();
	system("pause");
	return 0;
}