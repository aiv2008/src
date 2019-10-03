#ifndef TWO_STACK_TO_A_QUEUE_H_INCLUDED
#define TWO_STACK_TO_A_QUEUE_H_INCLUDED
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct
{
    int* header;
    int size;//盏实际大小(盏内元素个数)
    int capacity;//容量
} myStack, *p_myStack, **pp_myStack;

//入栈
void push(pp_myStack ppmystack, int data);

//出栈
void pop(pp_myStack ppmystack);

//输出栈顶元素
int* top(pp_myStack ppmystack);

void printStack(pp_myStack ppmystack);

BOOL stackIsNillOrEmpty(pp_myStack ppmystack);

#endif // TWO_STACK_TO_A_QUEUE_H_INCLUDED
