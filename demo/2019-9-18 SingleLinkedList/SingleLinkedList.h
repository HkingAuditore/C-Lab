///<summary>
///命名规范
///全局变量 _AaaaBbbb
///函数名		AaaaBbbb
///函数参数 _aaaaBbbb
///函数内变量 aaaaBbbb
///
///
///
///<summary>


///<summary>任务栏///////////////
///
///
//TODOCLAB#1 这运行也太卡了，啥情况			--2019-9-21 01:03:47
//TODOCLAB#2 没有写销毁链表的方法			--2019-9-21 01:05:36
//
//
///<summary>///////////////////

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
		return NULL;
}

//在尾巴上加一个节点
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

//生成只有头的单链表
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
	//准备工作
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

//读取链表里所有的数据
static int ReadWholeLinkListData(SingleLinkList* _list)
{
	SingleLinkListNode* curPos = _list->Head->Next;
	for(int i=1;i<=_list->Length;i++)
	{
		printf("Num.%d:%d\n", i, curPos->Data);
		curPos = curPos->Next;
	}
}


///////////////函  数//////////////////
