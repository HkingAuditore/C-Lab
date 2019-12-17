//
// Created by HkingAuditore on 2019/12/4.
//

#ifndef C_LAB_TREEBASIC_H
#define C_LAB_TREEBASIC_H

#include <stdio.h>
#include <stdlib.h>
#include "OutputController.h"

//数据类型
typedef int ElementType;
//位置
typedef enum side {
    NoValid, Left, Right
} Side;
//结点
typedef struct treeNode {
    ElementType Data;
    struct treeNode *LeftChild, *RightChild, *Parent;
    int BalanceFactor;
    int Height;
} TreeNode;
//树
typedef struct tree {
    TreeNode *Root;
    int NumOfNodes;
} Tree;
//旋转方向
typedef enum direction {
    TurnLeft, TurnRight
} Direction;
typedef enum traversalMode {
    /*前序*/
            DLR,
    /*中序*/
            LDR,
    /*后序*/
            LRD
} TraversalMode;

//生成节点
static TreeNode *GenerateNode(ElementType _rootData);

//生成初始树
static Tree *GenerateTree(ElementType _rootData);

//给已知节点加入叶子
static int AppendLeaf(TreeNode *_target, TreeNode *_leaf, Side _side);

//获取空闲位置
static Side GetValidSide(TreeNode *_node);

//对于查找树，根据大小返回位置
static Side GetComparedSide(TreeNode *_node, TreeNode *_follow);

//获取根据大小得出的新节点在查找树中的合适位置
static TreeNode *GetValidPosition(Tree *_tree, TreeNode *_node);

//遍历树
static int TraversalTree(const Tree *_tree, TraversalMode _mode,void(*_function)(TreeNode *));

//旋转Pivot节点
static int RotateNode(TreeNode *_pivot, Direction _dir, Tree *_tree);

//输出结点
static void WriteNode(TreeNode *_node);

//结点高度计算
static void NodeHeightCalculator(TreeNode *_node);

//结点信息输出
static void NodeInfoOutput(TreeNode *_node);

#endif //C_LAB_TREEBASIC_H

