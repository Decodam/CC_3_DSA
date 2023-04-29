#include <stdio.h>
#include <stdlib.h>
 
// Linked List Node
struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;
 
// Function to create list with n nodes initially
void createList()
{
    if (start == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            int data;
            struct node* newnode;
            struct node* temp;
            newnode = malloc(sizeof(struct node));
            start = newnode;
            temp = start;
            printf("\nEnter number to"
                   " be inserted : ");
            scanf("%d", &data);
            start->info = data;
 
            for (int i = 2; i <= n; i++) {
                newnode = malloc(sizeof(struct node));
                temp->link = newnode;
                printf("\nEnter number to"
                       " be inserted : ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
}
 
// Function to traverse the linked list
void traverse(){
    struct node* temp;
 
    if (start == NULL){
        printf("\nList is empty\n");
    }else {
        temp = start;
        while (temp != NULL) {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}
 
// Function to insert at the front of the linked list
void insertAtFront(){
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));

    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);

    temp->info = data;
 
    temp->link = start;
    start = temp;
}
 
// Function to insert at the end of the linked list
void insertAtEnd(){
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
 
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
 
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}
 
// Function to insert at any specified position in the linked list
void insertAtPosition(){
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
 
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
 
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}
 
// Function to delete from the front of the linked list
void deleteFirst(){
    struct node* temp;
    if (start == NULL){
        printf("\nList is empty\n");
    } else {
        temp = start;
        start = start->link;
        free(temp);
    }
}
 
// Function to delete from the end of the linked list
void deleteEnd(){
    struct node *temp, *prevnode;
    if (start == NULL){
        printf("\nList is Empty\n");
    } else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}
 
// Function to delete from any specified position from the linked list
void deletePosition(){
    struct node *temp, *position;
    int i = 1, pos;
 
    // If LL is empty
    if (start == NULL){
        printf("\nList is empty\n");
    } else {
        printf("\nEnter index : ");
        scanf("%d", &pos);

        position = malloc(sizeof(struct node));
        temp = start;
 
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
 
        position = temp->link;
        temp->link = position->link;
 
        free(position);
    }
}
 
// Function to search an element in linked list
void search(){
    int found = -1;
    struct node* tr = start;
 
    if (start == NULL) {
        printf("Linked list is empty\n");
    }
    else {
        printf("\nEnter the element you want to search: ");
        int key;
        scanf("%d", &key);
 
        while (tr != NULL) {
            if (tr->info == key) {
                found = 1;
                break;
            } else {
                tr = tr->link;
            }
        }
 
        // printing found or not
        if (found == 1) {
            printf(
                "Yes, %d is present in the linked list.\n", key);
        } else {
            printf("No, %d is not present in the linked list.\n", key);
        }
    }
}
 
// Driver Code
int main(){
    int choice;
    while (1) {
        
        printf(" \n");
        printf("Enter 1 to TRAVERSE the array \n");
        printf("Enter 2 to INSERT AT FRONT in the linked list \n");
        printf("Enter 3 to INSERT AT END in the linked list \n");
        printf("Enter 4 to INSERT AT A POSITIONin the linked list \n");
        printf("Enter 5 to DELETE AT FIRST in the linked list \n");
        printf("Enter 6 to DELETE AT END in the linked list \n");
        printf("Enter 6 to DELETE AT A POSITION in the linked list  \n");
        printf("Enter 6 to SEARCH in the linked list  \n");
        printf("Enter 7 to exit \n");

        
        printf("\n");
        printf("Your Choice:  "); scanf("%d", &choice);
        printf("\n");
 
        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
        case 8:
            search();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}