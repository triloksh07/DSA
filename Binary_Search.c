#include <stdio.h>
#include <stdlib.h>

// Binary Search
int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;

    while (low <= high){
        mid = (low + high)/2 ;
        if (arr[mid] == element){
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid+1;
        }else {
            high = mid-1;
        }
    }
    return 0;
}

int main(){

    int arr[] = {1, 2, 4, 6, 10, 23, 26, 55, 78, 90, 100};
    int size = sizeof (arr)/sizeof (int);
    int x=0;
    printf("enter element : ");
    scanf("%d", &x);
    int element = x;

    int searchIndex = binarySearch(arr, size, element);

    if(searchIndex != 0){
        printf("Element %d found at index %d.\n", element, searchIndex);   
    }else {
        printf("Element not found.\n");
    }
        // printf("Search Index : %d \n", searchIndex);   

    return 0;
}