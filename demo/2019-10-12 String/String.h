//
// Created by HkingAuditore 2019/10/12.
//

#ifndef C_LAB_STRING_H
#define C_LAB_STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EXTEND 10

/*声明*/
typedef struct string {
    char *Data;
    int Length;
    int *Info;
} String;

static String *GenerateString(char *_data);

static int Add2String(String *_str, char *_target);

static int Delete(String *_str, int _num);

static int RemoveWords(String *_str, char *_target);

static String LinkStrings(const String *_str0, const String *_str1);

static int WriteString(String _str);

static int WriteInfo(String _str);

static int DestroyString(String *_str);

static int *SoftTarget(String *_target);

static int Return2Nearest(String _target, int _curPos);

static int Compare(String _origin, String _target);

static int KMPSearch(char *_origin, char *_target);

static int Backspace(String *_str, int _pos, int _num);

static int Replace(String *_str, char *_origin,char *_target);

static int Insert(String *_str, int _pos, char *_target);
/*声明*/

//初始化字符串
static String *GenerateString(char *_data) {
    // printf("IN generate!\n");
    String *str = (String *) calloc(1, sizeof(String));
    // printf("IN generate!*2\n");
    str->Data = (char *) calloc((strlen(_data) + 10), sizeof(char));
    // printf("IN generate!*3\n");
    for (int i = 0; i < (int) strlen(_data); ++i) {
        // printf("now put %c\n", _data[i]);
        str->Data[i] = _data[i];
    }
    str->Data[strlen(_data) + 1] = '\0';
    str->Length = (int) strlen(_data);
    //    printf("OUT!");
    return str;
}

//在文本末加入
static int Add2String(String *_str, char *_target) {
    _str->Data = (char *) realloc(_str->Data, sizeof(char) * (strlen(_target) + _str->Length + EXTEND));
    if (_str->Data) {
        for (int i = 0; i < strlen(_target); ++i) {
            _str->Data[strlen(_str->Data)] = _target[i];
        }
        _str->Data[strlen(_str->Data) + 1] = '\0';
        _str->Length = strlen(_str->Data);
        return _str->Length;
    }
    return -1;
}

//在文本末删除
static int Delete(String *_str, int _num) {
    _str->Data[_str->Length - _num] = '\0';
    _str->Length -= _num;
    return _str->Length;
}

//在文本中删除
static int Backspace(String *_str, int _pos, int _num) {
    for (int i = _pos; i < _str->Length; ++i) {
        _str->Data[i] = _str->Data[_num + i];
    }
    _str->Length -= _num;
    _str->Data[_str->Length] = '\0';
    return _str->Length;
}

//插入
static int Insert(String *_str, int _pos, char *_target) {
    int lengthOfWord = strlen(_target);
//    重新分配空间
    _str->Data = (char *) realloc(_str->Data, _str->Length + lengthOfWord + EXTEND * sizeof(char));
//    为新字符空出空间
    for (int i = 0; i <= _str->Length-_pos; ++i) {
//        printf("Transform %c and %c\n",_str->Data[_str->Length+lengthOfWord-i],_str->Data[_str->Length-i]);
        _str->Data[_str->Length+lengthOfWord-i] = _str->Data[_str->Length-i];
    }
    for (int j = 0; j < lengthOfWord; ++j) {
        _str->Data[_pos+j]=_target[j];
    }
    _str->Length+=lengthOfWord;
    _str->Data[_str->Length]='\0';
    return _str->Length;
}

//去除所有匹配项
static int RemoveWords(String *_str, char *_target) {
    int lenOfTarget = strlen(_target);
    int searchResult = 0;
    while ((searchResult = KMPSearch(_str->Data, _target)) != -1) {
        Backspace(_str, searchResult, lenOfTarget);
    }
    return 0;
}

//连接字符串
static String LinkStrings(const String *_str0, const String *_str1) {
}

//打印字符串
static int WriteString(String _str) {
    //    printf("In write!\n");
    puts(_str.Data);
}

//打印字符串的KMP信息
static int WriteInfo(String _str) {
    for (int i = 0; i < _str.Length; ++i) {
        printf("%d ", _str.Info[i]);
    }
    printf("\n");
}

//销毁字符串
static int DestroyString(String *_str) {
    free(_str->Data);
    free(_str->Info);
    free(_str);
    return 0;
}

//替换所有匹配项
static int Replace(String *_str, char *_origin,char *_target) {
    int lenOfTarget = strlen(_target);
    int lenOfOrigin = strlen(_origin);
    int searchResult = 0;
    while ((searchResult = KMPSearch(_str->Data, _origin)) != -1) {
        Backspace(_str, searchResult, lenOfOrigin);
        Insert(_str,searchResult,_target);
    }
    return 0;
}


//获取相同信息
static int *SoftTarget(String *_target) {
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
static int Return2Nearest(String _target, int _curPos) {
    // for (int i = _curPos - 1; i >= 0; i--) {
    //     if (_target.Info[i] == 1) {
    //         return i;
    //     }
    // }
    return _target.Info[_curPos - 1];
}

// 比较
static int Compare(String _origin, String _target) {
    int curPos = 0;
    for (int i = 0; i < _origin.Length;) {
        // printf("%d turn in len %d\n", i, _origin.Length);
//        printf("%d turn:Compare %c with %c[%d]\n", i, _origin.Data[i], _target.Data[curPos], curPos);
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

static int KMPSearch(char *_origin, char *_target) {
    // printf("IN KMP!\n");
    String *origin = GenerateString(_origin);
    String *target = GenerateString(_target);

    SoftTarget(target);
//    WriteInfo(*target);
    int final = Compare(*origin, *target);
    int temp = target->Length;
    DestroyString(origin);
    DestroyString(target);
    return (final) != -1 ? (final - temp) : -1;
}

#endif //C_LAB_STRING_H
