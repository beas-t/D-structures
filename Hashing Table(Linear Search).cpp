#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;

}
 HashEntry;

HashEntry hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1; // -1 indicates an empty slot
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    int originalIndex = index;

    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex) {
            printf("Hash table is full, unable to insert.\n");
            return;
        }
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
}


int search(int key) {
    int index = hash(key);
    int originalIndex = index;

    while (hashTable[index].key != -1) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
        if (index == originalIndex) {
            break; // Element not found
        }
    }

    return -1; // Element not found
}

int main() {
    initHashTable();

    int numEntries;
    printf("Enter the number of key-value pairs to insert: ");
    scanf("%d", &numEntries);

    for (int i = 0; i < numEntries; i++) {
        int key, value;
        printf("Enter key and value for pair %d: ", i + 1);
        scanf("%d %d", &key, &value);
        insert(key, value);
    }

    int searchKey;
    printf("Enter key to search for: ");
    scanf("%d", &searchKey);

    int searchResult = search(searchKey);
    if (searchResult != -1) {
        printf("Value for key %d: %d\n", searchKey, searchResult);
    } else {
        printf("Key %d not found in hash table.\n", searchKey);
    }

    return 0;
}
