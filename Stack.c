#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
typedef struct {
    element* data; //ptr for dynamic allocation
    int size;
    int top; //top index
}Stack;

void InitStack(Stack* s, int stack_size) { //Initialize stack
    s->data = (element*)malloc(sizeof(element) * stack_size); //Allocate size fo stack's size
    if (s->data == NULL) return;
    s->size = stack_size;
    s->top = -1; //top(int) indicate index
}
void PrintMenu() { //Menu
    printf("\n1. Push\n");
    printf("2. Pop\n");
    printf("3. Print\n");
    printf("4. Quit\n");
    printf("Command : ");
}
bool is_empty(Stack* s) { //empty = true / not empty = false
    return s->top == -1;
}
bool is_full(Stack* s) { //full = true / not full = false
    return s->top == s->size - 1;
}
void push(Stack* s) {
    if (is_full(s)) {
        printf("Stack is max.\n");
        return;
    }
    else {
        element input;
        printf("Push : ");
        scanf_s("%d", &input);
        s->top++;
        *(s->data + s->top) = input;
    }
}
void pop(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    else {
        printf("Pop : %d\n", *(s->data + s->top));
        s->top--;
    }
}
void printStack(Stack* s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("bottom | ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d | ", *(s->data + i));
    }
    printf("top\n");
}
int main(void) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) return -1; //NULLptr means fail to allocation

    int stack_size, input;
    bool quit = false;
    printf("Insert stack size : ");
    scanf_s("%d", &stack_size);
    InitStack(s, stack_size);

    while (!quit) { //if input == 4 to exit program
        PrintMenu();
        scanf_s("%d", &input);
        switch (input) {
        case 1: push(s); break;
        case 2: pop(s); break;
        case 3: printStack(s); break;
        case 4: quit = true; break;
        default: printf("Wrong input.\n");
        }
    }

    free(s->data);
    free(s);

    return 0;
}