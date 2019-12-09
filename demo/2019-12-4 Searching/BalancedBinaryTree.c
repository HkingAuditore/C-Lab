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


//��ȡ����֮��˫�׵Ĺ�ϵ
Side GetChildSide(TreeNode *_parent, TreeNode *_child) {
    if (_parent->LeftChild == _child) {
        return Left;
    } else {
        return Right;
    }
}

//LL���
void LLProcess(TreeNode *_pivot, Tree *_tree) {
    RotateNode(_pivot, TurnRight, _tree);
}

//RR���
void RRProcess(TreeNode *_pivot, Tree *_tree) {
    RotateNode(_pivot, TurnLeft, _tree);
}

//LR���
void LRProcess(TreeNode *_pivot, Tree *_tree) {
    RotateNode(_pivot->LeftChild, TurnLeft, _tree);
    RotateNode(_pivot, TurnRight, _tree);
}

//RL���
void RLProcess(TreeNode *_pivot, Tree *_tree) {
    RotateNode(_pivot->RightChild, TurnRight, _tree);
    RotateNode(_pivot, TurnLeft, _tree);
}

//�ж�����
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

//�������ε���ƽ��
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

//ˢ��ƽ��
void BalanceRefresh(TreeNode *_node) {
    int left = _node->LeftChild ? _node->LeftChild->Height + 1 : 0;
    int right = _node->RightChild ? _node->RightChild->Height + 1 : 0;
    _node->BalanceFactor = left - right;
}


//����ƽ��
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
            printf("���%d��ƽ�⣡ƽ���Ϊ��%d\n", curNode->Data, curNode->BalanceFactor);
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
//    ������
    Tree *tree = GenerateTree(Read(keyboard));
    ElementType data;
//    ���ݴ�С�Ƚ�Ѱ��λ��
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

