///////////////头文件//////////////////

#pragma once
#include  <stdio.h>
#include  <stdlib.h>

///////////////头文件//////////////////

///////////////类  型//////////////////

typedef int ListEnum;

//单个节点
typedef  struct  singleLinkListNode {
	ListEnum Data;
	struct  singleLinkListNode *Next;
}SingleLinkListNode;

//链表组
typedef  struct  singleLinkList {
	SingleLinkListNode *Head, *Tail;
	int Length;
}SingleLinkList;

///////////////类  型//////////////////

///////////////函  数//////////////////

//生成节点
static SingleLinkListNode* CreateNode(ListEnum _data)
{
	SingleLinkListNode *node;
	if ((node = (SingleLinkListNode*)malloc(sizeof(SingleLinkListNode))))
	{
		node->Data = _data;
		node->Next = NULL;
		return node;
	}
	else 
	{
		return NULL;
		
	}
}

///////////////函  数//////////////////
