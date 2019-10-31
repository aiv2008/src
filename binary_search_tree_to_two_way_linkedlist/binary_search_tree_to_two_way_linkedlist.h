#ifndef BINARY_SEARCH_TREE_TO_TWO_WAY_LINKEDLIST_H_INCLUDED
#define BINARY_SEARCH_TREE_TO_TWO_WAY_LINKEDLIST_H_INCLUDED
#include "../binary_tree/binary_tree.h"


myBinrayTreeNode* convert(myBinrayTreeNode* pRoot);

void convertNode(myBinrayTreeNode* pNode, myBinrayTreeNode** ppLastNode);

void bstTo2WayLinkedlist(myBinrayTreeNode* pRoot, myBinrayTreeNode** pLast);

#endif //BINARY_SEARCH_TREE_TO_TWO_WAY_LINKEDLIST
