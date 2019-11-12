
// Created by HkingAuditore on 2019/10/20.


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "ArrayBase.h"

int main(){
    Array* array=GenerateArray(4,4,1,2,1,3);
//    WriteArray(*array);
    ArrayDataGenerate(array,7,1999,11,23,178854663,136,4014,5961);
    WriteArray(*array);
}