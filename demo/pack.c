#include "2019-9-25 Stack/Stack.h"
#include "2019-9-25 Stack/ViewManager.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct item{
	int Weight;
	int Num;

}Item;
typedef struct pack{
	Item* Items;
	int MaxWeight;
	int	NumOfItems;
	Item* Picked;
	int NumOfPicked;
	int weightOfPicked;

}Pack;

int GeneratePack(Pack* _pack, int _maxWeight, int _numOfItem)
{
	SetRandSeed();
	_pack->Items = (Item*)malloc(_numOfItem * sizeof(Item));
	// _pack->List = (int*)malloc(_numOfItem * sizeof(int));
	for(int i=0;i< _numOfItem;i++)
	{
		_pack->Items[i].Weight = GetPowerNumber(_maxWeight-1)+1;
		_pack->Items[i].Num = i;
	}
	_pack->NumOfItems = _numOfItem;
	_pack->MaxWeight = _maxWeight;
	_pack->NumOfPicked = 0;
	_pack->weightOfPicked = 0;
}

int SoftPack(Pack* _pack)
{
	for(int i=0;i<_pack->NumOfItems;i++)
	{
		for(int j=i;j<_pack->NumOfItems;j++)
		{
			if(_pack->Items[j].Weight >_pack->Items[i].Weight)
			{
				Item temp = _pack->Items[j];
				_pack->Items[j] = _pack->Items[i];
				_pack->Items[i] = temp;
				// int Newtemp = _pack->List[j];
				// _pack->List[j] = _pack->List[i];
				// _pack->List[i] = Newtemp;
			}
		}
	}
}

int PickItem(Pack* _pack)
{
	_pack->Picked = (Item*)malloc(_pack->NumOfItems * sizeof(Item));
	int tempMax=0;
	Item pickedItem[10];
	int numOfPicked=0;
	for(int i=0;i<_pack->NumOfItems;i++)
	{
		int pickedWeight = _pack->Items[i].Weight;
		int curPick=i+1;
		Item tempPickedItem[10] = {_pack->Items[i]};
		int tempNumOfPicked = 1;
		//进入时如果没有超重，就往里面加东西
		while (curPick<_pack->NumOfItems)
		{
			if(pickedWeight > _pack->MaxWeight)
			{
				//超重，减去最近加进去的物品
				pickedWeight -= _pack->Items[curPick-1].Weight;
				tempNumOfPicked--;
				curPick++;
				// break;
			}
			pickedWeight += _pack->Items[curPick].Weight;
			tempPickedItem[tempNumOfPicked++] = _pack->Items[curPick++];
		}
		if (pickedWeight > _pack->MaxWeight)
		{
			//超重，减去最近加进去的物品
			pickedWeight -= _pack->Items[--curPick].Weight;
			tempNumOfPicked--;
		}
		if(pickedWeight>tempMax)
		{
			tempMax = pickedWeight;
			numOfPicked = tempNumOfPicked;
			for(int i=0;i< numOfPicked;i++)
			{
				_pack->Picked[i] = tempPickedItem[i];
			}
		}
	}
	_pack->NumOfPicked = numOfPicked;
	for (int i = 0; i < _pack->NumOfPicked; i++)
	{
		pickedItem[i] = pickedItem[i];
	}
	_pack->weightOfPicked = tempMax;
}

void ShowPack(Pack _pack)
{
	for(int i=0;i<_pack.NumOfItems;i++)
	{
		printf("[%d]:%d\n", _pack.Items[i].Num, _pack.Items[i].Weight);
	}
}

void ShowPicked(Pack _pack)
{
	for (int i = 0; i < _pack.NumOfPicked; i++)
	{
		printf("[%d]:%d\n", _pack.Picked[i].Num, _pack.Picked[i].Weight);
	}
	printf("Total weight:%d\n", _pack.weightOfPicked);
}

int main()
{
	Pack pack;
	GeneratePack(&pack,100, 10);
	ShowPack(pack);
	printf("\n");
	SoftPack(&pack);
	ShowPack(pack);
	PickItem(&pack);
	printf("\n");
	ShowPicked(pack);
	
}