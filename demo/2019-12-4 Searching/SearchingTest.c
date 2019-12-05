//
// Created by HkingAuditore on 2019/12/4.
//

#include <stdio.h>
#include <stdlib.h>
#include "TreeBasic.h"
#include "InputController.h"
#include "OutputController.h"

extern Tree *GenerateSimpleSearchTree();

int main() {
    Tree *tree = GenerateSimpleSearchTree();
    TraversalTree(tree,DLR);
}