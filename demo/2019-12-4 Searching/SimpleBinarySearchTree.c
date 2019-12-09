//
// Created by HkingAuditore on 2019/12/5.
//

#include <stdio.h>
#include <stdlib.h>
#include "TreeBasic.h"
#include "InputController.h"
#include "OutputController.h"

//��������������
Tree *GenerateSimpleSearchTree() {
//    WriteInputTip();
//    ������
    Tree *tree = GenerateTree(Read(keyboard));
    ElementType data;
//    ���ݴ�С�Ƚ�Ѱ��λ��
    while ((data = Read(keyboard)) != EXITINPUT) {

        TreeNode *node = GenerateNode(data);
        TreeNode *validPos = GetValidPosition(tree, node);
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