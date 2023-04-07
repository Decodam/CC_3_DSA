#include <stdio.h>

int MAX;

//Trevarsal Method
void travarsal(int arr[]){
    int i;

    for(i = 0; i < MAX; i++){
        printf("Element %d = %d \n", i, arr[i]);
    }
}

//Search Method
void linear_search(int arr[], int querry){
    int i;

    for(i = 0; i < MAX; i++){
        if(arr[i] == querry){
            printf("The number %d can be found on the %d index with location %p", querry, i, &arr[i]);
            break;
        }
        if (arr[i] != querry && i == MAX - 1){
            printf("The number %d is not found in the array", querry);
        }
        
    }
}

//Update Method
void update(int arr[], int index, int value){
    if (index >= MAX || index < 0){
        printf("Invalid input!!!");
    } else {
        arr[index] = value;
        printf("The new array is: \n");
        travarsal(arr);
    }
}

//Delete Method
void delete(int arr[], int index){
    int i;
    if (index >= MAX || index < 0){
        printf("Invalid input!!!");
    } else {
        for (i = index; i < MAX; i++){
            arr[i] = arr[i+1];
        }
        MAX = MAX-1;
        printf("The new array is: \n");
        travarsal(arr);
    }
}

//Insert End Method
void insertEnd(int arr[], int value){
    arr[MAX] = value;
    MAX = MAX + 1;
    printf("The new array is: \n");
    travarsal(arr);
}

//Insert Index Method
void insertIndex(int arr[], int index, int value){
    int i;

    if (index >= MAX || index < 0){
        printf("Invalid input!!!");
    } else {
        for (i = MAX; i > index; i--){
            arr[i] = arr[i-1];
        }
        arr[index] = value;

        MAX = MAX+1;
        printf("The new array is: \n");
        travarsal(arr);
    }
}


int main(){
    int arr[100];
    int choice, input, input2, i;

    printf("Enter the size of your array: "); scanf("%d", &MAX);
    printf("Enter the elements of your array: \n");
    for (i = 0; i < MAX; i++){
        scanf("%d", &arr[i]);
    }
    

    while (1)
    {
        printf("Enter ctrl+c to exit \n");
        printf("Enter 1 to traverse the array \n");
        printf("Enter 2 to search an element in the array \n");
        printf("Enter 3 to update an element in the array \n");
        printf("Enter 4 to delete an element in the array \n");
        printf("Enter 5 to insert an element in the array \n");
        printf("Enter 6 to insert an element in the end of the array \n");

        
        printf("\n");
        printf("Your Choice:  "); scanf("%d", &choice);
        printf("\n");


        switch (choice){
            case 1:
                printf("All elements of the array are: \n");
                travarsal(arr);
                printf("\n \n");
                break;
            case 2:
                printf("Enter the element you are searching for:  ");
                scanf("%d", &input);
                linear_search(arr, input);
                printf("\n \n");
                break;
            case 3:
                printf("Enter the index to be updated:  "); scanf("%d", &input);
                printf("The new value of index %d is:  ", input); scanf("%d", &input2);
                update(arr, input, input2);
                printf("\n \n");
                break;
            case 4:
                printf("Enter the index to be deleted:  "); scanf("%d", &input);
                delete(arr, input);
                printf("\n \n");
                break;
            case 5:
                printf("Enter the index to be inserted at:  "); scanf("%d", &input);
                printf("Enter the value to be inserted in the array:  "); scanf("%d", &input2);
                insertIndex(arr, input, input2);
                printf("\n \n");
                break;
            case 6:
                printf("Enter the value to be inserted at the end of the array:  "); scanf("%d", &input);
                insertEnd(arr, input);
                printf("\n \n");
                break;
            default:
                printf("Wrong input try again");
                printf("\n \n");
                break;
        }
        
        printf("==================================================================== \n \n");

    }

    return 0;
}