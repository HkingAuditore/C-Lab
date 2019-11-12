//
// Created by HkingAuditore on 2019/10/25.
//

#ifndef C_LAB_BINARYTREE_H
#define C_LAB_BINARYTREEBASE_H

#include <stdio.h>
#include <stdlib.h>
//#include "BinaryTreeTraversal.h"

#define NUMOFNODE 6
#define MAXNUMOFNODE 100

typedef int DataEnum;
typedef struct binaryTreeNode {
    DataEnum Data;
    int Num;
    struct binaryTreeNode *Parent, *LeftChild, *RightChild;
} BinaryTreeNode;
typedef struct binaryTreeLinear {
    BinaryTreeNode **Root;
    int NumOfNode;
} BinaryTreeLinear;
typedef struct binaryTreeLinking {
    BinaryTreeNode *Root;
    int NumOfNode;
} BinaryTreeLinking;


typedef union binaryTreePointer {
    BinaryTreeLinear *LinearTree;
    BinaryTreeLinking *LinkingTree;
} BinaryTreePointer;

typedef struct binaryTree {
    BinaryTreePointer Tree;
//    0Ϊ���Դ洢��1Ϊ��ʽ�洢
    int TreeSaverFlag;
} BinaryTree;

enum LeftOrRight {
    Left = 0, Right = 1
};

//typedef BinaryTreeNode *BinaryTree;

int _Nodes2Created[8] = {0, 1, 2, 3, 5, 6, 7, 0};

//�������Դ洢�������ڵ�
static BinaryTreeNode *CreateBinaryTreeNodeLinear(BinaryTreeLinear* _tree, BinaryTreeNode *_parent, enum LeftOrRight _childType) {
    BinaryTreeNode *node = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode) * 1);
    if(_parent){
        node->Num = _parent->Num * 2 + (int) _childType;
    }else{
        node->Num = 1;
    }

    _tree->Root[node->Num]=node;
    node->Parent = _parent;
    printf("����������\n");
    int data;
    scanf("%d", &data);
    getchar();
    node->Data = data;
    printf("����Ϊ %d �Ľڵ��Ƿ�����������Y/N\n", data);
    char isLeftChild;
    scanf("%c", &isLeftChild);
    getchar();
    if (isLeftChild == 'Y') {
        node->LeftChild = CreateBinaryTreeNodeLinear(_tree, node, Left);
    } else {
        node->LeftChild = NULL;
    }
    printf("����Ϊ %d �Ľڵ��Ƿ�����������Y/N\n", data);
    char isRightChild;
    scanf("%c", &isRightChild);
    getchar();
    if (isRightChild == 'Y') {
        node->RightChild = CreateBinaryTreeNodeLinear(_tree, node, Right);
    } else {
        node->RightChild = NULL;
    }

    return node;

}


//�������Դ洢������
static BinaryTreeLinear *GenerateBinaryTreeInLinearSaver() {
//    BinaryTreeLinear *tree = (BinaryTreeLinear *) calloc(1, sizeof(BinaryTreeLinear));
//    tree->Root = (BinaryTreeNode **) calloc(MAXNUMOFNODE + 1, sizeof(BinaryTreeNode *));
//    BinaryTreeNode *curPos;
//    int numOfNode = NUMOFNODE;
//    for (int i = 1; i <= NUMOFNODE; ++i) {
//        curPos = calloc(1, sizeof(BinaryTreeNode));
//        curPos->Data = i;
//        curPos->Num = _Nodes2Created[i];
//        tree->Root[_Nodes2Created[i]] = curPos;
//        if (tree->Root[_Nodes2Created[i] / 2]) {
////            ˫��ƥ��
//            if (_Nodes2Created[i] % 2) {
//                tree->Root[_Nodes2Created[i] / 2]->RightChild = curPos;
//                curPos->Parent = tree->Root[_Nodes2Created[i] / 2];
//            } else {
//                tree->Root[_Nodes2Created[i] / 2]->LeftChild = curPos;
//                curPos->Parent = tree->Root[_Nodes2Created[i] / 2];
//            }
//        }
//    }
//    tree->NumOfNode = NUMOFNODE;
//    printf("DONE!\n");
//    return tree;
    BinaryTreeLinear *tree = (BinaryTreeLinear *) calloc(1, sizeof(BinaryTreeLinear));
    tree->Root = (BinaryTreeNode **) calloc(MAXNUMOFNODE + 1, sizeof(BinaryTreeNode *));
    CreateBinaryTreeNodeLinear(tree,NULL,0);
    return tree;
}

//������ʽ�洢�������ڵ�
static BinaryTreeNode *CreateBinaryTreeNodeLinking(BinaryTreeNode *_parent) {
    BinaryTreeNode *node = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode) * 1);
    node->Parent = _parent;
    printf("����������\n");
    int data;
    scanf("%d", &data);
    getchar();
    node->Data = data;
    printf("����Ϊ %d �Ľڵ��Ƿ�����������Y/N\n", data);
    char isLeftChild;
    scanf("%c", &isLeftChild);
    getchar();
    if (isLeftChild == 'Y') {
        node->LeftChild = CreateBinaryTreeNodeLinking(node);
    } else {
        node->LeftChild = NULL;
    }
    printf("����Ϊ %d �Ľڵ��Ƿ�����������Y/N\n", data);
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

//������ʽ�洢������
static BinaryTreeLinking *GenerateBinaryTreeInLinkingSaver() {
    BinaryTreeLinking *tree = (BinaryTreeLinking *) malloc(1 * sizeof(BinaryTreeLinear));
    tree->Root = CreateBinaryTreeNodeLinking(NULL);
    return tree;
}

//���������ɶ�����
static BinaryTree GenerateBinaryTree(int _type) {
    BinaryTree tree;
    if (_type == 0) {
        tree.Tree.LinearTree = GenerateBinaryTreeInLinearSaver();
        tree.TreeSaverFlag = _type;
    } else if (_type == 1) {
        tree.Tree.LinkingTree = GenerateBinaryTreeInLinkingSaver();
        tree.TreeSaverFlag = _type;
    } else {
        _Exit(0);
    }
    return tree;
}

//�����ڵ�
static DataEnum ReadNode(BinaryTreeNode *_node) {
    return _node->Data;
}

//��ӡ�ڵ�
static void PrintNode(BinaryTreeNode *_node) {
    printf("%d ", ReadNode(_node));
}

//���������ԣ�
static void WriteBinaryTreeLinking(BinaryTreeNode *_node) {
    if (_node) {
        PrintNode(_node);
        WriteBinaryTreeLinking(_node->LeftChild);
        WriteBinaryTreeLinking(_node->RightChild);
    }

}

//��ӡ��
static void WriteBinaryTree(BinaryTree _tree) {
//    printf("IN WRITE!\n");

    if (_tree.TreeSaverFlag == 0) {
        int curPos = 1, outputCount = 1;
        while (outputCount <= _tree.Tree.LinearTree->NumOfNode) {
            if (!_tree.Tree.LinearTree->Root[curPos]) {
                curPos++;
                continue;
            } else {
                printf("num:%d.data:%d,leftChild:%d,rightChild:%d,parent:%d\n",
                       _tree.Tree.LinearTree->Root[curPos]->Num,
                       _tree.Tree.LinearTree->Root[curPos]->Data,
                       (_tree.Tree.LinearTree->Root[curPos]->LeftChild)
                       ? _tree.Tree.LinearTree->Root[curPos]->LeftChild->Num : -1,
                       (_tree.Tree.LinearTree->Root[curPos]->RightChild)
                       ? _tree.Tree.LinearTree->Root[curPos]->RightChild->Num : -1,
                       (_tree.Tree.LinearTree->Root[curPos]->Parent) ? _tree.Tree.LinearTree->Root[curPos]->Parent->Num
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
