//
// Created by HkingAuditore on 2019/10/25.
//

#ifndef C_LAB_BINARYTREE_H
#define C_LAB_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

#define NUMOFNODE 6
#define MAXNUMOFNODE 30

typedef int DataEnum;
typedef struct binaryTreeNode {
    DataEnum Data;
    int Num;
    struct binaryTreeNode *LeftChild, *RightChild;
} BinaryTreeNode;
typedef struct binaryTree {
    BinaryTreeNode **Root;
    int NumOfNode;
} BinaryTree;

//typedef BinaryTreeNode *BinaryTree;

int _Nodes2Created[8] = {0,1, 2, 3, 5, 6, 7,0};

BinaryTree *GenerateBinaryTree() {
//    printf("IN GENERATE!\n");
    BinaryTree *tree = (BinaryTree *) calloc(1, sizeof(BinaryTree));
//    printf("HAVE GENERATED TREE!\n");
    tree->Root = (BinaryTreeNode **) calloc(MAXNUMOFNODE + 1, sizeof(BinaryTreeNode *));
//    printf("HAVE GENERATED TREE DATA!\n");
    BinaryTreeNode *curPos;
    int numOfNode = NUMOFNODE;
    for (int i = 1; i <= NUMOFNODE; ++i) {
        curPos = calloc(1, sizeof(BinaryTreeNode));
//        printf("HAVE GENERATED TREE NODE %d!\n",i);
        curPos->Data = i;
        curPos->Num = _Nodes2Created[i];
        tree->Root[_Nodes2Created[i]] = curPos;
//        printf("HAVE LINKED TREE NODE %d!\n",i);
        if (tree->Root[_Nodes2Created[i] / 2]) {
            if (_Nodes2Created[i] % 2) {
                tree->Root[_Nodes2Created[i] / 2]->RightChild = curPos;
            } else {
                tree->Root[_Nodes2Created[i] / 2]->LeftChild = curPos;
            }
        }
    }
    tree->NumOfNode = NUMOFNODE;
//    free(curPos);
//    printf("ALL DONE!\n");
    return tree;
}

void WriteBinaryTree(BinaryTree _tree) {
//    printf("IN WRITE!\n");
    int curPos = 1, outputCount = 1;
    while (outputCount <= _tree.NumOfNode) {
        if (!_tree.Root[curPos]) {
            curPos++;
            continue;
        } else {
            printf("num:%d.data:%d,leftChild:%d,rightChild:%d\n", _tree.Root[curPos]->Num, _tree.Root[curPos]->Data,
                   (_tree.Root[curPos]->LeftChild)?_tree.Root[curPos]->LeftChild->Num:-1,
                   (_tree.Root[curPos]->RightChild)?_tree.Root[curPos]->RightChild->Num:-1);
        }
        outputCount++;
        curPos++;
    }
}

#endif //C_LAB_BINARYTREE_H
