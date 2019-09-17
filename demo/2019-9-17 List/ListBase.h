
/////////ͷ�ļ�//////
#pragma once
#include  <stdio.h>
#include  <stdlib.h>
/////////ͷ�ļ�//////

/////////��/////////
#define  TRUE  1
#define  FALSE 0


/////////��/////////

////////����////////
typedef int ListEnum;

//Listģ��
typedef struct list {
	ListEnum *Enum;
	int Length;
	int Size;
}List;



////////����////////


//��ʼ��
static int InitList(List*_list,int _sizeOfList)
{
	_list->Size = _sizeOfList;
	printf("Init!\n");
	_list->Enum = (ListEnum*)malloc(_list->Size * sizeof(ListEnum));
	if(!(_list->Enum))
	{
		printf("Faild!\n");
		exit(0);
	}
	_list->Length = 0;
	return 0;
}

//����List����0����
static int GenerateList(List* _list)
{
	for(int i=0;i<_list->Length;i++)
	{
		_list->Enum[i] = 0;
	}
	return 0;
}

//��ӡList������Ԫ��
static int PrintList(List* _list)
{
	printf("Show List:");
	for(int i=0;i<_list->Length;i++)
	{
		printf("%d ", _list->Enum[i]);
	}
	printf("\n");
	return 0;
}

//���Ԫ��
static int AddEnumToList(List* _list,ListEnum _enum)
{
	_list->Enum[_list->Length] = _enum;
	_list->Length++;
	return 0;
}

//�Ƴ���i��Ԫ��
static int RemoveEnumFromList(List* _list,int _num)
{
	_num --;
	if(_num > (_list->Length-1))
	{
		return 1;
	}
	for(int i=_num;i<_list->Length-1;i++)
	{
		_list->Enum[i] = _list->Enum[i + 1];
	}
	_list->Length-=1;
}
