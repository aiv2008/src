#include<stdio.h>
#include<stdlib.h>
#define NIL -50000000
typedef struct
{
	int data;
	struct NODE* parent;
	struct NODE* left;
	struct NODE* right;
	char color;
	int count;
}NODE;

NODE* node_init(unsigned int data)
{
    NODE* node = (NODE*)calloc(1,sizeof(NODE));
    node->data = data;
    node->count = 1;
    node->color = 'R';
    return node;
}

NODE* nil_node_init()
{
    NODE* root = (NODE*)calloc(1,sizeof(NODE));
    root->data = NIL;
    root->color = 'B';
    return root;
}

NODE* rotate_left(NODE* root)
{
    NODE* old_root = root->parent;
    NODE* parent = old_root->parent;
    NODE* left = root->left;
    NODE* right = root->right;
    if( NIL != left->data || NIL != right->data)
    {
        root->color = 'B';
        old_root->color = 'R';
    }
    node_rela_save(parent, root, parent?(root->data < parent->data?'l':'r') : ' ');
    node_rela_save(root, old_root, 'l');
    node_rela_save(old_root, left, 'r');
    return root;
}
NODE* rotate_right(NODE* root)
{
    NODE* old_root = root->parent;
    NODE* parent = old_root->parent;
    NODE* left = root->left;
    NODE* right = root->right;
    if( NIL != left->data || NIL != right->data)
    {
        root->color = 'B';
        old_root->color = 'R';
    }
    node_rela_save(parent, root, parent?(root->data < parent->data?'l':'r') : ' ');
    node_rela_save(root, old_root, 'r');
    node_rela_save(old_root, right, 'l');
    return root;
}
NODE* tree_rb_fixup(NODE* node)
{
    NODE* p = node;
    NODE* parent = node->parent;
    while(parent)
    {
        if(!('R' == p->color && parent->color == p->color))
            break;
        NODE* parent_parent = parent->parent;
        NODE* uncle = NULL;
        if(parent == parent_parent->left)
            uncle = parent_parent->right;
        else
            uncle = parent_parent->left;
        if('R' == uncle->color)
        {
            parent->color = 'B';
            parent_parent->color = 'R';
            uncle->color = 'B';
            p = parent_parent;
            parent = parent_parent->parent;
        }
        else
        {
            if(parent == parent_parent->left)
                //if parent is pp`s left child node, then rotate right
                p = p == parent->left?rotate_right(parent):rotate_right(rotate_left(p));
            else
                //if parent is pp`s right child node, then rotate left
                p = p == parent->left?rotate_left(rotate_right(p)):rotate_left(parent);
            parent = p->parent;
        }
    }
    return p;
}

NODE* tree_search(NODE* root, unsigned int data)
{
	if(!root)return NULL;
    NODE* p = root;
   	while( NIL != p->data)
    {
        if(data == p->data)
            break;
        else if(p->data < data)
            p = p->right;
        else
            p = p->left;
    }
    return p;
}

NODE* tree_insert(NODE** ppRoot, unsigned int data)
{
	if(!ppRoot)return NULL;
	if(!*ppRoot)
		*ppRoot = nil_node_init();
    //node is the new added node
    NODE* p = *ppRoot;
    if(NIL == p->data)
    {
        NODE* node = node_init(data);
        node_rela_save(node, *ppRoot, 'l');
        NODE* right_nil_node = nil_node_init();
        node_rela_save(node, right_nil_node, 'r');
        node->color = 'B';
        *ppRoot = node;
    }
    else
    {
        p = tree_search(*ppRoot, data);
        if( NIL != p->data )
            p->count++;
        else
        {
            NODE* node = node_init(data);
            NODE* parent = p->parent;
            node_rela_save(parent, node, node->data < parent->data?'l':'r');
            node_rela_save(node, p, 'l');
            NODE* right_nil_node = nil_node_init();
            node_rela_save(node, right_nil_node, 'r');
            p = tree_rb_fixup(node);
            if(!p->parent && 'R' == p->color)//if root is red, then rotate
                p->color = 'B';
        }
    }
    return p->parent?*ppRoot:p;
}

void node_rela_save(NODE* parent, NODE* child, unsigned char lof)
{
    child->parent = parent;
    if(parent)
        if('l' == lof)
            parent->left = child;
        else if('r' == lof)
            parent->right = child;
}

void calUniqueSize(NODE* pRoot, int* pSize)
{
	if(!pSize || !*pSize)return;
	if(NIL != pRoot->data)
	{
		int cn = calN(pRoot->count);
		*pSize = (*pSize) / cn;
		calUniqueSize(pRoot->left, pSize);
		calUniqueSize(pRoot->right, pSize);
	}	
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	if(!nums || !numsSize)return NULL;
	int size = calN(numsSize);
	NODE* pRoot = NULL;
	int i;
	for(i=0;i<numsSize;i++)
		pRoot = tree_insert(&pRoot, *(nums+i));
	calUniqueSize(pRoot, &size);
	free(pRoot);
	pRoot = NULL;
	printf("size=%d\n", size);
	int** result = (int**)calloc(size, sizeof(int*));
	int** resultMove = result;
	int* columnSizes = (int*)calloc(size, sizeof(int));
	int* columnSizesMove = columnSizes;
	permutation(nums, nums, numsSize, &resultMove, &columnSizesMove );
	//for(i=0;i<size;i++)
	//	printf("%d,", *(columnSizes+i));
	printf("\n");
	*returnSize = size;
	*returnColumnSizes = columnSizes;
	return result;	
}

void permutation(int* pStr, int* pBegin, int size, int*** pppMove, int** columnSizesMove)
{
	//if(*pppMove - result > resultSize)return;
	if(pBegin - pStr == size)
	{
		if(!*pppMove)printf("*pppMove is null\n");
		**pppMove  = (int*)calloc(size, sizeof(int));
		int i;
		int* pMove = **pppMove;
		int* p = pStr;
		for(i=0;i<size;i++)	
		{
			//*(pMove+i) = *(p+i);
			*(**pppMove+i) = *(p+i);
			//printf("%d,",*(pMove+i));
			//printf("%d,", *(**pppMove+i));
		}
		**columnSizesMove = size;
		//printf("\n");
		(*pppMove)++;
		(*columnSizesMove)++;
	}
	else
	{
		int* pMove ;
		NODE* pRoot = NULL;
		for(pMove = pBegin; pMove - pStr < size; ++pMove)
		{
			NODE* node = tree_search(pRoot, *pMove);
			if(!node || node->data == NIL)
			{
					pRoot = tree_insert(&pRoot, *pMove);
					//printf("---before---\n");
					//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
					int temp = *pMove;
					*pMove = *pBegin;
					*pBegin = temp;
					//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
					permutation(pStr, pBegin+1, size, pppMove, columnSizesMove);
					//printf("---after---\n");
					//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
					temp = *pMove;
					*pMove = *pBegin;
					*pBegin = temp;
					//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			}
		}
		free(pRoot);
		pRoot = NULL;
	}				
}

int calN(int n)
{
	int sum=1;
	while(n)
	{
		sum *= n--;
	}
	return sum;
}

