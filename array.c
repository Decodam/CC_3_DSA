/*
C PROGRAM FOR IMPLIMENTING ARRAY DATA STRUCTURE. IT IS DESIGNED TO CONDUCT
DATA STRUCTURE OPERATIONS ON AN ARRAY OF SIZE 5
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int current_index = 0;
int arr[MAX];


// TRAVERSE ALGORITHM
void traverse(){
    int i;

    if(current_index == 0){
        printf("Operation not possible, array is EMPTY!");
    }else{
        printf("The array elements are:    ");
    
        for (i = 0; i < current_index; i++){
            printf("%d  ", arr[i]);
        }
    }
    
}


// INSERT ALGORITHM
void insert(int pos, int value){
    if (pos < 0 || pos > current_index) {
        printf("Invalid position\n");
        return;
    }
    for (int i = current_index-1; i >= pos; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = value;
    current_index++;
}


// SEARCH ALGORITHM
void search(int value){
    int i, counter = 0;

    for(i = 0; i < current_index; i++){
        if(arr[i] == value){
            printf("Element is found at position %d \n", i+1);;
            counter++;
        }
    }

    if (counter == 0){
        printf("Element is found in the array!\n");
    }
    
}


// UPDATE ALGORITHM
void update(int pos, int value){
    if (pos < 0 || pos > current_index) {
        printf("Invalid position\n");
        return;
    } else {
        arr[pos-1] = value;
    }
}


// DELETE ALGORITHM
void delete(int pos) {
    if (pos < 0 || pos >= current_index) {
        printf("Invalid position\n");
        return;
    }
    for (int i = pos; i < current_index-1; i++) {
        arr[i] = arr[i+1];
    }
    current_index--;
}


// MAIN APP FUNCTION
int main(){
    int choice, input1, input2;

    printf("New array of size 5 initialized... \n");

    while (1){
        printf("Enter 0 to EXIT  \n");
        printf("Enter 1 to TRAVERSE  \n");
        printf("Enter 2 to INSERT  \n");
        printf("Enter 3 to SEARCH  \n");
        printf("Enter 4 to UPDATE  \n");
        printf("Enter 5 to DELETE  \n");

        printf("\nEnter your choice:    "); scanf("%d", &choice);
        printf("\n");

        switch (choice){
            case 0:
                printf("Thank You!");
                exit(0);
                break;

            case 1:
                traverse();
                break;

            case 2:
                printf("Enter the POSITION to be inserted:  "); scanf("%d", &input1);
                printf("Enter the VALUE to be inserted:  "); scanf("%d", &input2);
                
                insert(input1, input2);
                break;

            case 3:
                printf("Enter the VALUE to be searched:  "); scanf("%d", &input1);
                search(input1);
                break;

            case 4:
                printf("Enter the POSITION to be updated:  "); scanf("%d", &input1);
                printf("Enter the new VALUE:  "); scanf("%d", &input2);
                
                update(input1, input2);
                break;

            case 5:
                printf("Enter the POSITION to be deleted:  "); scanf("%d", &input1);
                delete(input1);
                break;
            
            default:
                printf("Wrong choice! Try again...  \n");
                break;
        }

        printf("\n\n");
    }
    

    return 0;
}