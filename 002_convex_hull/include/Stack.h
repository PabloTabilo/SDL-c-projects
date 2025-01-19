/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : Stack
 * @created     : Friday Jan 17, 2025 19:35:28 Pacific SA Daylight Time
 */

#ifndef STACK_H

#define STACK_H

#include <stdbool.h>

#define MAX_STACK_SIZE 1000

typedef struct{
    int top;
    int data[MAX_STACK_SIZE];
}Stack;

void Stack_Init(Stack * stack);
bool Stack_IsEmpty(const Stack * stack);
bool Stack_IsFull(const Stack * stack);
bool Stack_Push(Stack * stack, int val);
bool Stack_Pop(Stack * stack, int * val);
int Stack_Peek(const Stack * stack);

#endif /* end of include guard STACK_H */

