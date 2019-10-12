//
// Created by HkingAuditore 2019/10/12.
//

#ifndef C_LAB_STRING_H
#define C_LAB_STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct string {
    char *Data;
    int Length;
    int *Info;
} String;

String *GenerateString(char *_data) {
//    printf("IN!");
    String *str = (String *) malloc(sizeof(String));
    str->Data = (char *) malloc(sizeof(char) * (strlen(_data)+1));
    for (int i = 0; i < (int) strlen(_data); ++i) {
        str->Data[i] = _data[i];
    }
    str->Data[strlen(_data)]='\0';
    str->Length=strlen(_data);
//    printf("OUT!");
    return str;
}

int WriteString(String _string) {
//    printf("In write!\n");
    puts(_string.Data);
}

int WriteInfo(String _string) {
    for (int i = 0; i < _string.Length; ++i) {
        printf("%d ", _string.Info[i]);
    }
    printf("\n");
}

#endif //C_LAB_STRING_H
