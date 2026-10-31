#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];
int hashFunction(int key) {
    return key % SIZE;
}
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
      while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
         if (index == originalIndex) {
            printf("Hash Table is Full! Cannot insert %d\n", key);
            return;
        }}
    hashTable[index] = key;
}
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index; 
        }
        index = (index + 1) % SIZE;

        
        if (index == originalIndex) {
            break;
        }
    }
    return -1; 
}



int main(){





}