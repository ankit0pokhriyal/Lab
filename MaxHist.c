#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize stack
void initializeStack(struct Stack *st) {
    st->top = -1;
}

// Check if stack is empty
bool isEmpty(struct Stack *st) {
    return st->top == -1;
}

// Push element onto stack
void push(struct Stack *st, int value) {
    if (st->top < MAX_SIZE - 1) {
        st->top++;
        st->arr[st->top] = value;
    }
}

// Pop element from stack
int pop(struct Stack *st) {
    if (!isEmpty(st)) {
        int value = st->arr[st->top];
        st->top--;
        return value;
    }
    return -1; // Return -1 to indicate an empty stack
}

//Solution Logic implementataion

int largestRectangleArea(int *heights, int n) {
    int left[MAX_SIZE], right[MAX_SIZE];
  struct Stack mystack;
 // Left  side
    initializeStack(&mystack);

    for (int i = 0; i < n; i++) {
        while (!isEmpty(&mystack) && heights[mystack.arr[mystack.top]] >= heights[i]) {
            pop(&mystack);
        }
        left[i] = isEmpty(&mystack) ? 0 : mystack.arr[mystack.top] + 1;
        push(&mystack, i);
    }
// Right side
    initializeStack(&mystack);

    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(&mystack) && heights[mystack.arr[mystack.top]] >= heights[i]) {
            pop(&mystack);
        }
        right[i] = isEmpty(&mystack) ? n - 1 : mystack.arr[mystack.top] - 1;
        push(&mystack, i);
    }
// Maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] + 1;
        int newArea = heights[i] * width;
        if (newArea > maxArea) {
            maxArea = newArea;
        }
    }

    return maxArea;
}


int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int n = sizeof(heights) / sizeof(heights[0]);
    printf("Largest Area: %d\n", largestRectangleArea(heights, n));

    return 0;
}