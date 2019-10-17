//
// Created by HkingAuditore on 2019/10/17.
//

#ifndef C_LAB_MATRIXBASE_H
#define C_LAB_MATRIXBASE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ArrayBase.h"

typedef struct matrixEnum {
    int i;
    int j;
    int Data;
} MatrixEnum;

typedef struct matrix {
    MatrixEnum *Data;
    int Row;
    int Column;
} Matrix;

Matrix* GenerateMatrix(int _row, int _column,int _data,...) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->Data = (MatrixEnum *) calloc(_row * _column, sizeof(MatrixEnum));
    matrix->Column=_column;
    matrix->Row=_row;
    va_list data;
    va_start(data, _data);
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            matrix->Data[_column * i + j].Data = va_arg(data,int);
            matrix->Data[_column * i + j].j = j;
            matrix->Data[_column * i + j].i = i;
        }
    }
    va_end(data);
    return matrix;

}

int WriteMatrix(Matrix _matrix){
    for (int i = 0; i <_matrix.Row ; ++i) {
        for (int j = 0; j <_matrix.Column ; ++j) {
            printf("%d ",_matrix.Data[i*_matrix.Column+j].Data);
        }
        printf("\n");
    }
}


#endif //C_LAB_MATRIXBASE_H
