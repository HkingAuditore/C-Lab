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

typedef enum nodeProcess {
    Add = 1, Delete = -1
} NodeProcess;


//获取孩子之于双亲的关系
Side GetChildSide(TreeNode *_parent, TreeNode *_child) {
    if (_parent->LeftChild == _child) {
        return Left;
    } else if (_parent->RightChild == _child) {
        return Right;
    } else {
        return NoValid;
    }
}

//根据方向获取孩子
TreeNode *GetSideChild(TreeNode *_parent, Side _side) {
    if (_side == Left) {
        return _parent->LeftChild;
    } else {
        return _parent->RightChild;
    }
}

//修改父节点某一边的孩子
void ChangeSideChild(TreeNode *_target, Side _side, TreeNode *_newChild) {
    if (_side == Left) {
        _target->LeftChild = _newChild;
    } else if (_side == Right) {
        _target->RightChild = _newChild;
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
            if (_node->LeftChild && _node->LeftChild->BalanceFactor == -1) {
                printf("LR\n");
                return LR;
            } else {
                printf("LL\n");
                return LL;
            }
        } else if (_node->BalanceFactor <= -2) {
            if (_node->RightChild && _node->RightChild->BalanceFactor == 1) {
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
//Delete
void BalanceUpdateDelete(TreeNode *_node, Tree *_tree, Side _side) {
    TreeNode *curNode = _node;
    Side curSide = _side;
    while (curNode) {
        if(curSide==Right){
            curNode->BalanceFactor++;
        }else{
            curNode->BalanceFactor--;
        }
        curSide = curNode->BalanceFactor>0?Left:Right;
        if(curSide!=_side){
            break;
        }else{
            curNode=curNode->Parent;
        }
    }
    curNode = _node;
    while (curNode) {
        if (abs(curNode->BalanceFactor) >= 2) {
//            printf("Unbalance!\n");
            printf("结点%d不平衡！平衡度为：%d\n", curNode->Data, curNode->BalanceFactor);
            StabilizeNode(GetUnbalanceType(curNode), curNode, _tree);
//            printf("Balanced!\n");
            TraversalTree(_tree, LRD, NodeHeightCalculator);
            TraversalTree(_tree, LRD, BalanceRefresh);
        }
        curNode = curNode->Parent;
    }
}

//ADD
void BalanceUpdateAdd(TreeNode *_node, Tree *_tree) {
    TreeNode *curNode = _node;
    while (curNode->Parent) {
        if (GetChildSide(curNode->Parent, curNode) == Left) {
            curNode->Parent->BalanceFactor++;
        } else {
            curNode->Parent->BalanceFactor--;
        }
        curNode = curNode->Parent;
    }
    curNode = _node;
    while (curNode) {
        if (abs(curNode->BalanceFactor) >= 2) {
//            printf("Unbalance!\n");
            printf("结点%d不平衡！平衡度为：%d\n", curNode->Data, curNode->BalanceFactor);
            StabilizeNode(GetUnbalanceType(curNode), curNode, _tree);
//            printf("Balanced!\n");
            TraversalTree(_tree, LRD, NodeHeightCalculator);
            TraversalTree(_tree, LRD, BalanceRefresh);
        }
        curNode = curNode->Parent;
    }
}

void BalanceUpdate(TreeNode *_node, Tree *_tree, NodeProcess _process, Side _side) {
    if (_process == Add) {
        BalanceUpdateAdd(_node, _tree);
    } else if (_process == Delete) {
        BalanceUpdateDelete(_node, _tree, _side);
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
        BalanceUpdate(node, tree, Add, NoValid);

    }
    return tree;
}

//搜索节点
TreeNode *SearchNode(ElementType _target, Tree *_tree) {
    TreeNode *curnode = _tree->Root;
    while (curnode && (curnode->Data != _target)) {
        if (_target > curnode->Data) {
            curnode = curnode->RightChild;
        } else {
            curnode = curnode->LeftChild;
        }
    }
    return curnode;
}

//删除完成后行为
void DeleteDoneProcess(Tree *_tree, TreeNode *_deleteNode, Side _deleteSide) {
    BalanceUpdate(_deleteNode, _tree, Delete, _deleteSide);
}

//单个删除行为
void DeleteNodeProcess(TreeNode *_target, Side _parentSide, TreeNode *_newChild, Tree *_tree, int _toFree) {
    ChangeSideChild(_target->Parent, _parentSide, _target->RightChild);
    if (_newChild) {
        _newChild->Parent = _target->Parent;
        _newChild->BalanceFactor = _target->BalanceFactor;
        _newChild->Height = _target->Height;
        Side childSide = GetChildSide(_target, _newChild);
        switch (childSide) {
            case Left:
                _newChild->RightChild = _target->RightChild;
                _target->RightChild->Parent = _newChild;
                break;
            case Right:
                _newChild->LeftChild = _target->LeftChild;
                _target->LeftChild->Parent = _newChild;
                break;
            default:
                _newChild->LeftChild = _target->LeftChild;
                _target->LeftChild->Parent = _newChild;
                _newChild->RightChild = _target->RightChild;
                _target->RightChild->Parent = _newChild;
                break;
        }
    }

    if (_toFree)free(_target);
}


//删除节点
TreeNode *DeleteSingleNode(ElementType _target, Tree *_tree) {
    Write("in0\n");
    TreeNode *targetNode = SearchNode(_target, _tree);
    if (!targetNode) {
        return NULL;
    }
    TreeNode *tempParent = targetNode->Parent;
    Side parentSide = GetChildSide(targetNode->Parent, targetNode);
    Side deleteSide;
    if (targetNode->RightChild) {
        Write("in1\n");
        deleteSide = Right;
        if (!targetNode->RightChild->LeftChild) {
            DeleteNodeProcess(targetNode, parentSide, targetNode->RightChild, _tree, 1);
        } else {
            if ((targetNode->RightChild->LeftChild->LeftChild) || (targetNode->RightChild->LeftChild->RightChild)) {
                TreeNode *newChild = targetNode->RightChild->LeftChild;
                TreeNode *newRightNode = targetNode->RightChild;
                DeleteNodeProcess(newChild, parentSide, newChild->RightChild, _tree, 0);
                DeleteNodeProcess(targetNode, parentSide, targetNode->RightChild->LeftChild, _tree, 1);
            } else {
                DeleteNodeProcess(targetNode, parentSide, targetNode->RightChild->LeftChild, _tree, 1);
            }
        }
    } else {
        DeleteNodeProcess(targetNode, parentSide, targetNode->LeftChild, _tree, 1);
        deleteSide = Left;
    }
    Write("in2\n");
    TreeNode *newNode = GetSideChild(tempParent, parentSide);
    TraversalTree(_tree, DLR, NodeInfoOutput);
    DeleteDoneProcess(_tree, newNode, deleteSide);
    return newNode;
}

void DeleteNode(Tree *_tree) {
    Write("删除节点：\n");
    ElementType data;
    while ((data = Read(keyboard)) != EXITINPUT) {
        DeleteSingleNode(data, _tree);
    }
}



