#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;


void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = element;
        printf("Pushed element is %d\n", element);
    }
}

int pop() {
    int element;

    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        element = stack[top];
        top--;
        return element;
    }
}

void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Elements in the stack are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;

            case 2:
                element = pop();
                if (element != -1) {
                    printf("Popped element is %d\n", element);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

