//
// Created by HkingAuditore on 2019/11/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "UnionFind.h"
//#include "BinaryTreeTraversal.h"

int main(){
    Forest forestTest = GenerateForest();
    for (int i = 0; i <5 ; ++i) {
        InteractiveLinkChild(&forestTest);
    }
//    InteractiveLinkChild(&forestTest);
//    InteractiveLinkChild(&forestTest);
//    InteractiveLinkChild(&forestTest);
    TraversalForest(forestTest);

}