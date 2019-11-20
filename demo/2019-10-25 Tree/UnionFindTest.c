//
// Created by HkingAuditore on 2019/11/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "UnionFind.h"

int main(){
    Forest forestTest = GenerateForest();
    for (int i = 0; i <3 ; ++i) {
        NewTreeInForest(&forestTest);
    }
    ShowForest(forestTest);

}