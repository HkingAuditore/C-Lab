//
// Created by HkingAuditore on 2019/12/23.
//


#pragma once
#ifndef C_LAB_BALANCEDBINARYTREE_H
#define C_LAB_BALANCEDBINARYTREE__H
#include "TreeBasic.h"


typedef enum unbalanceType {
	Balanced, LL, RR, LR, RL
} UnbalanceType;

typedef enum nodeProcess {
	Add = 1, Delete = -1
} NodeProcess;


void StabilizeNode(UnbalanceType _type, TreeNode *_node, Tree *_tree, TreeNode* _crition);
Side GetChildSide(TreeNode *_parent, TreeNode *_child);
TreeNode *GetSideChild(TreeNode *_parent, Side _side);
TreeNode *SearchNode(ElementType _target, Tree *_tree);




#endif //C_LAB_BALANCEDBINARYTREE_H