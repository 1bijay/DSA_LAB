#include<stdio.h>
int  table_size = 10;

int generateKey(int value){
    return value%table_size;
}

int main(){
    int arr[] = {12, 44, 16, 83, 18},
    size = sizeof(arr)/sizeof(arr[0]),
    hasTable[table_size], key;

    for(int i = 0; i<table_size; i++)
        hasTable[i] = 0;

    for(int i = 0; i<size; i++){
        key = generateKey(arr[i]);
        hasTable[key] = arr[i];
    }

    printf("Displaying Hash Table...\n\n");
    printf("Index\tValue\n");
    for(int i = 0; i<table_size; i++){
        printf("%d\t%d\n", i, hasTable[i]);
    }
}