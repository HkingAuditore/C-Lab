//
// Created by HkingAuditore on 2019/12/4.
//

#ifndef C_LAB_TREEBASIC_H
#define C_LAB_TREEBASIC_H

#include <stdio.h>
#include <stdlib.h>
#include "OutputController.h"

//��������
typedef int ElementType;
//λ��
typedef enum side {
    noValid, left, right
} Side;
//���
typedef struct treeNode {
    ElementType Data;
    struct treeNode *LeftChild, *RightChild, *Parent;
} TreeNode;
//��
typedef struct tree {
    TreeNode *Root;
    int NumOfNodes;
} Tree;
//��ת����
typedef enum direction {
    turnLeft, turnRight
} Direction;


//���ɽڵ�
static TreeNode *GenerateNode(ElementType _rootData) {
    TreeNode *leaf = (TreeNode *) malloc(1 * sizeof(TreeNode));
    if (leaf) {
//      ��ʼ��
        leaf->Data = _rootData;
        leaf->LeftChild = leaf->RightChild = leaf->Parent = NULL;
    }
    return leaf;
}

//���ɳ�ʼ��
static Tree *GenerateTree(ElementType _rootData) {
    Tree *tree = (Tree *) malloc(1 * sizeof(Tree));
    if (tree) {
        tree->Root = GenerateNode(_rootData);
    }
    tree->NumOfNodes=0;
    return tree;
}

//����֪�ڵ����Ҷ��
static int AppendLeaf(TreeNode *_target, TreeNode *_leaf, Side _side) {
    _leaf->Parent = _target;
    if (_side == left) {
        _target->LeftChild = _leaf;
    } else if (_side == right) {
        _target->RightChild = _leaf;
    } else {
        return 0;
    }
    return 1;
}

//��ȡ����λ��
static Side GetValidSide(TreeNode *_node) {
    if (!_node->LeftChild) {
        return left;
    } else if (!_node->RightChild) {
        return right;
    } else {
        return noValid;
    }
}



//���ڲ����������ݴ�С����λ��
static Side GetComparedSide(TreeNode *_node, TreeNode *_follow) {
    if (_follow->Data > _node->Data) {
        return right;
    } else {
        return left;
    }
}
//��ȡ���ݴ�С�ó����½ڵ��ڲ������еĺ���λ��
static TreeNode* GetValidPosition(Tree* _tree,TreeNode* _node){
    TreeNode* _position=_tree->Root;
    Side side;
    while (_position){
        side = GetComparedSide(_position,_node);
        if(side == left){
            if(_position->LeftChild){
                _position = _position->LeftChild;
                continue;
            }else{
                return _position;
            }
        }else{
            if(_position->RightChild){
                _position=_position->RightChild;
                continue;
            }else{
                return _position;
            }
        }
    }
}

//���ڵ�����
static int RotateNodeLeft(TreeNode *_pivot) {
    Side pivotSide = _pivot->Parent->LeftChild == _pivot ? left : right;
    if (pivotSide == left) {
        _pivot->Parent->LeftChild = _pivot->RightChild;
    } else {
        _pivot->Parent->RightChild = _pivot->RightChild;
    }
    _pivot->Parent = _pivot->RightChild;
    _pivot->RightChild = _pivot->RightChild->LeftChild;
    _pivot->Parent->LeftChild = _pivot;
    return 1;
}

//���ڵ�����
static int RotateNodeRight(TreeNode *_pivot) {
    Side pivotSide = _pivot->Parent->LeftChild == _pivot ? left : right;
    if (pivotSide == left) {
        _pivot->Parent->LeftChild = _pivot->RightChild;
    } else {
        _pivot->Parent->RightChild = _pivot->RightChild;
    }
    _pivot->Parent = _pivot->LeftChild;
    _pivot->LeftChild = _pivot->LeftChild->RightChild;
    _pivot->Parent->RightChild = _pivot;
    return 1;
}

//��תPivot�ڵ�
static int RotateNode(TreeNode *_pivot, Direction _dir) {
    if (_dir == turnLeft) {
        RotateNodeLeft(_pivot);
    } else if (_dir == turnRight){
        RotateNodeRight(_pivot);
    }else{
        return 0;
    }
    return 1;
}



//����ڵ�
static ElementType OutputNode(const TreeNode *_node) {
    WriteData(_node->Data);
    return _node->Data;
}

//������ʽ
typedef enum traversalMode{
    DLR,LDR,LRD
}TraversalMode;


/*****************ǰ�����*****************/


//ǰ������ڵ�
static void TraversalNodeDLR(const TreeNode *_node) {
    if(_node){
        OutputNode(_node);
        TraversalNodeDLR(_node->LeftChild);
        TraversalNodeDLR(_node->RightChild);
    }
}

//ǰ�������
static void TraversalDLR(const Tree* _tree){
    if(_tree && _tree->Root){
       TraversalNodeDLR(_tree->Root);
    }
}

/*****************ǰ�����*****************/

/*****************�������*****************/
//��������ڵ�
static void TraversalNodeLDR(const TreeNode *_node) {
    if(_node){
        TraversalNodeDLR(_node->LeftChild);
        OutputNode(_node);
        TraversalNodeDLR(_node->RightChild);
    }
}

//���������
static void TraversalLDR(const Tree* _tree){
    if(_tree && _tree->Root){
        TraversalNodeDLR(_tree->Root);
    }
}
/*****************�������*****************/


/*****************�������*****************/
//��������ڵ�
static void TraversalNodeLRD(const TreeNode *_node) {
    if(_node){
        TraversalNodeDLR(_node->LeftChild);
        TraversalNodeDLR(_node->RightChild);
        OutputNode(_node);
    }
}

//���������
static void TraversalLRD(const Tree* _tree){
    if(_tree && _tree->Root){
        TraversalNodeDLR(_tree->Root);
    }
}
/*****************�������*****************/

//������
static int TraversalTree(const Tree *_tree,TraversalMode _mode){
    WriteTraversalTip(_mode);
    switch (_mode){
        case DLR:
            TraversalDLR(_tree);
            return 1;
        case LDR:
            TraversalLDR(_tree);
            return 1;
        case LRD:
            TraversalLRD(_tree);
            return 1;
        default:
            return 0;
    }
    SwitchLine();
}

#endif //C_LAB_TREEBASIC_H
