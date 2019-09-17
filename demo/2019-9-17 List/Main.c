#include <stdio.h>
#include "ListBase.h"

int main(){
	printf("Start!\n");
	List test;
	ListEnum num;
	InitList(&test,100);
	scanf("%d", &num);
	AddEnumToList(&test, num);
	scanf("%d", &num);
	AddEnumToList(&test, num);
	scanf("%d", &num);
	AddEnumToList(&test, num);
	PrintList(&test);
	RemoveEnumFromList(&test, 1);
	PrintList(&test);
}



