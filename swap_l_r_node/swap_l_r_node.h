#ifndef SWAP_L_R_NODE_H_INCLUDED
#define SWAP_L_R_NODE_H_INCLUDED
#define bool char
#define true 1
#define false 0

/**
����˼��: 1) �ö���ѵķ�ʽʵ��(����ѵ����������аٶ�),
��һ�����������, ÿ��ڵ�ĸ����ֱ�Ϊ2^0, 2^1, 2^2, ..., ��n���ڵ㺬��k = log(n)��
2) ÿ��Ľڵ㼯�Ͻ�������һ������, ���ǵ�����������
3) ����: {4,5,2,6,7,8,2,1}, ���չ����ֳ�k = log(8) = 3��, �򻮷ֺ�Ϊ
{4}, {5,2}, {6,7,8,2}, {1} (��������, ������������, ���Ƕ���ѵ�����),
4) ÿ�㶼��������, ���������{4}, {2,5}, {2,8,7,6}, {1}, ������������������,
���ṹ���{4,2,5,2,8,7,6,1}
5) ʱ�临�Ӷȼ���: T = ���� *  ÿ�������ڵ��������ʱ�� = log(n) * log(n) = (log(n))^2
��ֻ������һ���Ͻ�, ����ȷ��Ҫ�Ƶ�һ��
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
