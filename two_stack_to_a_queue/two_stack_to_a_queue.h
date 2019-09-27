#ifndef TWO_STACK_TO_A_QUEUE_H_INCLUDED
#define TWO_STACK_TO_A_QUEUE_H_INCLUDED
#define bool char
#define true 1
#define false 0

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

bool stackIsNillOrEmpty(pp_myStack ppmystack)
{
    return !ppmystack||!(*ppmystack)||!(*ppmystack)->capacity||!(*ppmystack)->size;
//    return !pptree||!(*pptree)||!(*pptree)->data||!(*pptree)->size;
}

#endif // TWO_STACK_TO_A_QUEUE_H_INCLUDED
