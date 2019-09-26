//////////////////////////ͷ�ļ�//////////////////////////////
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define FOV 9

//TODOCLAB#0 �ϴ���,Ҫ�ع�
//////////////////////////ͷ�ļ�//////////////////////////////
//////////////////////////����///////////////////////////////
///��ɫ
typedef enum Color
{
	black = 30, red, green, yellow, blue, purple, deepgreen, white
}color;

//��ͼ��ɫ
color _MapColorCol[20] = { white , green,yellow,red,white };

//����
char _CNNameOfMapPoint[20][20] = { "·" ,"ǽ","��","��" };
char _ENNameOfMapPoint[20] = "WRDS";

//��Ұ
int  _NumOfView = 9;
int  _NumOfColView = 3;
//////////////////////////����///////////////////////////////

/////////////////////////����////////////////////////////////

/************��������***************/
//�������ȡ
static int GetRandNumber() {
	//srand((unsigned)time(NULL));
	int randnum = rand();
	return randnum;
}

//��ȡȨ�������
static int GetPowerNumber(int _power) {
	int randNum = GetRandNumber() % (_power);
	return randNum;
}

//�趨�������
static int SetRandSeed() {
	srand((unsigned)time(NULL));
	return 1;
}

//�����ַ���
static char* GetString(char* _input, int _max) {
	char* temp;
	int i = 0;
	temp = fgets(_input, _max, stdin);
	if (temp) {
		while (_input[i] != '\n' && _input[i] != '\0')
		{
			i++;
		}
		if (_input[i] == '\n') {
			_input[i] = '\0';
		}
		else {
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	return temp;
}

//int�������
static int SumCol(const int *_target, int _numOfTarget) {
	int sum = 0;
	for (int i = 0; i < _numOfTarget; i++) {
		sum += _target[i];
	}
	return sum;
}

//�ַ�ת����
static int CharToInt(char _char) {
	int result = _char - '0';

	return result;
}

//������ȡ��
static int GetPowerResult(int _num, int _col[]) {
	int result;
	int *stageSumOfPower = (int*)malloc(_num * sizeof(int));
	if (!*stageSumOfPower)
		return -1;
	for (int i = 0; i < _num; i++) {
		stageSumOfPower[i] = SumCol(_col, i + 1);
	}

	int tempRandom = GetPowerNumber(stageSumOfPower[_num - 1]);
	for (int i = 0; i < _num; i++) {
		if (tempRandom <= stageSumOfPower[i]) {
			result = i;
			break;
		}
	}
	return result;
	free(stageSumOfPower);
}

/************��������***************/
/************��ʾ���***************/

//��ͼ����ת��ɫֵ
static color ChooseMapPointColor(int _typeOfMapPoint) {
	return _MapColorCol[_typeOfMapPoint];
}

//��ͼ����ת�����ַ�
static char GetMapPointName(int _typeOfMapPoint) {
	return  _ENNameOfMapPoint[_typeOfMapPoint];
}

//\033[1;%dm����������������\033[m
//�����ͼ��Ⱦ��
static int DrawMapPiece(int _typeOfMapPoint0, int _typeOfMapPoint1, int _typeOfMapPoint2, int _isPlayer) {
	color	mapPoint0Color = ChooseMapPointColor(_typeOfMapPoint0),
			mapPoint1Color = ChooseMapPointColor(_typeOfMapPoint1),
			mapPoint2Color = ChooseMapPointColor(_typeOfMapPoint2);

	char	mapPoint0Name = GetMapPointName(_typeOfMapPoint0),
			mapPoint1Name = GetMapPointName(_typeOfMapPoint1),
			mapPoint2Name = GetMapPointName(_typeOfMapPoint2);
	if (_isPlayer == 1)mapPoint1Color = purple;
	printf("\033[1;%dm����������������\033[m\033[1;%dm����������������\033[m\033[1;%dm����������������\033[m\n", mapPoint0Color, mapPoint1Color, mapPoint2Color);
	printf("\033[1;%dm��  %c   ��\033[m\033[1;%dm��  %c   ��\033[m\033[1;%dm��  %c   ��\033[m\n", mapPoint0Color, mapPoint0Name, mapPoint1Color, mapPoint1Name, mapPoint2Color, mapPoint2Name);
	printf("\033[1;%dm����������������\033[m\033[1;%dm����������������\033[m\033[1;%dm����������������\033[m\n", mapPoint0Color, mapPoint1Color, mapPoint2Color);

	return 1;
}
//0 1 2 /0
//3 4 5 /1
//6 7 8 /2
//��ͼ��Ⱦ��
static int MapRenderer(int _mapInView[FOV]) {
	for (int i = 0; i < _NumOfColView; i++) {
		if (i == 1) {
			DrawMapPiece(_mapInView[ (int)sqrt(FOV)* i], _mapInView[(int)sqrt(FOV) * i + 1], _mapInView[(int)sqrt(FOV) * i + 2], 1);
		}
		else {
			DrawMapPiece(_mapInView[(int)sqrt(FOV) * i], _mapInView[(int)sqrt(FOV) * i + 1], _mapInView[(int)sqrt(FOV) * i + 2], 0);

		}
	}
	return 1;
}

/************��ʾ���***************/