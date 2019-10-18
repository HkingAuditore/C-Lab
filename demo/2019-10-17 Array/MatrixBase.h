//
// Created by HkingAuditore on 2019/10/17.
//

#ifndef C_LAB_MATRIXBASE_H
#define C_LAB_MATRIXBASE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
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

typedef struct matrixStorage {
    int *Data;
    int Num;
} MatrixStorage;

Matrix *GenerateMatrix(int _row, int _column, int _data, ...) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->Data = (MatrixEnum *) calloc(_row * _column, sizeof(MatrixEnum));
    matrix->Column = _column;
    matrix->Row = _row;
    va_list data;
    va_start(data, _data);
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _column; ++j) {
            matrix->Data[_column * i + j].Data = va_arg(data, int);
            matrix->Data[_column * i + j].j = j + 1;
            matrix->Data[_column * i + j].i = i + 1;
        }
    }
    va_end(data);
    return matrix;

}

int WriteMatrix(Matrix _matrix) {
    for (int i = 0; i < _matrix.Row; ++i) {
        for (int j = 0; j < _matrix.Column; ++j) {
            printf("%d ", _matrix.Data[i * _matrix.Column + j].Data);
        }
        printf("\n");
    }
}

int IsTriangleMatrix(Matrix _matrix) {
    if (_matrix.Row != _matrix.Column) {
        return 0;
    }
    for (int i = 0; i < _matrix.Row; ++i) {
        for (int j = i + 1; j < _matrix.Column; ++j) {
            if (_matrix.Data[_matrix.Column * i + j].Data != 0) {
                return 0;
            }
        }
    }
    return 1;
}

MatrixStorage *SaveTriangle(Matrix _matrix) {
    int numOfEle = (1 + _matrix.Row) * (_matrix.Row) / 2;
    MatrixStorage *storage = (MatrixStorage *) calloc(1, sizeof(MatrixStorage));
    storage->Data = (int *) calloc(numOfEle, sizeof(int));
    for (int i = 1; i <= _matrix.Row; ++i) {
        for (int j = 1; j <= i; ++j) {
            storage->Data[((i - 1) * i / 2) + j - 1] = _matrix.Data[(_matrix.Column * (i - 1)) + j - 1].Data;
        }
    }
    storage->Num = numOfEle;
    return storage;
}

Matrix *ReadTriangle(MatrixStorage _storage) {
    Matrix *matrix = (Matrix *) calloc(1, sizeof(Matrix));
    int column = (int) (sqrt(2.0 * _storage.Num + 1.0 / 4) - 1.0 / 2);
    matrix->Data = (MatrixEnum *) calloc(column * column, sizeof(MatrixEnum));
    matrix->Column = matrix->Row = column;
    for (int i = 1; i <= matrix->Row; ++i) {
        for (int j = 1; j <= matrix->Column; ++j) {
            if (j <= i) {
                matrix->Data[(i - 1) * column + j - 1].Data = _storage.Data[((i - 1) * i / 2) + j - 1];
            }
            matrix->Data[(i - 1) * column + j - 1].i = i;
            matrix->Data[(i - 1) * column + j - 1].j = j;
        }
    }
    return matrix;
}

#endif //C_LAB_MATRIXBASE_H
