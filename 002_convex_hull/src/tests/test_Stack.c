/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : test_Stack
 * @created     : Sunday Jan 19, 2025 01:31:59 Pacific SA Daylight Time
 */

#include <stdio.h>
#include "Stack.h"

// Test the initialization of the stack
void test_Stack_Init() {
    Stack stack;
    Stack_Init(&stack);

    if (stack.top == -1) {
        printf("test_stackInit passed!\n");
    } else {
        printf("test_stackInit failed: Expected top = -1, got top = %d\n", stack.top);
    }
}

// Test pushing elements onto the stack
void test_Stack_Push() {
    Stack stack;
    Stack_Init(&stack);

    Stack_Push(&stack, 10);
    Stack_Push(&stack, 20);

    if (stack.top == 1 && stack.data[0] == 10 && stack.data[1] == 20) {
        printf("test_stackPush passed!\n");
    } else {
        printf("test_stackPush failed: Stack content mismatch.\n");
    }
}

// Test popping elements from the stack
void test_Stack_Pop() {
    Stack stack;
    Stack_Init(&stack);

    Stack_Push(&stack, 10);
    Stack_Push(&stack, 20);
    
    int popped;
    Stack_Pop(&stack, &popped);
    if (popped == 20 && stack.top == 0) {
        printf("test_stackPop passed!\n");
    } else {
        printf("test_stackPop failed: Expected 20, got %d or incorrect top index.\n", popped);
    }
}

// Test checking if the stack is empty
void test_Stack_IsEmpty() {
    Stack stack;
    Stack_Init(&stack);

    if (Stack_IsEmpty(&stack)) {
        printf("test_stackIsEmpty passed (empty case)!\n");
    } else {
        printf("test_stackIsEmpty failed (empty case): Expected true.\n");
    }

    Stack_Push(&stack, 10);
    if (!Stack_IsEmpty(&stack)) {
        printf("test_stackIsEmpty passed (non-empty case)!\n");
    } else {
        printf("test_stackIsEmpty failed (non-empty case): Expected false.\n");
    }
}

// Test peeking at the top of the stack
void test_Stack_Peek() {
    Stack stack;
    Stack_Init(&stack);

    Stack_Push(&stack, 10);
    Stack_Push(&stack, 20);

    int peeked = Stack_Peek(&stack);
    if (peeked == 20 && stack.top == 1) {
        printf("test_stackPeek passed!\n");
    } else {
        printf("test_stackPeek failed: Expected 20, got %d or incorrect top index.\n", peeked);
    }
}

// Main test function to run all tests
int main() {
    printf("Running Stack tests...\n");

    test_Stack_Init();
    test_Stack_Push();
    test_Stack_Pop();
    test_Stack_IsEmpty();
    test_Stack_Peek();

    printf("All Stack tests finished.\n");
    return 0;
}
