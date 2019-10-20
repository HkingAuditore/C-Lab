//
// Created by HkignAuditore on 2019/10/17.
//

#ifndef C_LAB_ARRAYBASE_H
#define C_LAB_ARRAYBASE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

typedef int SingleType;
typedef struct enumType {
    SingleType Data;
    int NumOfDimension;
    int NumOfComponent;
} EnumType;
//typedef int EnumType;
typedef EnumType *EnumSet;

typedef struct array {
    EnumSet *Data;
    int Dimension;
    int NumOfEnum;
    int *Component;
} Array;

Array *GenerateArray(int _dimension, int _component, ...) {
    Array *array = (Array *) calloc(1, sizeof(Array));
    array->Dimension = _dimension;
    array->Data = (EnumSet *) malloc(_dimension * sizeof(EnumSet));
    array->Component = (int *) malloc(_dimension * sizeof(int));
    int numOfEnum = 0;
    va_list component;
    va_start(component, _component);
    for (int i = 0; i < _dimension; ++i) {
        int tempComponent = va_arg(component, int);
        array->Component[i] = tempComponent;
        array->Data[i] = (EnumType *) malloc(tempComponent * sizeof(EnumType));
        numOfEnum += tempComponent;
        for (int j = 0; j < tempComponent; ++j) {
            array->Data[i][j].NumOfDimension = i;
            array->Data[i][j].NumOfComponent = j;
        }
    }
    va_end(component);
    array->NumOfEnum = numOfEnum;
    return array;

}

void ArrayDataGenerate(Array *_array, SingleType _data, ...) {
    va_list data;
    va_start(data, _data);
    for (int i = 0; i < _array->Dimension; ++i) {
        for (int j = 0; j < _array->Component[i]; ++j) {
            _array->Data[i][j].Data = va_arg(data, int);
        }
    }
    va_end(data);
}


void WriteArray(Array _array) {
    printf("Num of enum:%d\nNum of dimension:%d\n", _array.NumOfEnum, _array.Dimension);
    for (int i = 0; i < _array.Dimension; ++i) {
        for (int j = 0; j < _array.Component[i]; ++j) {
            printf("%d-%d:%d\n", _array.Data[i][j].NumOfDimension, _array.Data[i][j].NumOfComponent,
                   _array.Data[i][j].Data);
        }
    }
}


#endif //C_LAB_ARRAYBASE_H
