///////ͷ�ļ�/////////
#include "ViewManager.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
///////ͷ�ļ�/////////


//////////Ԥ����/////////
#define MAPSIZE 9

///////Ԥ����/////////



//////����//////
//�ص���̬
typedef enum point{
	wall=0, road, entryDoor, exitDoor,solution,outside
}Point;

typedef struct vector2{
	int x;
	int y;
}Vector2;

typedef  Vector2 Transform;

typedef struct maze{
	Point** Map;
	Transform Init;
	Transform End;
}Maze;

//////����//////


///////////Ԥ����///////////
//��������
Vector2 forward		= { 1,0 };
Vector2 backward	= { -1,0 };
Vector2 leftward	= { 0,1 };
Vector2 rightward	= { 0,-1 };
Vector2 stay		= { 0,0 };
///////////Ԥ����///////////



////////////����////////////
//����һ��ֻ��ǽ�ĵ�ͼ
Point** CreateEmptyMap()
{

	//���ɿյ�ͼ
	Point** map = (Point**)calloc(MAPSIZE, sizeof(Point*));
	for(int i=0;i<MAPSIZE;i++)
	{
		map[i] = (Point*)calloc(MAPSIZE, sizeof(Point));
	}
	//����Χ��·
	for(int i=0;i<MAPSIZE;i++)
	{
		if(i==0 || i==MAPSIZE-1)
		{
			for(int j=0;j<MAPSIZE;j++)
			{
				map[i][j] = outside;
			}
		}else
		{
			map[i][0] = outside;
			map[i][MAPSIZE - 1] = outside;
		}
	}
}
//��������������һλ��
Transform Transforming(Transform _position,Vector2 _dir)
{
	Transform result = { _position.x + _dir.x,_position.y + _dir.y };
	return result;
}


//��·
int BuildRoad(Point** _map,Vector2 _dir,Transform _position,Point _avoid)
{
	Transform target = Transforming(_position, _dir);
	if(	_map[Transforming(target,leftward).x][Transforming(target,leftward).y] != road 	)
	{
		
	}
}


//�����Թ���·
int SetMazeMainRoute(Maze* _maze,int _complexity)
{
	SetRandSeed();
	Transform init = { GetPowerNumber(MAPSIZE),GetPowerNumber(MAPSIZE)};
	_maze->Map[init.x][init.y] = entryDoor;
	_maze->Init = init;
	
}