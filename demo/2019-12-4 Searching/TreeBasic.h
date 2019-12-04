//
// Created by HkingAuditore on 2019/12/4.
//

#ifndef C_LAB_TREEBASIC_H
#define C_LAB_TREEBASIC_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef enum side {
    noValid, left, right
} Side;
typedef struct treeNode {
    ElementType Data;
    struct treeNode *LeftChild, *RightChild, *Parent;
} TreeNode;

typedef struct tree {
    TreeNode *Root;
    int NumOfNodes;
} Tree;

//生成节点
TreeNode *GenerateNode(ElementType _rootData) {
    TreeNode *leaf = (TreeNode *) malloc(1 * sizeof(TreeNode));
    if (leaf) {
//      初始化
        leaf->Data = _rootData;
        leaf->LeftChild = leaf->RightChild = leaf->Parent = NULL;
    }
    return leaf;
}

//生成初始树
Tree *GenerateTree(ElementType _rootData) {
    Tree *tree = (Tree *) malloc(1 * sizeof(Tree));
    if (tree) {
        tree->Root = GenerateNode(_rootData);
    }
    return tree;
}

//给已知节点加入叶子
int AddLeaf(TreeNode *_target, TreeNode *_leaf, Side _side) {
    _leaf->Parent = _target;
    if (_side == left) {
        _target->LeftChild = _leaf;
    } else if (_side == right) {
        _target->RightChild = _leaf;
    } else {
        return 1;
    }
    return 0;
}

//获取空闲位置
Side GetValidSide(TreeNode *_node) {
    if (!_node->LeftChild) {
        return left;
    } else if (!_node->RightChild) {
        return right;
    } else {
        return noValid;
    }
}

//对于查找树，根据大小返回位置
Side GetComparedSide(TreeNode *_node, TreeNode *_follow) {
    if (_follow->Data > _node->Data){
        return right;
    }else{
        return left;
    }
}

//将节点左旋
int RotateNodeLeft(TreeNode* _pivot){
    Side pivotSide= _pivot->Parent->LeftChild==_pivot?left:right;
    if(pivotSide==left){
        _pivot->Parent->LeftChild =_pivot->RightChild;
    }else{
        _pivot->Parent->RightChild =_pivot->RightChild;
    }

    _pivot->Parent=_pivot->RightChild;
    _pivot->RightChild=_pivot->RightChild->LeftChild;
    _pivot->Parent->LeftChild=_pivot;
}

//将节点右旋
int RotateNodeRight(TreeNode* _pivot){
    Side pivotSide= _pivot->Parent->LeftChild==_pivot?left:right;
    if(pivotSide==left){
        _pivot->Parent->LeftChild =_pivot->RightChild;
    }else{
        _pivot->Parent->RightChild =_pivot->RightChild;
    }

    _pivot->Parent=_pivot->LeftChild;
    _pivot->LeftChild=_pivot->LeftChild->RightChild;
    _pivot->Parent->RightChild=_pivot;
}

#endif //C_LAB_TREEBASIC_H
