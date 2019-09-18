
/////////头文件//////
#pragma once
#include  <stdio.h>
#include  <stdlib.h>
/////////头文件//////

/////////宏/////////
#define  TRUE  1
#define  FALSE 0


/////////宏/////////

////////类型////////
typedef int ListEnum;

//List模板
typedef struct list {
	ListEnum *Enum;
	int Length;
	int Size;
}List;



////////类型////////


//初始化
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

//生成List，用0填满
static int GenerateList(List* _list)
{
	for(int i=0;i<_list->Length;i++)
	{
		_list->Enum[i] = 0;
	}
	return 0;
}

//打印List内所有元素
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

//添加元素
static int AddEnumToList(List* _list,ListEnum _enum)
{
	_list->Enum[_list->Length] = _enum;
	_list->Length++;
	return 0;
}

//移除第i个元素
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
