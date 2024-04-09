#include <stdio.h>
#include <math.h>
#define table_size 10

int HashFunction(int value, int count){
    return (value+(int)pow(count, 2)) % table_size;
}

int isFull(int hasTable[]){
    int count = 0;
    for (int i = 0; i < table_size; i++)
        if (hasTable[i] != -1)
            count++;

    if (count == table_size)
        return 1;
    else
        return 0;
}

void insertValue(int hasTable[], int key, int value){
    static int count = 0;
    if (isFull(hasTable)){
        printf("\nHash Table is Occupied cannot insert anymore");
        return;
    }
    if (hasTable[key] != -1){
        count++;
        key = HashFunction(value, count);
        insertValue(hasTable, key, value);
    }
    else
        hasTable[key] = value;
}

int main()
{
    int arr[] = {10, 40, 14, 83, 18, 19, 23, 44, 15, 16},
        size = sizeof(arr) / sizeof(arr[0]), key;
    int hasTable[table_size];

    for (int i = 0; i < table_size; i++)
        hasTable[i] = -1;

    for (int i = 0; i < size; i++){
        key = HashFunction(arr[i], 0);
        insertValue(hasTable, key, arr[i]);
    }

    printf("\nDisplaying Hash Table...\n");
    printf("Index\tValue\n");
    for (int i = 0; i < table_size; i++)
        printf("%d\t%d\n", i, hasTable[i]);
}