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


//////////////////////////////////////任务栏///////////////////////////////////////////
///TODOCLAB#1 这运行也太卡了，啥情况			--2019-9-21 01:03:47
///TODOCLAB#2 没有写销毁链表的方法			--2019-9-21 01:05:36            ***DONE***
///TODOCLAB#3 插入方法需要优化				--2019-9-21 12:17:02
///
///
//////////////////////////////////////////////////////////////////////////////////////

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
	SingleLinkList *list;
	if(list = GenerateEmptyLinkList())
	{
		for (int i = 1; i <= _numOfNode; i++)
		{
			AddNode(i, list);
		}
		return list;
	}
	return NULL;

}

//读取链表里所有的数据
static int ReadWholeLinkListData(SingleLinkList* _list)
{
	if (_list) {
		SingleLinkListNode* curPos = _list->Head->Next;
		for (int i = 1; i <= _list->Length; i++)
		{
			printf("Num.%d:%d\n", i, curPos->Data);
			curPos = curPos->Next;
		}
		return 1;
	}else
	{
		printf("Empty List!!!");
		return 0;
	}
}

//销毁链表
static SingleLinkList* DestroyLinkList(SingleLinkList* _list)
{
	SingleLinkListNode* curPos = _list->Head->Next;
	SingleLinkListNode* destroyPos = _list->Head;
	while(curPos->Next)
	{
		free(destroyPos);
		destroyPos = curPos;
		curPos = curPos->Next;
	}
	free(destroyPos);
	free(curPos);
	free(_list);
	return NULL;
}

//插入数据
//TODOCLAB#3 插入方法需要优化		--2019-9-21 12:17:02
static int InsertNode2LinkList(SingleLinkList* _list,int _num2Insert,struct singleLinkListNode* _node2Insert)
{
	SingleLinkListNode* curPos=_list->Head;
	for(int i=1;i<=_num2Insert;i++)
	{
		curPos = curPos->Next;
	}
	SingleLinkListNode* nextPos = curPos->Next;
	curPos->Next = _node2Insert;
	_node2Insert->Next = nextPos;
	_list->Length++;
	return 1;
}

//获取目标node地址
static SingleLinkListNode* GetNode(SingleLinkList* _list,int _num2Get)
{
	SingleLinkListNode* curPos = _list->Head;
	if (_num2Get>_list->Length)
	{
		return NULL;
	}
	for(int i=1;i<=_num2Get;i++)
	{
		curPos = curPos->Next;
	}
	return curPos;
}

//删除节点
static int DeleteNode(SingleLinkList* _list,int _num2Delete)
{
	SingleLinkListNode* curPos = GetNode(_list, _num2Delete-1);
	if (!(curPos->Next))return 0;
	SingleLinkListNode* node2Delete = curPos->Next;
	curPos->Next = curPos->Next->Next;
	_list->Length--;
	
	free(node2Delete);

	return 1;
}

///////////////函  数//////////////////
