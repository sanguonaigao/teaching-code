#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int DataType;
typedef struct LinkNode
{
	DataType data;
	struct LinkNode *next;
}LinkNode,*pLinkNode,*pList;

void InitList(pList* pplist);
void DestroyList(pList *pplist);
void PrintList(pList head);
int GetListLength(pList head);

void PushBack(pList *pplist, DataType x);
void PopBack(pList *pplist);

void PushFront(pList *pplist, DataType x);
void PopFront(pList *pplist);

pLinkNode Find(pList head, DataType x);
void Insert(pList *pplist, pLinkNode pos, DataType x);
void Remove(pList *pplist, DataType x);
void RemoveAll(pList *pplist, DataType x);
void Erase(pLinkNode *pplist, pLinkNode pos);

// 链表相关面试题

//删除非尾节点-----1
void EraseNotTail(pLinkNode pos);

//反转（逆序）链表--2
void ReverseList(pList* pplist);

//排序链表（冒泡）--3
void BubbleSort(pList * pplist);

// 删除非尾结点----4
void DelNonTailNode(pLinkNode pos);

// 在当前节点前插入一个数据x-----5
void InsertFrontNode(pLinkNode pos, DataType x);

//合并两个有序列表-----6
pLinkNode Merge(pList l1, pList l2);

//查找链表的中间节点---7
pLinkNode FindMidNode(pList head);

// 删除单链表的倒数第k个节点(k > 1 && k < 链表的总长度)----8
// 时间复杂度O(N)
void DelKNode(pList *pplist, int k);

// 【链表带环问题】-----9
// 判断链表是否带环, 若链表带环则求环的长度和相遇节点，不带环返回-1
pLinkNode CheckCycle(pList pList);
int GetCircleLength(pLinkNode meet);
//FindEntryNode()
// 获取环入口点
pLinkNode GetCycleEntryNode(pList list, pLinkNode meetNode);

// 【链表相交问题】
//
// 判断两个链表是否相交，假设两个链表都不带环。
// 求环的交点，长链表先走n步（n为两链表的长度差），然后再一起走，第一个相遇点则为交点。
//
int CheckCross(pList list1, pList list2);


/*链表实现相关功能*/

void InitList(pList* pplist)
{
	assert(pplist);
	*pplist = NULL;
}

void DestroyList(pList *pplist)
{
	pLinkNode cur = *pplist;
	assert(pplist);

	while (cur)
	{
		pLinkNode del = cur;//先保存将要保存要删除的节点
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}

void PrintList(pList head)
{
	pLinkNode cur = head;
	printf("list :");

	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("over\n");
}

int GetListLength(pList head)
{
	pLinkNode cur = head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

pLinkNode BuyNode(DataType x)
{
	pLinkNode newNode = (pLinkNode)malloc(sizeof(LinkNode));
	if (newNode == NULL)
	{
		printf("out of memory\n");
		exit(EXIT_FAILURE);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void PushBack(pList *pplist, DataType x)
{
	pLinkNode newNode = NULL;
	assert(pplist);
	newNode = BuyNode(x);
	//没有节点
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else//有一个及以上节点
	{
		pLinkNode cur = *pplist;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

void PopBack(pList *pplist)
{
	assert(pplist);
	//没有节点
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)//有一个节点
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	else//两个以上节点
	{
		pLinkNode cur = *pplist;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

void PushFront(pList *pplist, DataType x)
{
	pLinkNode newNode = BuyNode(x);
	assert(pplist);
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		newNode->next = *pplist;
		*pplist = newNode;
	}
}

void PopFront(pList *pplist)
{
	assert(pplist);
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		pLinkNode del = *pplist;
		*pplist = (*pplist)->next;
		free(del);
	}
}

pLinkNode Find(pList plist,DataType x)
{
	pLinkNode begin = plist;

	while (begin)
	{
		if (begin->data == x)
		{
			return begin;
		}
		begin = begin->next;
	}
	return NULL;
}
//指定位置之后插入一个数据
void Insert(pList *pplist, pLinkNode pos, DataType x)
{
	pLinkNode newNode = BuyNode(x);
	assert(pplist);
	assert(pos);
	//没有节点 
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else//一个节点以上
	{
		newNode->next = pos->next;
		pos->next = newNode;
	}
}

void Remove(pList *pplist, DataType x)
{
	pLinkNode begin = *pplist;
	pLinkNode prev = NULL;
	assert(pplist);
	while (begin)
	{
		if (begin->data == x)//如果找到了
		{
			pLinkNode del = begin;

			if ((*pplist) == begin)//是第一个节点
			{
				*pplist = (*pplist)->next;
			}
			else//非第一个节点
			{
				prev->next = begin->next;
			}
			free(del);
			return;
		}
		prev = begin;
		begin = begin->next;
	}
}

void RemoveAll(pList *pplist, DataType x)
{
	pLinkNode begin = *pplist;
	pLinkNode prev = NULL;
	assert(pplist);
	while (begin)
	{
		if (begin->data == x)//找到了
		{
			pLinkNode del = begin;

			if ((*pplist) == begin)//是第一个节点
			{
				*pplist = (*pplist)->next;
				begin = *pplist;
			}
			else//非第一个节点
			{
				prev->next = begin->next;
				begin = prev->next;//调整begin
			}
			free(del);
		}
		else//找不到向向后调整
		{
			prev = begin;
			begin = begin->next;
		}
	}
}

void Erase(pLinkNode *pplist, pLinkNode pos)
{
	pLinkNode prev = *pplist;
	assert(pplist);

	while (prev && prev->next != pos)
	{
		prev = prev->next;
	}

	if (prev != NULL)
	{
		pLinkNode del = pos;
		prev->next = pos->next;
		free(del);
	}
}

//删除无头单链表的非尾结点--
void EraseNotTail(pLinkNode pos)
{
	assert(pos->next);//如果为尾节点就断言失败，报错
	pLinkNode del = pos->next;
	pos->data = pos->next->data;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}

// 链表相关面试题

//反转（逆序）链表
void ReverseList(pList* pplist)
{
	assert(pplist);
	if ((*pplist == NULL) || ((*pplist)->next == NULL))//没有节点和只有一个节点
	{
		return;
	}
	pLinkNode cur = *pplist;
	pLinkNode tmp = NULL;
	pLinkNode newHead = NULL;
	while (cur != NULL)//头摘，头插
	{
		tmp = cur;
		cur = cur->next;
		tmp->next = newHead;
		newHead = tmp;	
	}
	*pplist = newHead;
}

//排序链表（冒泡）
void BubbleSort(pList * pplist)
{
	pLinkNode start = *pplist;
	pLinkNode tail = NULL;
	while (*pplist != tail)
	{
		while (start->next != tail)
		{
			if (start->data > start->next->data)
			{
				DataType tmp = start->data;
				start->data = start->next->data;
				start->next->data = tmp;
			}
			start = start->next;
		}
		tail = start;
		start = *pplist;
	}
}

// 在无头单链表的一个节点前插入一个数据x
void InsertFrontNode(pLinkNode n, DataType x)
{
	assert(n);
	pLinkNode newNode = BuyNode(x);
	DataType tmp;

	//将当前位置的后边
	newNode->next = n->next;
	n->next = newNode;

	//交换数据
	tmp = n->data;
	n->data = newNode->data;
	newNode->data = tmp;
}

//合并两个有序列表(非递归实现)
pLinkNode Merge(pList list1, pList list2)
{
	pList newList = NULL;
	pList begin1 = list1;
	pList begin2 = list2;
	pLinkNode tail = NULL;
	// 如果两个链表相同就无需合并，直接返回
	if (list1 == list2)
	{
		return list1;
	}
	// 若其中一个链表为空，则返回另一个链表
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}

	if (begin1->data > begin2->data)
	{
		newList = begin2;
		begin2 = begin2->next;
	}
	else
	{
		newList = begin1;
		begin1 = begin1->next;
	}

	//找较小的数据尾插
	tail = newList;

	while (begin1 && begin2)
	{
		if (begin1->data > begin2->data)
		{
			tail->next = begin2;
			begin2 = begin2->next;
			tail = tail->next;
		}
		else
		{
			tail->next = begin1;
			begin1 = begin1->next;
			tail = tail->next;
		}
	}
	//剩余链表的追加
	if (begin1)
	{
		tail->next = begin1;
	}
	else
	{
		tail->next = begin2;
	}

	return newList;
}


pLinkNode _Merge(pList list1, pList list2)
{
	pList newList = NULL;
	pList begin1 = list1;
	pList begin2 = list2;
	pLinkNode tail = NULL;
	// 如果两个链表相同就无需合并，直接返回
	if (list1 == list2)
	{
		return list1;
	}
	// 若其中一个链表为空，则返回另一个链表
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}

	if (begin1->data > begin2->data)
	{
		newList = begin2;
		//newList->next = _Merge(begin2->next, begin1);
		newList->next = _Merge(begin1, begin2->next);
	}
	else
	{
		newList = begin1;
		newList->next = _Merge(begin2, begin1->next);
	}

	return newList;
}

//
// 约瑟夫环（约瑟夫问题）是一个数学的应用问题：
// 已知n个人（以编号1，2，3...n分别表示）围坐在一张//圆桌周围。
// 从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人
// 又出列；依此规律重复下去，直到圆桌周围的人全部出列。
//
pLinkNode JosephCycle(pList * pplist, int num)
{
	assert(pplist);
	
	pLinkNode cur = *pplist;
	while (1)
	{
		int count = num;
		if (cur->next == cur)//剩一个人的时候停下来
		{
			break;
		}
		pLinkNode del = NULL;
		while (--count)//报数
		{
			cur = cur->next;
		}
		printf("del:%d\n", cur->data);
		del = cur->next;//交换法删除当前节点
		cur->data = cur->next->data;
		cur->next = cur->next->next;
		free(del);
		del = NULL;
	}
	return cur;
}

pLinkNode FindMidNode(pList head)
{
	if (head == NULL)
	{
		return NULL;
	}
	pLinkNode fast = head;
	pLinkNode slow = head;
	//当fast为NULL,则链表节点数为偶数个
	//当fast->next为NULL,则链表的节点数为奇数个
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


//删除第倒数K个节点
void DelKNode(pList *pplist, int k)
{
	pLinkNode slow = *pplist;
	pLinkNode fast = *pplist;
	assert(k > 1);
	
	if (*pplist == NULL)
	{
		return;
	}
	while (fast)
	{
		if (--k < 0)
		{
			slow = slow->next;
		}
		fast = fast->next;
	}

	if (k < 0)
	{
		pLinkNode del = slow->next;
		slow->data = slow->next->data;
		slow->next = slow->next->next;
		free(del);
	}
}


// 【链表带环问题】-----10
// 判断链表是否带环, 若链表带环则求环的长度和相遇节点，不带环返回NULL
pLinkNode CheckCycle(pList pList)
{
	int ret = 0;
	int len = 0;
	pLinkNode fast = pList;
	pLinkNode slow = pList;
	pLinkNode last = NULL;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return slow;
		}
	}
	return NULL;
}

int GetCircleLength(pLinkNode meet)
{
	pLinkNode cur = meet;
	meet = meet->next;
	int count = 1;
	while (meet != cur)
	{
		meet = meet->next;
		count++;
	}
	return count;
}

// 获取环入口点
pLinkNode GetCycleEntryNode(pList list, pLinkNode meetNode)
{
	assert(meetNode);

	pLinkNode start = list;
	pLinkNode entry = meetNode;
	while (entry != start)
	{
		entry = entry->next;
		start = start->next;
	}
	return entry;
}


// 获取环入口点(转换为链表相交问题)
pLinkNode GetCycleEntryNode2(pList list, pLinkNode meetNode)
{
	assert(meetNode);

	pLinkNode start1 = list;
	pLinkNode start2 = meetNode;
	pLinkNode entry = meetNode;
	pLinkNode end = meetNode;
	int len1 = 1;
	int len2 = 1;
	while (start1->next != end)
	{
		len1++;
		start1 = start1->next;
	}
	while (start2->next != end)
	{
		len2++;
		start2 = start2->next;
	}
	int count = (len1 > len2 ? len1 - len2 : len2 - len1);
	start1 = list;
	start2 = meetNode;

	if (len1 > len2)
	{
		while (--count)
		{
			start1 = start1->next;
		}
	}
	else
	{
		while (--count)
		{
			start2 = start2->next;
		}
	}
	while (start1 != start2)
	{
		start1 = start1->next;
		start2 = start2->next;
	}
	entry = start1;
	return entry;
}

//
// 【链表相交问题】
//
// 判断两个链表是否相交，假设两个链表都不带环。
//
int CheckCross(pList list1, pList list2)
{
	assert(list1);
	assert(list2);

	pLinkNode end1= 0;
	pLinkNode end2 = 0;

	while (list1)
	{
		end1 = list1;
		list1 = list1->next;
	}
	while (list2)
	{
		end2 = list2;
		list2 = list2->next;
	}
	if (end1 == end2)
	{
		return 1;
	}
	return 0;
}


