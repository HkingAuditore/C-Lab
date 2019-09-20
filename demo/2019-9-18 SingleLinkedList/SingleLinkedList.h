///<summary>
///�����淶
///ȫ�ֱ��� _AaaaBbbb
///������		AaaaBbbb
///�������� _aaaaBbbb
///�����ڱ��� aaaaBbbb
///
///
///
///<summary>


///<summary>������///////////////
///
///
//TODOCLAB#1 ������Ҳ̫���ˣ�ɶ���			--2019-9-21 01:03:47
//TODOCLAB#2 û��д��������ķ���			--2019-9-21 01:05:36
//
//
///<summary>///////////////////

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
		return NULL;
}

//��β���ϼ�һ���ڵ�
static int AddNode(ListEnum _data,SingleLinkList* _list)
{
	SingleLinkListNode* node2Add = CreateNode(_data);
	if (!node2Add)return 0;
	if (_list->Tail) {
			_list->Tail->Next = node2Add;
	}else
	{
			_list->Head->Next = node2Add;

	}
	_list->Tail = node2Add;
	_list->Length++;
	// printf("	newnode.data=%d\n", node2Add->Data);
	// printf("	tailnode.data=%d\n", _list->Tail->Data);
	return  1;
}

//����ֻ��ͷ�ĵ�����
static SingleLinkList* GenerateEmptyLinkList()
{
	SingleLinkList *list;
	if (
		(list = (SingleLinkList*)malloc(sizeof(SingleLinkList))) &&
		(list->Head = (SingleLinkListNode*)calloc(1, sizeof(SingleLinkListNode)))
		)
	{
		list->Tail = NULL;
		list->Head->Next = list->Tail;
		list->Length = 0;
		return list;
	}
	return NULL;
}


static SingleLinkList* GenerateLinkList(int _numOfNode)
{
	//׼������
	SingleLinkList *list;
	if(list = GenerateEmptyLinkList())
	{
		for (int i = 1; i <= _numOfNode; i++)
		{
			// printf("		No.%d:", i);
			AddNode(i, list);
		}
		return list;
	}
	return NULL;

}

//��ȡ���������е�����
static int ReadWholeLinkListData(SingleLinkList* _list)
{
	SingleLinkListNode* curPos = _list->Head->Next;
	for(int i=1;i<=_list->Length;i++)
	{
		printf("Num.%d:%d\n", i, curPos->Data);
		curPos = curPos->Next;
	}
}


///////////////��  ��//////////////////
