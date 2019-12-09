//
// Created by HkingAuditore on 2019/12/8.
//

#include "TreeBasic.h"
#include <stdio.h>
#include <stdlib.h>
#include "InputController.h"
#include <math.h>
#include "OutputController.h"


typedef enum unbalanceType {
    Balanced, LL, RR, LR, RL
} UnbalanceType;


//获取孩子之于双亲的关系
Side GetChildSide(TreeNode *_parent, TreeNode *_child) {
    if (_parent->LeftChild == _child) {
        return Left;
    } else {
        return Right;
    }
}

//LL情况
void LLProcess(TreeNode *_pivot, Tree *_tree) {
    RotateNode(_pivot, TurnRight, _tree);
}

//RR情况
void RRProcess(TreeNode *_pivot, Tree *_tree) {
    RotateNode(_pivot, TurnLeft, _tree);
}

//LR情况
void LRProcess(TreeNode *_pivot, Tree *_tree) {
    RotateNode(_pivot->LeftChild, TurnLeft, _tree);
    RotateNode(_pivot, TurnRight, _tree);
}

//RL情况
void RLProcess(TreeNode *_pivot, Tree *_tree) {
    RotateNode(_pivot->RightChild, TurnRight, _tree);
    RotateNode(_pivot, TurnLeft, _tree);
}

//判断情形
UnbalanceType GetUnbalanceType(TreeNode *_node) {
//    printf("unbalance type:");
    if (_node->BalanceFactor >= 2) {
        if (_node->LeftChild && _node->LeftChild->BalanceFactor >= 1) {
            printf("LL\n");
            return LL;
        } else {
            printf("LR\n");
            return LR;
        }
    } else if (_node->BalanceFactor <= -2) {
        if (_node->RightChild && _node->RightChild->BalanceFactor >= 1) {
            printf("RL\n");
            return RL;
        } else {
            printf("RR\n");
            return RR;
        }
    } else {
        return Balanced;
    }
}

//根据情形调整平衡
void StabilizeNode(UnbalanceType _type, TreeNode *_node, Tree *_tree) {
//    printf("in stabilize!\n");
    switch (_type) {
        case LL:
            LLProcess(_node, _tree);
            break;
        case RR:
            RRProcess(_node, _tree);
            break;
        case LR:
            LRProcess(_node, _tree);
            break;
        case RL:
            RLProcess(_node, _tree);
            break;
        default:
            break;
    }
}

//刷新平衡
void BalanceRefresh(TreeNode *_node) {
    int left = _node->LeftChild ? _node->LeftChild->Height + 1 : 0;
    int right = _node->RightChild ? _node->RightChild->Height + 1 : 0;
    _node->BalanceFactor = left - right;
}


//更新平衡
void BalanceUpdate(TreeNode *_newNode, Tree *_tree) {
    TreeNode *curNode = _newNode;
    while (curNode->Parent) {
        if (GetChildSide(curNode->Parent, curNode) == Left) {
            curNode->Parent->BalanceFactor++;
        } else {
            curNode->Parent->BalanceFactor--;
        }
        curNode=curNode->Parent;
    }
    curNode = _newNode;
    while (curNode) {
        if (abs(curNode->BalanceFactor) >= 2) {
//            printf("Unbalance!\n");
            printf("结点%d不平衡！平衡度为：%d\n", curNode->Data, curNode->BalanceFactor);
            StabilizeNode(GetUnbalanceType(curNode), curNode, _tree);
//            printf("Balanced!\n");
            TraversalTree(_tree, LRD, NodeHeightCalculator);
            TraversalTree(_tree, LRD, BalanceRefresh);
        }
        curNode=curNode->Parent;
    }
}


Tree *GenerateAVLTree() {
//    WriteInputTip();
//    生成树
    Tree *tree = GenerateTree(Read(keyboard));
    ElementType data;
//    根据大小比较寻找位置
    while ((data = Read(keyboard)) != EXITINPUT) {

        TreeNode *node = GenerateNode(data);
        TreeNode *validPos = GetValidPosition(tree, node);
        if (GetComparedSide(validPos, node) == Left) {
            validPos->LeftChild = node;
        } else {
            validPos->RightChild = node;
        }
        node->Parent = validPos;
        tree->NumOfNodes++;
        BalanceUpdate(node, tree);
    }
    return tree;
}

