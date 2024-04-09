#include<stdio.h>

int searchIt(int arr[], int value, int size){
    int i;
    for(i = 0; i<size; i++)
        if(arr[i] == value)
            return i;
    return -1;
}

int main(){
    int arr[]={8, 4, 5, 6, 1, 7};
    int size = sizeof(arr)/sizeof(int), 
    search_element = 7, index;

    index = searchIt(arr, search_element, size);

    if(index == -1){
        printf("Value not found\n");
        printf("Total comparision made is %d", size);
    }
    else{
        printf("Value found at index %d\n", index);
        printf("Total comparision made is %d", index+1);
    }
}