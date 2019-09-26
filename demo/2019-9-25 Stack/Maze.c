///////头文件/////////
#include "ViewManager.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
///////头文件/////////


//////////预定义/////////
#define MAPSIZE 9

///////预定义/////////



//////类型//////
//地点形态
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

//////类型//////


///////////预定义///////////
//基本朝向
Vector2 forward		= { 1,0 };
Vector2 backward	= { -1,0 };
Vector2 leftward	= { 0,1 };
Vector2 rightward	= { 0,-1 };
Vector2 stay		= { 0,0 };
///////////预定义///////////



////////////方法////////////
//创建一个只有墙的地图
Point** CreateEmptyMap()
{

	//生成空地图
	Point** map = (Point**)calloc(MAPSIZE, sizeof(Point*));
	for(int i=0;i<MAPSIZE;i++)
	{
		map[i] = (Point*)calloc(MAPSIZE, sizeof(Point));
	}
	//给周围铺路
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
//根据向量计算下一位置
Transform Transforming(Transform _position,Vector2 _dir)
{
	Transform result = { _position.x + _dir.x,_position.y + _dir.y };
	return result;
}


//挖路
int BuildRoad(Point** _map,Vector2 _dir,Transform _position,Point _avoid)
{
	Transform target = Transforming(_position, _dir);
	if(	_map[Transforming(target,leftward).x][Transforming(target,leftward).y] != road 	)
	{
		
	}
}


//生成迷宫主路
int SetMazeMainRoute(Maze* _maze,int _complexity)
{
	SetRandSeed();
	Transform init = { GetPowerNumber(MAPSIZE),GetPowerNumber(MAPSIZE)};
	_maze->Map[init.x][init.y] = entryDoor;
	_maze->Init = init;
	
}