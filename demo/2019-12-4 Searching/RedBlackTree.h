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

typedef enum situationInsert
{
	BlackFather,
	RedFatherRedUncle,
	RedFatherBlackUncle_Node_FatherFirst,
	RedFatherBlackUncle_Node_FatherSecond,
	RedFatherBlackUncle_NodeSecondFatherFirst,
	RedFatherBlackUncle_NodeFirstFatherSecond
} SituationInsert;

typedef enum situationDelete
{
	/*NO CHILD*/
	NoChild_Red, NoChild_Black_Root, NoChild_Black_NonRoot,
	/*ONE CHILD*/
	OneChild_Red, OneChild_Black
} SituationDelete;

TreeNode* GenerateNIL();
Tree* GenerateRBTree();

#endif //C_LAB_REDBLACKTREE_H
