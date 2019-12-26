//
// Created by HkingAuditore on 2019/12/23.
//

#ifndef C_LAB_REDBLACKTREE_H
#define C_LAB_REDBLACKTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "OutputController.h"

#include "BalancedBinaryTree.h"
#include "TreeBasic.h"
#include "InputController.h"


TreeNode* _NIL;

typedef enum situation
{
	BlackFather,
	RedFatherRedUncle,
	RedFatherBlackUncle_Node_FatherFirst,
	RedFatherBlackUncle_Node_FatherSecond,
	RedFatherBlackUncle_NodeSecondFatherFirst,
	RedFatherBlackUncle_NodeFirstFatherSecond
} Situation;

TreeNode* GenerateNIL();
Tree* GenerateRBTree();






#endif //C_LAB_REDBLACKTREE_H
