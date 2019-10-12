//
// Created by HkingAuditore on 2019/10/12.
//
#include <stdlib.h>
#include <stdio.h>
#include "String.h"

//获取相同信息
int *SoftTarget(String *_target)
{
    // printf("In SOFT!\n");
    // printf("SOFT:%s\n", _target->Data);
    int *info = (int *)calloc(_target->Length, sizeof(int));
    int judgePos = 0;
    for (int i = 1; i < _target->Length; ++i)
    {
        if (_target->Data[i] == _target->Data[judgePos])
        {
            info[i] = judgePos + 1;
            // printf("%d:%c same as %d:%c\n", i, _target->Data[i], judgePos, _target->Data[judgePos]);
            judgePos++;
            continue;
        }
        if (_target->Data[i] != _target->Data[judgePos] && judgePos != 0)
        {
            judgePos = 0;
        }
    }
    _target->Info = info;
    //    printf("QuitSoft!");
    return 0;
}

// 回溯至最近标记处
int Return2Nearest(String _target, int _curPos)
{
    for (int i = _curPos; i >= 0; i--)
    {
        if (_target.Info[i] == 1)
        {
            return i;
        }
    }
    return 0;
}

// 比较
int Compare(String _origin, String _target)
{
    int curPos = 0;
    for (int i = 0; i < _origin.Length;)
    {
        // printf("%d turn in len %d\n", i, _origin.Length);
        printf("%d turn:Compare %c with %c\n", i, _origin.Data[i], _target.Data[curPos]);
        if (_target.Data[curPos] == _origin.Data[i])
        {
            // 完全匹配
            if (curPos == _target.Length - 1)
            {
                return i + 1;
            }
            curPos++;
            i++;
            continue;
        }
        else
        {
            if (i == _origin.Length - 1)
            {
                // printf("not found quit!\n");
                return -1;
            }
            if (curPos == 0)
            {
                i++;
                continue;
            }
            curPos = Return2Nearest(_target, curPos);
            continue;
        }
    }
}

int KMPSearch(char *_origin, char *_target)
{
    // printf("IN KMP!\n");
    String *origin = GenerateString(_origin);
    String *target = GenerateString(_target);

    SoftTarget(target);
    // WriteInfo(*target);
    int final = Compare(*origin, *target);
    int temp = target->Length;
    DestroyString(origin);
    DestroyString(target);
    return (final) != -1 ? (final - temp) : -1;
}

int main()
{
    char origin[100] = "YouAreAAsslessAssassin!";
    char target[100] = "Assassin";
    int result = KMPSearch(origin, target);
    if (result != -1)
    {
        printf("---------At %d------\n", result);
    }
    else
    {
        printf("No match!\n");
    }
}