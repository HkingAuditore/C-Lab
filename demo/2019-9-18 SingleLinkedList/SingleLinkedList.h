///////////////ͷ�ļ�//////////////////

#pragma once
#include  <stdio.h>
#include  <stdlib.h>

///////////////ͷ�ļ�//////////////////

///////////////��  ��//////////////////

typedef int ListEnum;

//�����ڵ�
typedef  struct  singleLinkListNode {
	ListEnum Data;
	struct  singleLinkListNode *Next;
}SingleLinkListNode;

//������
typedef  struct  singleLinkList {
	SingleLinkListNode *Head, *Tail;
	int Length;
}SingleLinkList;

///////////////��  ��//////////////////

///////////////��  ��//////////////////

//���ɽڵ�
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

///////////////��  ��//////////////////
