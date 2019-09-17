
/////////头文件//////////
#pragma once
#include  <stdio.h>
#include  <stdlib.h>
/////////头文件//////////

/////////宏/////////
#define  TRUE  1
#define  FALSE 0


/////////宏/////////

////////类型////////
typedef int ListEnum;

//List模板
typedef struct list {
	ListEnum *Enum;
	int length;
	int size;
}List;



////////类型////////



static int InitList(List*_list,int _sizeOfList)
{
	_list->size = _sizeOfList;
	printf("Init!\n");
	_list->Enum = (ListEnum*)malloc(_list->size * sizeof(ListEnum));
	if(!(_list->Enum))
	{
		printf("Faild!\n");
		exit(0);
	}
	_list->length = 0;
	return 0;
}

static int GenerateList(List* _list)
{
	for(int i=0;i<_list->size;i++)
	{
		_list->Enum[i] = 0;
	}
	return 0;
}

static int PrintList(List* _list)
{
	for(int i=0;i<_list->size;i++)
	{
		printf("%d\n", _list->Enum[i]);
	}
	return 0;
}
