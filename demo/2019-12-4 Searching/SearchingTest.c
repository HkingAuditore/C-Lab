//
// Created by HkingAuditore on 2019/12/4.
//

#include <stdio.h>
#include <stdlib.h>
#include "TreeBasic.h"
#include "InputController.h"
#include "OutputController.h"

extern Tree *GenerateSimpleSearchTree();
extern Tree *GenerateAVLTree();
extern void DeleteNode(Tree *_tree);



int main() {
    setbuf(stdout, 0);
    Tree *tree = GenerateAVLTree();
    TraversalTree(tree, DLR, NodeInfoOutput);
    DeleteNode(tree);
    TraversalTree(tree, DLR, NodeInfoOutput);

}