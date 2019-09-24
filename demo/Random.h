#pragma once
#include  <stdio.h>
#include  <stdlib.h>
#include <time.h>

static int GetRandom(int _min,int _max)
{
	return (_min + rand() % (_max-_min));
}
