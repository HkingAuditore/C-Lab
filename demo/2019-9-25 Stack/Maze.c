///////头文件/////////
#include "ViewManager.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
///////头文件/////////


//////////预定义/////////
#define MAPSIZE 30

///////预定义/////////



//////类型//////
//地点形态
typedef enum point{
	wall=0, road, entryDoor, exitDoor,solution,border
}Point;

char _Material[20][20] = {"█","  ","Ｉ","Ｅ","●","※"};

typedef struct vector2{
	int x;
	int y;
}Vector2;

typedef  Vector2 Position;
typedef  Vector2 Rotation;
typedef  Point** Map;

typedef struct maze{
	Point** Map;
	int		SizeOfMap;
	Position Init;
	Position End;
}Maze;





//////类型//////


///////////预定义///////////
//基本朝向
Vector2 _Forward		= { 1,0 };
Vector2 _Backward		= { -1,0 };
Vector2 _Leftward		= { 0,1 };
Vector2 _Rightward		= { 0,-1 };
Vector2 _Stay			= { 0,0 };

//顺时针旋转
typedef enum direction {
	forward = 0, rightward, backward, leftward
}Direction;

typedef enum turn {
	staying = 0, turnRight = 1, turnARound = 2, turnLeft = -1
}Turn;

Vector2 _Direction[4] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

//坐标
typedef struct transform {
	Position Pos;
	Direction Dir;
}Transform;

//路径点集合
typedef struct pointArray
{
	Position Array[MAPSIZE*MAPSIZE];
	int Num;
}PointArray;

PointArray _Roads;
///////////预定义///////////



////////////方法////////////

/*Position/Vector计算类*/


//向量乘法
Vector2 VectorMult(int _coefficient,Vector2 _vector)
{
	Vector2 result = {_coefficient*_vector.x,_coefficient*_vector.y};
	return  result;
}

//向量加法
Vector2 VectorAddition(Vector2 _v1, Vector2 _v2)
{
	Vector2 result = { _v1.x + _v2.x,_v1.y + _v2.y };
	return result;
}

//获取坐标的地形
Point GetPositionPoint(Map _map,Position _position)
{
	return (_map[_position.x][_position.y]);
}
//获取反方向
Direction ReversedDiretion(Direction _dir)
{
	Direction result = _dir+=2;
	if (_dir > 3)
	{
		_dir -= 4;
	}
}


//转向
void Rotate(Transform *_transform,Turn _dir)
{
	_transform->Dir += _dir;
	if(_transform->Dir >3)
	{
		_transform->Dir -= 4;
	}
}



//沿朝向移动
Position MoveInDirection(Transform _transform,int _distance)
{
	Position result = VectorAddition(_transform.Pos, VectorMult(_distance, _Direction[_transform.Dir]));
	return result;
}




/*Position/Vector计算类*/
//迷宫渲染器
int MazeRenderer(Maze _maze)
{
	for (int i = 0; i < _maze.SizeOfMap; i++)
	{
		for (int j = 0; j < _maze.SizeOfMap; j++)
		{
			printf("%s", _Material[_maze.Map[i][j]]);
		}
		printf("\n");
	}
	return 0;
}

//创建一个只有墙的地图
Map CreateEmptyMap(int _sizeOfMap)
{
	// printf("IN 0!\n");
	//生成空地图
	Map map = (Map)calloc(_sizeOfMap, sizeof(Point*));
	for(int i=0;i<_sizeOfMap;i++)
	{
		map[i] = (Point*)calloc(_sizeOfMap, sizeof(Point));
	}
	// printf("IN 1!\n");
	//给周围铺路
	for(int i=0;i<_sizeOfMap;i++)
	{
		if(i==0 || i==_sizeOfMap-1)
		{
			for(int j=0;j<_sizeOfMap;j++)
			{
				map[i][j] = border;
			}
		}else
		{
			map[i][0] = border;
			map[i][_sizeOfMap - 1] = border;
		}
	}
	return map;
}


//挖路
int BuildRoad(Map _map,Transform *_transform)
{
	Transform target = { MoveInDirection(*_transform,1),_transform->Dir };
	Rotate(&target, turnLeft);
	for(int i=0;i<3;i++)
	{
		if(GetPositionPoint(_map,MoveInDirection(target,1)) == road || (GetPositionPoint(_map, MoveInDirection(target, 1)) == border))
		{
			return 1;
		}
		Rotate(&target, turnRight);
	}

	_map[target.Pos.x][target.Pos.y] = road;
	_Roads.Array[_Roads.Num++] = target.Pos;
	_transform->Pos = target.Pos;
	return  0;
}
//挖主路
int BuildMainRoad(Map _map,Transform *_transform)
{
	Transform target = { MoveInDirection(*_transform,1),_transform->Dir };
	//Rotate(&target, turnLeft);
	// for(int i=0;i<3;i++)
	// {
	// 	if(GetPositionPoint(_map,MoveInDirection(target,1)) == road)
	// 	{
	// 		return 1;
	// 	}
	// 	Rotate(&target, turnRight);
	// }

	_map[target.Pos.x][target.Pos.y] = road;
	_Roads.Array[_Roads.Num++] = target.Pos;
	_transform->Pos = target.Pos;
	printf("buid!\n");
	return  0;
}


//生成迷宫主路
int SetMazeMainRoute(Maze* _maze,int _minDistance,int _maxDistance)
{
	SetRandSeed();
	int tempMin = 1.2*_minDistance;
	int tempMax = 1.5*_maxDistance;
	int side = GetPowerNumber(4);
	Position init = { (_maze->SizeOfMap) / 3+GetPowerNumber((_maze->SizeOfMap)/3),(_maze->SizeOfMap) / 3 + GetPowerNumber((_maze->SizeOfMap) / 3) };
	Direction initDir;
	//随机入口的边
	switch (side)
	{
	case 0:
		init.x = 0;
		initDir = forward;
		break;
	case 1:
		init.x = _maze->SizeOfMap - 1;
		initDir = backward;
		break;
	case 2:
		init.y = 0;
		initDir = rightward;
		break;
	case 3:
		init.y = _maze->SizeOfMap - 1;
		initDir = leftward;
		break;
	}
	_maze->Map[init.x][init.y] = entryDoor;
	_maze->Init = init;
	// printf("IN!");
	//生成一个工人开挖道路
	Transform worker = { _maze->Init,initDir };
	BuildRoad(_maze->Map, &worker);

	while (GetPositionPoint(_maze->Map,worker.Pos) != border)
	{
		// printf("NOW TURN %d\n", worker.Dir);
		//如果走了反方向就减少反向行进距离
		tempMax = _maxDistance;
		tempMin = _minDistance;
		if(worker.Dir == ReversedDiretion(initDir))
		{
			tempMax /= 3;
			tempMin /= 3;
		}
		for(int i=0;i< (_minDistance+GetPowerNumber(tempMax - tempMin));i++)
		{
			//如果下一格就挖到边界说明已经到出口
			if(GetPositionPoint(_maze->Map,MoveInDirection(worker,1)) == border)
			{
				worker.Pos = MoveInDirection(worker, 1);
				break;
			}
			//如果要接上就转向
			if(BuildMainRoad(_maze->Map, &worker))
			{
				Rotate(&worker, turnRight);
				i--;
			}
			// printf("now at(%d,%d),point is %d\n", worker.Pos.x, worker.Pos.y,GetPositionPoint(_maze->Map,worker.Pos));
			// MazeRenderer(*_maze);
		}
		Turn turnDir = (Turn)GetPowerNumber(4);
		if (turnDir == turnARound)
		{
			turnDir = initDir;
		}
		Rotate(&worker, turnDir);
	}
	_maze->Map[worker.Pos.x][worker.Pos.y] = exitDoor;
}


//
int GenerateMaze(Maze* _maze, int _sizeOfMap)
{
	_maze->SizeOfMap = _sizeOfMap;
	_maze->Map = CreateEmptyMap(_maze->SizeOfMap);
	return 0;
}

//一条支路
int SetMazeABranch(Maze* _maze, int _numOfBrance, int _minDistance, int _maxDistance) {
	int pos = GetPowerNumber(_Roads.Num);
	Transform worker = { _Roads.Array[pos],GetPowerNumber(3) };
	int tempMax = _maxDistance;
	int tempMin = _minDistance;
	Direction initDir = GetPowerNumber(4);
	while (GetPositionPoint(_maze->Map, worker.Pos) != border)
	{
		// printf("NOW TURN %d\n", worker.Dir);
		//如果走了反方向就减少反向行进距离
		tempMax = _maxDistance;
		tempMin = _minDistance;
		if (worker.Dir == ReversedDiretion(initDir))
		{
			tempMax /= 3;
			tempMin /= 3;
		}
		for (int i = 0; i < (_minDistance + GetPowerNumber(tempMax - tempMin)); i++)
		{
			//如果要接上就停止
			if (BuildRoad(_maze->Map, &worker))
			{
				return i;
			}
			// printf("now at(%d,%d),point is %d\n", worker.Pos.x, worker.Pos.y, GetPositionPoint(_maze->Map, worker.Pos));
			// MazeRenderer(*_maze);
		}
		Turn turnDir = (Turn)GetPowerNumber(4);
		if (turnDir == turnARound)
		{
			turnDir = initDir;
		}
		Rotate(&worker, turnDir);
	}
}

//开挖支路
int SetMazeBranch(Maze* _maze,int _numOfBrance, int _minDistance, int _maxDistance)
{
	printf("IN! BRANCH!");
	for (int i=0;i<_numOfBrance;i++)
	{
		if(SetMazeABranch(_maze, _numOfBrance, _minDistance, _maxDistance) < 1)
		{
			i--;
		}

	}

}


int main()
{
	Maze test;
	_Roads.Num = 0;
	GenerateMaze(&test, MAPSIZE);
	SetMazeMainRoute(&test,3,6);
	printf("done\n");
	MazeRenderer(test);
	SetMazeBranch(&test, 5000, 3, 8);
	printf("ALL done\n");
	MazeRenderer(test);
	
}