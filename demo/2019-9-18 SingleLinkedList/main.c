#include  <stdio.h>
#include  <stdlib.h>
#include  "SingleLinkedList.h"

int main()
{
	SingleLinkList *test;
	test = GenerateLinkList(20);
	ReadWholeLinkListData(test);
	free(test);
	return 0;
}