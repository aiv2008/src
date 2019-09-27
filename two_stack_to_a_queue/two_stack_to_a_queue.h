#ifndef TWO_STACK_TO_A_QUEUE_H_INCLUDED
#define TWO_STACK_TO_A_QUEUE_H_INCLUDED
#define bool char
#define true 1
#define false 0

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

bool stackIsNillOrEmpty(pp_myStack ppmystack)
{
    return !ppmystack||!(*ppmystack)||!(*ppmystack)->capacity||!(*ppmystack)->size;
//    return !pptree||!(*pptree)||!(*pptree)->data||!(*pptree)->size;
}

#endif // TWO_STACK_TO_A_QUEUE_H_INCLUDED
