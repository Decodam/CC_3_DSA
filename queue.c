/*
WAP C PROGRAM TO IMPLEMENT A QUEUE DATA STRCUTURE USING LINKED LIST.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node * next;
} Node;
 
Node *front = NULL;
Node *rear = NULL;
  
// To Check if the Queue is empty
int isEmpty(){
    if(front == NULL && rear == NULL){
        return 1;
    } else {
        return 0;
    }
}

// To enter new element in the Queue
void enqueue(){
    int d;

    printf("Enter the data to be enqueued: ");
    scanf("%d", &d);

    struct Node* new_n;
    new_n = (struct Node*)malloc(sizeof(struct Node));
    new_n -> data = d;
    new_n -> next = NULL;
    if(isEmpty()){
        front = rear = new_n;
    } else {
        rear -> next = new_n;
        rear = new_n;
    }
}

// To remove element from the Queue
void dequeue(){
    if(isEmpty()){
        printf("Queue is empty \n");
    } else if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        Node* temp = front;
        front = front -> next;
        free(temp);
    }
}

// To display the Queue 
void display(){
    struct Node* temp;
    if(isEmpty()){
        printf("Queue is Empty \n");
    } else {
        temp = front;
        while(temp){
            printf ("%d", temp->data);
            temp = temp->next;
        }
    } 
}

// To peek the first element of the Queue
void peek(){
    if(isEmpty()){
        printf("The queue is empty!");
    } else {
        printf("Element at the front of the queue: %d\n", front-> data);
    }
}


int main()
{
    int choice;

    while (1){
        printf("\n\nMenu:\n");
        printf("Press 1 to ENTER an element in the queue\n");
        printf("Press 2 to REMOVE an element in the queue\n");
        printf("Press 3 to PEEK the first element in the queue\n");
        printf("Press 4 to Display the full Queue\n");
        printf("Press 5 to Exit\n");

        printf("\nYour Choice: "); scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again!");
            break;
        }
    }
    
}