//
// Created by HkingAuditore on 2019/10/11.
//

#ifndef C_LAB_SYSTEMBASE_H
#define C_LAB_SYSTEMBASE_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//随机种子
static void InitRandSeed(){
    srand((unsigned)time(NULL));
}

//获取随机数
static int GetRandom(int _max) {
    return rand()%(_max+1);
}
#endif //C_LAB_SYSTEMBASE_H
