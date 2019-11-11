//
// Created by HkingAudtire on 2019/11/11.
//

#ifndef C_LAB_BINARYTREELINKBASE_H
#define C_LAB_BINARYTREELINKBASE_H

#include <stdlib.h>
#include <stdio.h>

typedef int NodeData;

typedef struct binaryTreeLinkNode{
    struct binaryTreeLinkNode* Parent;
    struct binaryTreeLinkNode* LeftChild;
    struct binaryTreeLinkNode* RightChild;
    NodeData Data;
}BinaryTreeLinkNode;

typedef struct binaryTreeLink{
    BinaryTreeLinkNode* Root;
    int NumOfNodes;
}BinaryTreeLink;

//生成树
BinaryTreeLink* GenerateBinaryTreeLink(){
    BinaryTreeLink* tree;
    return tree;
}



#endif //C_LAB_BINARYTREELINKBASE_H
