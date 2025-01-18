/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : Stack
 * @created     : Friday Jan 17, 2025 19:35:14 Pacific SA Daylight Time
 */

#include "Stack.h"
#include <stdio.h>


void Stack_Init(Stack * stack){
    stack->top = -1;
}

bool Stack_IsEmpty(const Stack * stack){
    return stack->top == -1;
}

bool Stack_IsFull(const Stack * stack){
    return stack->top == MAX_STACK_SIZE-1;
}

bool Stack_Push(Stack * stack, int val){
    if(Stack_IsFull(stack)){
	printf("Stack overflow\n");
	return false;
    }
    stack->data[++stack->top] = val;
    return true;
}

bool Stack_Pop(Stack * stack, int * val){
    if(Stack_IsEmpty(stack)){
	printf("Stack underflow\n");
	return false;
    }
    *val = stack->data[stack->top--];
    return true;
}

int Stack_Peek(const Stack * stack){
    if(Stack_IsEmpty(stack)){
	printf("Stack is empty\n");
	return -1;
    }
    return stack->data[stack->top];
}


