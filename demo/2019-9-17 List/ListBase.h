
/////////ͷ�ļ�//////////
#pragma once
#include  <stdio.h>
#include  <stdlib.h>
/////////ͷ�ļ�//////////

/////////��/////////
#define  TRUE  1
#define  FALSE 0


/////////��/////////

////////����////////
typedef int ListEnum;

//Listģ��
typedef struct list {
	ListEnum *Enum;
	int length;
	int size;
}List;



////////����////////



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
