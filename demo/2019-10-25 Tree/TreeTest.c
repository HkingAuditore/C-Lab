//
// Created by HkingAuditore 2019/10/25.
//


#include "BinaryTreeTraversal.h"

BinaryTree _TestTree;


int main() {
    BinaryTree tree = GenerateBinaryTree(1);
//    BinaryDLR(&tree,1);
//    BinaryLDR(&tree,1);
    TraversalBinaryTree(&tree, 0, 0);
    TraversalBinaryTree(&tree, 0, 1);
    TraversalBinaryTree(&tree, 1, 0);
    TraversalBinaryTree(&tree, 1, 1);
    TraversalBinaryTree(&tree, 2, 0);
    TraversalBinaryTree(&tree, 2, 1);
}
