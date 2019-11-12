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
static void RecursionDLRNode(BinaryTreeNode* _node){
//    printf("IN!\n");
    if(_node){
        printf("%d ",ReadNode(_node));
        RecursionDLRNode(_node->LeftChild);
        RecursionDLRNode(_node->RightChild);
    }
}
static void RecursionDLR(BinaryTree* _tree){
     if(_tree){
         if(_tree->TreeSaverFlag==0){
             RecursionDLRNode(_tree->Tree.LinearTree->Root[LINEARINITPOS]);
         }else{
             RecursionDLRNode(_tree->Tree.LinkingTree->Root);
         }
     }
     printf("\n");
}
//递推前序遍历
static void RecurrenceDLR(BinaryTree* _tree){

}

/*中序遍历*/

//递归中序遍历
static void RecursionLDR(BinaryTree* _tree){

}
//递推中序遍历
static void RecurrenceLDR(BinaryTree* _tree){

}

/*后序遍历*/

//递归后序遍历
static void RecursionLRD(BinaryTree* _tree){

}
//递推后序遍历
static void RecurrenceLRD(BinaryTree* _tree){

}


static void TraversalBinaryTree(BinaryTree* _tree,int _type,int _inType){

}



#endif //C_LAB_BINARYTREETRAVERSAL_H
