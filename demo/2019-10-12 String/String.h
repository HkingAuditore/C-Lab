//
// Created by HkingAuditore 2019/10/12.
//

#ifndef C_LAB_STRING_H
#define C_LAB_STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct string
{
    char *Data;
    int Length;
    int *Info;
} String;

String *GenerateString(char *_data)
{
    // printf("IN generate!\n");
    String *str = (String *)calloc(1, sizeof(String));
    // printf("IN generate!*2\n");
    str->Data = (char *)calloc((strlen(_data) + 10), sizeof(char));
    // printf("IN generate!*3\n");
    for (int i = 0; i < (int)strlen(_data); ++i)
    {
        // printf("now put %c\n", _data[i]);
        str->Data[i] = _data[i];
    }
    str->Data[strlen(_data) + 1] = '\0';
    str->Length = (int)strlen(_data);
    //    printf("OUT!");
    return str;
}

int WriteString(String _str)
{
    //    printf("In write!\n");
    puts(_str.Data);
}

int WriteInfo(String _str)
{
    for (int i = 0; i < _str.Length; ++i)
    {
        printf("%d ", _str.Info[i]);
    }
    printf("\n");
}

int DestroyString(String *_str)
{
    free(_str->Data);
    free(_str->Info);
    free(_str);
    return 0;
}
#endif //C_LAB_STRING_H
