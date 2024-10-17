#include <stdio.h>
#include <stdlib.h>

//Linear Search
int linearSearch(int arr[], int size, int element){
    for(int i=0; i <= element; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return 0;
}
// main function
int main(){

    int arr[] = {1, 2, 4, 6, 10, 23, 26, 55, 78, 90, 100};
    int size = (sizeof (arr)/sizeof (int));
    int x=0;
    printf("length of array is : %d\n", size);

    printf("enter element : ");
    scanf("%d", &x);

    int element = x;// storing value of x in element
    int searchIndex = linearSearch(arr, size, element);

    if(searchIndex != 0){
        printf("Element %d found at index %d.\n", element, searchIndex);   
    }else {
        printf("Element not found.\n");
    }
    //     printf("Search Index : %d \n", searchIndex);   

    return 0;
}