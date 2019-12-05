//
// Created by HkingAuditore on 2019/10/12.
//
#include <stdlib.h>
#include <stdio.h>
#include "String.h"

//获取相同信息
int *SoftTarget(String *_target) {
    int *info = (int *) calloc(_target->Length, sizeof(int));
    int judgePos = 0;
    for (int i = 1; i < _target->Length; ++i) {
        if (_target->Data[i] == _target->Data[judgePos]) {
            info[i] = judgePos + 1;
            judgePos++;
            continue;
        }
        if (_target->Data[i] != _target->Data[judgePos] && judgePos != 0) {
            judgePos = info[judgePos - 1];
            i--;
            continue;
        }
    }
    _target->Info = info;

    //    printf("QuitSoft!");
    return 0;
}

// 回溯至最近标记处
int Return2Nearest(String _target, int _curPos) {
    // for (int i = _curPos - 1; i >= 0; i--) {
    //     if (_target.Info[i] == 1) {
    //         return i;
    //     }
    // }
    return _target.Info[_curPos-1];
}

// 比较
int Compare(String _origin, String _target) {
    int curPos = 0;
    for (int i = 0; i < _origin.Length;) {
        // printf("%d turn in len %d\n", i, _origin.Length);
        printf("%d turn:Compare %c with %c[%d]\n", i, _origin.Data[i], _target.Data[curPos], curPos);
        if (_target.Data[curPos] == _origin.Data[i]) {
            // 完全匹配
            if (curPos == _target.Length - 1) {
                return i + 1;
            }
            curPos++;
            i++;
            continue;
        } else {
            if (i == _origin.Length - 1) {
                return -1;
            }
            if (curPos == _target.Info[curPos]) {
                i++;
                continue;
            }
            curPos = Return2Nearest(_target, curPos);
            continue;
        }
    }
}

int KMPSearch(char *_origin, char *_target) {
    // printf("IN KMP!\n");
    String *origin = GenerateString(_origin);
    String *target = GenerateString(_target);

    SoftTarget(target);
    WriteInfo(*target);
    int final = Compare(*origin, *target);
    int temp = target->Length;
    DestroyString(origin);
    DestroyString(target);
    return (final) != -1 ? (final - temp) : -1;
}

int main() {
    char origin[100] = "aabaabacaabaabaabaabacaabaabaabacb";
    char target[100] = "aabaabacb";
    // String *str = GenerateString(target);
    // SoftTarget(str);
    // WriteInfo(*str);
    int result = KMPSearch(origin, target);
    if (result != -1) {
        printf("---------At %d------\n", result);
    } else {
        printf("No match!\n");
    }
}