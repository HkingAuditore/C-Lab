//
// Created by HkingAuditore on 2019/11/4.
//

#ifndef C_LAB_BINARYTREETRAVERSAL_H
#define C_LAB_BINARYTREETRAVERSAL_H

#include "BinaryTreeBase.h"
#include "TreeBase.h"

#define LINEARINITPOS 1

/*前序遍历*/

//递归前序遍历
static void RecursionDLRNode(BinaryTreeNode *_node) {
//    printf("IN!\n");
    if (_node) {
        PrintNode(_node);
        RecursionDLRNode(_node->LeftChild);
        RecursionDLRNode(_node->RightChild);
    }
}

static void RecursionDLR(BinaryTree *_tree) {
    if (_tree) {
        if (_tree->TreeSaverFlag == 0) {
            RecursionDLRNode(_tree->Tree.LinearTree->Root[LINEARINITPOS]);
        } else {
            RecursionDLRNode(_tree->Tree.LinkingTree->Root);
        }
    }
}

//递推前序遍历

static void RecurrenceDLRNode(BinaryTreeNode *_node) {
    BinaryTreeNode *cur;
    BinaryTreeNode *tempStack[100] = {0};
    int tempCount[100] = {0};
    int stackTop = 0;
    cur = _node;
    while (stackTop >= 0) {
        while (cur) {
            if (tempCount[stackTop] >= 2)break;
            tempStack[stackTop] = cur;
            if (tempCount[stackTop] == 0) {
                PrintNode(cur);
                cur = cur->LeftChild;
            } else {
                cur = cur->RightChild;
            }
            tempCount[stackTop++]++;
        }
        tempCount[stackTop] = 0;
        stackTop--;
        cur = tempStack[stackTop];
    }
}


static void RecurrenceDLR(BinaryTree *_tree) {
    if (_tree) {
        BinaryTreeNode *cur;
        if (_tree->TreeSaverFlag == 0) {
            RecurrenceDLRNode(_tree->Tree.LinearTree->Root[1]);
        } else {
            RecurrenceDLRNode(_tree->Tree.LinkingTree->Root);
        }
    }
}

//前序遍历最终函数
static void BinaryDLR(BinaryTree *_tree, int _mode) {
    if (_mode == 0) {
        printf("-递归：");
        RecursionDLR(_tree);
    } else {
        printf("-递推：");
        RecurrenceDLR(_tree);
    }
}

/*中序遍历*/

//递归中序遍历
static void RecursionLDRNode(BinaryTreeNode *_node) {
    if (_node) {
        RecursionLDRNode(_node->LeftChild);
        PrintNode(_node);
        RecursionLDRNode(_node->RightChild);
    }
}

static void RecursionLDR(BinaryTree *_tree) {
    if (_tree) {
        if (_tree->TreeSaverFlag == 0) {
            RecursionLDRNode(_tree->Tree.LinearTree->Root[LINEARINITPOS]);
        } else {
            RecursionLDRNode(_tree->Tree.LinkingTree->Root);
        }
    }
}

//递推中序遍历
static void RecurrenceLDRNode(BinaryTreeNode *_node) {
    BinaryTreeNode *cur;
    BinaryTreeNode *tempStack[100] = {0};
    int tempCount[100] = {0};
    int stackTop = 0;
    cur = _node;
    while (stackTop >= 0) {
        while (cur) {
            if (tempCount[stackTop] >= 2)break;
            tempStack[stackTop] = cur;
            if (tempCount[stackTop] == 0) {
                cur = cur->LeftChild;
//                continue;
            } else {
                PrintNode(cur);
                cur = cur->RightChild;
            }
//            PrintNode(cur);
            tempCount[stackTop++]++;
        }
        tempCount[stackTop] = 0;
        stackTop--;
        cur = tempStack[stackTop];
    }
}

static void RecurrenceLDR(BinaryTree *_tree) {
    if (_tree) {
        BinaryTreeNode *cur;
        if (_tree->TreeSaverFlag == 0) {
            RecurrenceLDRNode(_tree->Tree.LinearTree->Root[1]);
        } else {
            RecurrenceLDRNode(_tree->Tree.LinkingTree->Root);
        }
    }
}

//中序遍历最终函数
static void BinaryLDR(BinaryTree *_tree, int _mode) {
    if (_mode == 0) {
        printf("-递归：");
        RecursionLDR(_tree);
    } else {
        printf("-递推：");
        RecurrenceLDR(_tree);
    }
}



/*后序遍历*/

//递归后序遍历
static void RecursionLRDNode(BinaryTreeNode *_node) {
//    printf("IN!\n");
    if (_node) {
        RecursionLRDNode(_node->LeftChild);
        RecursionLRDNode(_node->RightChild);
        PrintNode(_node);
    }
}

static void RecursionLRD(BinaryTree *_tree) {
    if (_tree) {
        if (_tree->TreeSaverFlag == 0) {
            RecursionLRDNode(_tree->Tree.LinearTree->Root[LINEARINITPOS]);
        } else {
            RecursionLRDNode(_tree->Tree.LinkingTree->Root);
        }
    }
}

//递推后序遍历
static void RecurrenceLRDNode(BinaryTreeNode *_node) {
    BinaryTreeNode *cur;
    BinaryTreeNode *tempStack[100] = {0};
    int tempCount[100] = {0};
    int stackTop = 0;
    cur = _node;
    while (stackTop >= 0) {
        while (cur) {
            if (tempCount[stackTop] >= 2){
                PrintNode(cur);
                break;
            }
            tempStack[stackTop] = cur;
            if (tempCount[stackTop] == 0) {
                cur = cur->LeftChild;
            } else {
                cur = cur->RightChild;
            }
            tempCount[stackTop++]++;
        }
        tempCount[stackTop] = 0;
        stackTop--;
        cur = tempStack[stackTop];
    }
}

static void RecurrenceLRD(BinaryTree *_tree) {
    if (_tree) {
        BinaryTreeNode *cur;
        if (_tree->TreeSaverFlag == 0) {
            RecurrenceLRDNode(_tree->Tree.LinearTree->Root[1]);
        } else {
            RecurrenceLRDNode(_tree->Tree.LinkingTree->Root);
        }
    }
}

//后序遍历最终函数
static void BinaryLRD(BinaryTree *_tree, int _mode) {
    if (_mode == 0) {
        printf("-递归：");
        RecursionLRD(_tree);
    } else {
        printf("-递推：");
        RecurrenceLRD(_tree);
    }
}

//遍历最终函数
static void TraversalBinaryTree(BinaryTree *_tree, int _type, int _inType) {
    switch (_type) {
        case 0:
            printf("DLR前序");
            BinaryDLR(_tree, _inType);
            break;
        case 1:
            printf("LDR中序");
            BinaryLDR(_tree, _inType);
            break;
        case 2:
            printf("LRD后序");
            BinaryLRD(_tree, _inType);
            break;
        default:
            printf("ERROR!");
            break;
    }
    printf("\n");
}


#endif //C_LAB_BINARYTREETRAVERSAL_H
