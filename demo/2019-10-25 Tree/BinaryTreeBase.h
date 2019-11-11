//
// Created by HkingAuditore on 2019/10/25.
//

#ifndef C_LAB_BINARYTREE_H
#define C_LAB_BINARYTREEBASE_H

#include <stdio.h>
#include <stdlib.h>
//#include "BinaryTreeTraversal.h"

#define NUMOFNODE 6
#define MAXNUMOFNODE 30

typedef int DataEnum;
typedef struct binaryTreeNode {
    DataEnum Data;
    int Num;
    struct binaryTreeNode *Parent, *LeftChild, *RightChild;
} BinaryTreeNode;
typedef struct binaryTreeLiner {
    BinaryTreeNode **Root;
    int NumOfNode;
} BinaryTreeLiner;
typedef struct binaryTreeLinking {
    BinaryTreeNode *Root;
    int NumOfNode;
} BinaryTreeLinking;


typedef union binaryTreePointer {
    BinaryTreeLiner *LinerTree;
    BinaryTreeLinking *LinkingTree;
} BinaryTreePointer;

typedef struct binaryTree {
    BinaryTreePointer Tree;
//    0为线性存储，1为链式存储
    int TreeSaverFlag;
} BinaryTree;

//typedef BinaryTreeNode *BinaryTree;

int _Nodes2Created[8] = {0, 1, 2, 3, 5, 6, 7, 0};

static BinaryTreeLiner *GenerateBinaryTreeInLinerSaver() {
    BinaryTreeLiner *tree = (BinaryTreeLiner *) calloc(1, sizeof(BinaryTreeLiner));
    tree->Root = (BinaryTreeNode **) calloc(MAXNUMOFNODE + 1, sizeof(BinaryTreeNode *));
    BinaryTreeNode *curPos;
    int numOfNode = NUMOFNODE;
    for (int i = 1; i <= NUMOFNODE; ++i) {
        curPos = calloc(1, sizeof(BinaryTreeNode));
        curPos->Data = i;
        curPos->Num = _Nodes2Created[i];
        tree->Root[_Nodes2Created[i]] = curPos;
        if (tree->Root[_Nodes2Created[i] / 2]) {
            if (_Nodes2Created[i] % 2) {
                tree->Root[_Nodes2Created[i] / 2]->RightChild = curPos;
                curPos->Parent = tree->Root[_Nodes2Created[i] / 2];
            } else {
                tree->Root[_Nodes2Created[i] / 2]->LeftChild = curPos;
                curPos->Parent = tree->Root[_Nodes2Created[i] / 2];
            }
        }
    }
    tree->NumOfNode = NUMOFNODE;
    return tree;
}

static BinaryTreeNode *CreateBinaryTreeNodeLinking(BinaryTreeNode *_parent) {
    BinaryTreeNode *node = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode) * 1);
    node->Parent = _parent;
    printf("请输入数据\n");
    int data;
    scanf("%d", &data);
    getchar();
    node->Data = data;
    printf("是否有左子树？Y/N\n");
    char isLeftChild;
    scanf("%c", &isLeftChild);
    getchar();
    if (isLeftChild == 'Y') {
        node->LeftChild = CreateBinaryTreeNodeLinking(node);
    } else {
        node->LeftChild = NULL;
    }
    printf("是否有右子树？Y/N\n");
    char isRightChild;
    scanf("%c", &isRightChild);
    getchar();
    if (isRightChild == 'Y') {
        node->RightChild = CreateBinaryTreeNodeLinking(node);
    } else {
        node->RightChild = NULL;
    }

    return node;

}


static BinaryTreeLinking *GenerateBinaryTreeInLinkingSaver() {
    BinaryTreeLinking *tree = (BinaryTreeLinking *) malloc(1 * sizeof(BinaryTreeLiner));
    tree->Root = CreateBinaryTreeNodeLinking(NULL);
    return tree;
}

static BinaryTree GenerateBinaryTree(int _type) {
    BinaryTree tree;
    if (_type == 0) {
        tree.Tree.LinerTree = GenerateBinaryTreeInLinerSaver();
        tree.TreeSaverFlag = _type;
    } else if (_type == 1) {
        tree.Tree.LinkingTree = GenerateBinaryTreeInLinkingSaver();
        tree.TreeSaverFlag = _type;
    } else {
        _Exit(0);
    }
    return tree;
}

static DataEnum ReadNode(BinaryTreeNode *_node) {
    return _node->Data;
}

static void PrintNode(BinaryTreeNode *_node) {
    printf("%d ", _node->Data);
}

static void WriteBinaryTreeLinking(BinaryTreeNode *_node) {
    if (_node) {
        PrintNode(_node);
        WriteBinaryTreeLinking(_node->LeftChild);
        WriteBinaryTreeLinking(_node->RightChild);
    }

}


static void WriteBinaryTree(BinaryTree _tree) {
//    printf("IN WRITE!\n");

    if (_tree.TreeSaverFlag == 0) {
        int curPos = 1, outputCount = 1;
        while (outputCount <= _tree.Tree.LinerTree->NumOfNode) {
            if (!_tree.Tree.LinerTree->Root[curPos]) {
                curPos++;
                continue;
            } else {
                printf("num:%d.data:%d,leftChild:%d,rightChild:%d,parent:%d\n", _tree.Tree.LinerTree->Root[curPos]->Num,
                       _tree.Tree.LinerTree->Root[curPos]->Data,
                       (_tree.Tree.LinerTree->Root[curPos]->LeftChild)
                       ? _tree.Tree.LinerTree->Root[curPos]->LeftChild->Num : -1,
                       (_tree.Tree.LinerTree->Root[curPos]->RightChild)
                       ? _tree.Tree.LinerTree->Root[curPos]->RightChild->Num : -1,
                       (_tree.Tree.LinerTree->Root[curPos]->Parent) ? _tree.Tree.LinerTree->Root[curPos]->Parent->Num
                                                                    : -1);
            }
            outputCount++;
            curPos++;
        }
    } else if (_tree.TreeSaverFlag == 1) {
        BinaryTreeNode *curPos = _tree.Tree.LinkingTree->Root;
        WriteBinaryTreeLinking(curPos);
        printf("\n");
    }
}


#endif //C_LAB_BINARYTREE_H
