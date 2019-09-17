#include <stdio.h>
#include "ListBase.h"

int main(){
	printf("YES!");
	List test;
	InitList(&test,100);
	GenerateList(&test);
	PrintList(&test);
}



