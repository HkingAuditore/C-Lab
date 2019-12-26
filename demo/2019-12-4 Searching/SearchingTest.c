//
// Created by HkingAuditore on 2019/12/4.
//

#include <stdio.h>
#include <stdlib.h>
#include "TreeBasic.h"
// #include "RedBlackTree.h"
#include "InputController.h"
#include "BalancedBinaryTree.h"
#include "RedBlackTree.h"
#include "OutputController.h"


extern Tree *GenerateSimpleSearchTree();
extern Tree *GenerateAVLTree();
extern void DeleteNode(Tree *_tree);

// extern TreeNode* _NIL;

int main() {
    setbuf(stdout, 0);
	GenerateNIL();
    Tree *tree = GenerateRBTree();
    TraversalTree(tree, _NIL, DLR, NodeInfoOutput);

}