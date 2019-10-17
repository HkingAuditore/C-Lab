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
}