#ifndef TWO_STACK_TO_A_QUEUE_H_INCLUDED
#define TWO_STACK_TO_A_QUEUE_H_INCLUDED
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct
{
    int* header;
    int size;//յʵ�ʴ�С(յ��Ԫ�ظ���)
    int capacity;//����
} myStack, *p_myStack, **pp_myStack;

//��ջ
void push(pp_myStack ppmystack, int data);

//��ջ
void pop(pp_myStack ppmystack);

//���ջ��Ԫ��
int* top(pp_myStack ppmystack);

void printStack(pp_myStack ppmystack);

BOOL stackIsNillOrEmpty(pp_myStack ppmystack);

#endif // TWO_STACK_TO_A_QUEUE_H_INCLUDED
