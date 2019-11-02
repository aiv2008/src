#ifndef BINARY_SEARCH_TREE_TO_TWO_WAY_LINKEDLIST_H_INCLUDED
#define BINARY_SEARCH_TREE_TO_TWO_WAY_LINKEDLIST_H_INCLUDED
#include "../binary_tree/binary_tree.h"


myBinrayTreeNode* convert(myBinrayTreeNode* pRoot);

void convertNode(myBinrayTreeNode* pNode, myBinrayTreeNode** ppLastNode);

void myBstTo2WayLinkedlist(myBinrayTreeNode* pRoot);

void myConvert(myBinrayTreeNode* pRoot, myBinrayTreeNode** pMoveLast);

#endif //BINARY_SEARCH_TREE_TO_TWO_WAY_LINKEDLIST
