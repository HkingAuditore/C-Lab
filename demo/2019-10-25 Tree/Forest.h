//
// Created by HkingAuditore on 2019/11/20.
//

#ifndef C_LAB_FOREST_H
#define C_LAB_FOREST_H

#include "BinaryTreeTraversal.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct forestTree {
    BinaryTree *Tree;
    int Rank;
} ForestTree;

typedef struct forest {
    ForestTree **ForestRoot;
    int NumOfTrees;
} Forest;


//ɭ��������
ForestTree *GenerateForestTree(int _rootData) {
    ForestTree *forestTree = (ForestTree *) malloc(sizeof(ForestTree));
    forestTree->Rank = 1;
    forestTree->Tree = (BinaryTree *) malloc(sizeof(BinaryTree));
    forestTree->Tree->TreeSaverFlag = 1;/*Ĭ����ʽ�洢*/
    forestTree->Tree->Tree.LinkingTree = (BinaryTreeLinking *) malloc(1 * sizeof(BinaryTreeLinking));
    BinaryTreeNode *node = (BinaryTreeNode *) malloc(1 * sizeof(BinaryTreeNode));
    node->Parent = node;
    node->LeftChild = node->RightChild = NULL;
    node->Data = _rootData;
    forestTree->Tree->Tree.LinkingTree->Root = node;
    forestTree->Tree->Tree.LinkingTree->NumOfNode = 1;
    return forestTree;
}

ForestTree* NewForestTree(){
    int rootData;
    printf("�������������ݣ�");
    scanf("%d",&rootData);
    ForestTree* tree =GenerateForestTree(rootData);
    return tree;
}

ForestTree* NewForestTreeNonInput(DataEnum _data){
    ForestTree* tree =GenerateForestTree(_data);
    return tree;
}


//�����ɵ�������ɭ��
Forest *LinkTree2Forest(ForestTree *_tree, Forest *_forest) {
    ForestTree *temp = (ForestTree *) realloc(_forest->ForestRoot, sizeof(BinaryTree) * (_forest->NumOfTrees + 1));
    if(!temp){
        printf("OUT OF MEMORY!\n");
        exit(0);
    }
    _forest->ForestRoot=temp;
    _forest->ForestRoot[_forest->NumOfTrees]=_tree;
    _forest->NumOfTrees++;
    return _forest;
}

//���û��½�һ�������������Ž�ɭ��
void NewTreeInForest(Forest* _forest){
    LinkTree2Forest(NewForestTree(),_forest);
}

void NewTreeInForestNonInPut(Forest* _forest,DataEnum _data){
    LinkTree2Forest(NewForestTreeNonInput(_data),_forest);
}


//ɭ������
Forest GenerateForest() {
    ForestTree **forestRoot = (ForestTree **) malloc(1 * sizeof(ForestTree));
    Forest forest = {forestRoot, 0};
    return forest;
}

//ɭ��չʾ
void ShowForest(Forest _forest){
    for (int i = 0; i < _forest.NumOfTrees ; ++i) {
        printf("No.%d tree's root is %d\n",i,_forest.ForestRoot[i]->Tree->Tree.LinkingTree->Root->Data);
    }
}



#endif //C_LAB_FOREST_H