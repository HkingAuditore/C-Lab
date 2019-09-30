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

}Pack;

int GeneratePack(Pack* _pack, int _maxWeight, int _numOfItem)
{
	SetRandSeed();
	_pack->Items = (Item*)malloc(_numOfItem * sizeof(Item));
	// _pack->List = (int*)malloc(_numOfItem * sizeof(int));
	for(int i=0;i< _numOfItem;i++)
	{
		_pack->Items[i].Weight = GetPowerNumber(_maxWeight);
		_pack->Items[i].Num = i;
	}
	_pack->NumOfItems = _numOfItem;
	_pack->MaxWeight = _maxWeight;
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
	for(int i=0;i<_pack->NumOfItems;i++)
	{
		
	}
}

void ShowPack(Pack _pack)
{
	for(int i=0;i<_pack.NumOfItems;i++)
	{
		printf("[%d]:%d\n", _pack.Items[i].Num, _pack.Items[i]);
	}
}

int main()
{
	Pack pack;
	GeneratePack(&pack,100, 10);
	ShowPack(pack);
	printf("\n");
	SoftPack(&pack);
	ShowPack(pack);

	
}