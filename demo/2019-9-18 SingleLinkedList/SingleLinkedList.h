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


//////////////////////////////////////������///////////////////////////////////////////
///TODOCLAB#1 ������Ҳ̫���ˣ�ɶ���			--2019-9-21 01:03:47
///TODOCLAB#2 û��д��������ķ���			--2019-9-21 01:05:36            ***DONE***
///TODOCLAB#3 ���뷽����Ҫ�Ż�				--2019-9-21 12:17:02
///
///
//////////////////////////////////////////////////////////////////////////////////////

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

//��ȡ���������е�����
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

//��������
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

//��������
//TODOCLAB#3 ���뷽����Ҫ�Ż�		--2019-9-21 12:17:02
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

//��ȡĿ��node��ַ
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

//ɾ���ڵ�
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

///////////////��  ��//////////////////
