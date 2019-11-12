//
// Created by HkingAuditore on 2019/10/17.
//

#include "ArrayBase.h"
#include "MatrixBase.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Matrix* matrix =GenerateMatrix(3,3,9,1,0,0,2,3,0,4,5,6);
    WriteMatrix(*matrix);
    printf("Is %c Triangle\n",IsTriangleMatrix(*matrix)?' ':'n');
    printf("-------------------\n");
    MatrixStorage* storage= SaveTriangle(*matrix);
    for (int i = 0; i < storage->Num; ++i) {
        printf("%d:%d\n",i,storage->Data[i]);
    }
    printf("-------------------\n");
    Matrix* ReReadMatrix = ReadTriangle(*storage);
    WriteMatrix(*ReReadMatrix);
}