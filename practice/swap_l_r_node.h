#ifndef SWAP_L_R_NODE_H_INCLUDED
#define SWAP_L_R_NODE_H_INCLUDED
#define bool char
#define true 1
#define false 0

/**
核心思想: 1) 用二叉堆的方式实现(二叉堆的性质请自行百度),
建一个二叉堆数组, 每层节点的个数分别为2^0, 2^1, 2^2, ..., 即n个节点含有k = log(n)层
2) 每层的节点集合交换后有一个规律, 就是倒序重新排序
3) 举例: {4,5,2,6,7,8,2,1}, 按照规则会分成k = log(8) = 3层, 则划分后为
{4}, {5,2}, {6,7,8,2}, {1} (除了最后层, 其他都是满层, 这是二叉堆的特征),
4) 每层都逆序来排, 即排序后变成{4}, {2,5}, {2,8,7,6}, {1}, 所以左右子树交换后,
树结构变成{4,2,5,2,8,7,6,1}
5) 时间复杂度计算: T = 层数 *  每层消耗在倒序排序的时间 = log(n) * log(n) = (log(n))^2
这只是其中一个上界, 更精确的要推导一下
**/

typedef struct
{
    int* data;
    size_t size;
} tree, *p_tree, **p_p_tree;

void swap_l_r_node(p_p_tree pptree);

void init_node(p_p_tree pptree, int* header, size_t size);

void des_sort(p_p_tree pptree, size_t index_b, size_t index_e);

bool is_nul(p_p_tree pptree);

float my_log(int a, int b);

#endif // SWAP_L_R_NODE_H_INCLUDED
