//
// Created by HkingAuditore on 2019/11/20.
//

#ifndef C_LAB_UNIONFIND_H
#define C_LAB_UNIONFIND_H

#include "Forest.h"
//#include "BinaryTreeTraversal.h"
//#define LINEARINITPOS 1

////递归前序遍历
//static void DLRNode(BinaryTreeNode *_node) {
////    printf("IN!\n");
//    if (_node) {
//        PrintNode(_node);
//        DLRNode(_node->LeftChild);
//        DLRNode(_node->RightChild);
//    }
//}
//
//static void DLR(BinaryTree *_tree) {
//    if (_tree) {
//        if (_tree->TreeSaverFlag == 0) {
//            DLRNode(_tree->Tree.LinearTree->Root[1]);
//        } else {
//            DLRNode(_tree->Tree.LinkingTree->Root);
//        }
//    }
//}

//生成单个目标节点
static  BinaryTreeNode* CreateNode(DataEnum _data){
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(1* sizeof(BinaryTreeNode));
    node->Data=_data;
    node->RightChild=node->LeftChild=node->Parent=NULL;
    return node;
}


//前序遍历寻找目标节点
static BinaryTreeNode* UnionFindTraversal(BinaryTreeNode *_node,DataEnum _target) {
//    printf("IN!\n");
    if (_node) {
        if(_node->Data == _target){
            printf("Find Parent:%d\n",_node->Data);
            return _node;
        }
        BinaryTreeNode* temp;
        temp = UnionFindTraversal(_node->LeftChild,_target);
        if(temp)return temp;
        return UnionFindTraversal(_node->RightChild,_target);
    }else{
//        printf("Find Nothing!\n");
        return NULL;
    }
}

//寻找名下空闲位置
static BinaryTreeNode* FindEmptyChild(BinaryTreeNode* _node){
    if(_node->LeftChild && _node->RightChild){
            FindEmptyChild(_node->LeftChild);
    }else{
        printf("Find Empty Positon at parent:%d\n",_node->Data);
        return _node;
        return _node;
    }
}

static void MergeTree(Forest *_forest,BinaryTreeNode* _target,BinaryTree* _child ){
    BinaryTreeNode* target= FindEmptyChild(_target);
    if(!target->LeftChild){
        target->LeftChild=_child->Tree.LinkingTree->Root;
    } else{
        target->RightChild=_child->Tree.LinkingTree->Root;
    }
    _child->Tree.LinkingTree->Root->Parent=target;
    for (int i = 0; i < _forest->NumOfTrees; ++i) {
        if(_forest->ForestRoot[i]->Tree == _child){
            _forest->ForestRoot[i]=_forest->ForestRoot[_forest->NumOfTrees-1];
            break;
        }
    }
    _forest->NumOfTrees--;


}
//寻找双亲并连接
static void LinkChild(Forest* _forest,DataEnum _childData,DataEnum _target){
    BinaryTreeNode* result = NULL;
    for (int i = 0; i < _forest->NumOfTrees; ++i) {
        result= UnionFindTraversal(_forest->ForestRoot[i]->Tree->Tree.LinkingTree->Root,_target);
        if(result)break;
    }
    printf("now find %p parent\n",result);
    if(!result){

        NewTreeInForestNonInPut(_forest,_target);
        printf("Now create a new tree\n");
        result =_forest->ForestRoot[_forest->NumOfTrees-1]->Tree->Tree.LinkingTree->Root;
    }

    BinaryTreeNode* existedChild = NULL;
    for (int i = 0; i < _forest->NumOfTrees; ++i) {
        existedChild= UnionFindTraversal(_forest->ForestRoot[i]->Tree->Tree.LinkingTree->Root,_childData);
        if(existedChild)break;
    }

    if(existedChild){
        printf("now find %p existed child\n",existedChild);
         while (existedChild->Parent!=existedChild){
             existedChild=existedChild->Parent;
         }
         BinaryTree* existedTree=NULL;
        for (int i = 0; i <_forest->NumOfTrees ; ++i) {
            if(_forest->ForestRoot[i]->Tree->Tree.LinkingTree->Root->Data==existedChild->Data){
                existedTree=_forest->ForestRoot[i]->Tree;
                break;
            }
        }
         MergeTree(_forest,result,existedTree);
        return;
    }



    BinaryTreeNode* node = CreateNode(_childData);
    result = FindEmptyChild(result);
    node->Parent=result;
    if(!result->LeftChild){
        result->LeftChild=node;
    }else{
        result->RightChild=node;
    }
}

//交互式寻找双亲
static void InteractiveLinkChild(Forest* _forest){
    DataEnum childData,target;
    printf("输入双亲数据：");
    scanf("%d",&target);
    printf("输入孩子数据：");
    scanf("%d",&childData);
    LinkChild(_forest,childData,target);
}

static void TraversalForest(Forest forest){
    printf("============================================================\n");
    for (int i = 0; i <forest.NumOfTrees ; ++i) {
        printf("第 %d 棵树：\n",i);
        TraversalBinaryTree(forest.ForestRoot[i]->Tree,0,1);
        TraversalBinaryTree(forest.ForestRoot[i]->Tree,1,1);
        TraversalBinaryTree(forest.ForestRoot[i]->Tree,2,1);
        printf("------------------------\n");
    }
    printf("============================================================\n");

}





#endif //C_LAB_UNIONFIND_H
