//
// Created by HkingAuditore on 2019/12/5.
//

#include <stdio.h>
#include <stdlib.h>
#include "TreeBasic.h"
#include "InputController.h"
#include "OutputController.h"

//创建二叉搜索树
Tree *GenerateSimpleSearchTree() {
//    WriteInputTip();
//    生成树
    Tree *tree = GenerateTree(Read(Keyboard));
    ElementType data;
//    根据大小比较寻找位置
    while ((data = Read(Keyboard)) != EXITINPUT) {

        TreeNode *node = GenerateNode(data);
        TreeNode *validPos = GetValidPosition(tree, node,NULL);
        if (GetComparedSide(validPos, node) == Left) {
            validPos->LeftChild=node;
        }else{
            validPos->RightChild=node;
        }
        node->Parent=validPos;
        tree->NumOfNodes++;
    }
    return tree;
}