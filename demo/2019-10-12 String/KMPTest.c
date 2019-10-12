//
// Created by HkingAuditore on 2019/10/12.
//
#include <stdlib.h>
#include <stdio.h>
#include "String.h"

//获取相同信息
int *SoftTarget(String *_target) {
//    printf("In SOFT!\n");
    printf("SOFT:%s\n",_target->Data);
    int *info = (int *)calloc(_target->Length, sizeof(int));
    int judgePos = 0;
    for (int i = 1; i < _target->Length; ++i) {
        if (_target->Data[i] == _target->Data[judgePos]) {
            info[i] = judgePos + 1;
            printf("%d:%c same as %d:%c\n",i,_target->Data[i],judgePos,_target->Data[judgePos]);
            judgePos++;
            continue;
        }
        if (_target->Data[i] != _target->Data[judgePos] && judgePos != 0) {
            judgePos = 0;
        }
    }
    _target->Info=info;
//    printf("QuitSoft!");
    return 0;
}



int main(){
    String* str = GenerateString("abcdefgabcdssabcdefjsdabcs");
    SoftTarget(str);
    WriteInfo(*str);
}