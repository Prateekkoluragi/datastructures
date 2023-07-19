#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024 // Size of each file chunk
#define TABLE_SIZE 100 // Size of the hash table

typedef struct Chunk {
    char data[CHUNK_SIZE];
    struct Chunk* next;
} Chunk;

typedef struct HashEntry {
    unsigned long hashValue;
    Chunk* chunk;
    struct HashEntry* next;
} HashEntry;

HashEntry* hashTable[TABLE_SIZE];

// Hash function 1
unsigned long hash1(char* data) {
    unsigned long sum = 0,i;
    for (i = 0; i < CHUNK_SIZE; i++) {
        sum += data[i];
    }
    return sum;
}

// Hash function 2
unsigned long hash2(char* data) {
    unsigned long sum = 0,i;
    for (i = 0; i < CHUNK_SIZE; i++) {
        sum += data[i] * (i + 1);
    }
    return sum;
}

// Insert a chunk into the hash table
void insertChunk(Chunk* chunk) {
    unsigned long hashValue1 = hash1(chunk->data);
    unsigned long hashValue2 = hash2(chunk->data);
    int index = hashValue1 % TABLE_SIZE;

    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    newEntry->hashValue = hashValue2;
    newEntry->chunk = chunk;
    newEntry->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newEntry;
    } else {
        // Handle collision using double hashing
        int i = 1;
        int newIndex = (index + i * (hashValue2 % (TABLE_SIZE - 1))) % TABLE_SIZE;
        while (hashTable[newIndex] != NULL) {
            i++;
            newIndex = (index + i * (hashValue2 % (TABLE_SIZE - 1))) % TABLE_SIZE;
        }
        hashTable[newIndex] = newEntry;
    }
}

// Check if a chunk is a duplicate
int checkChunk(Chunk* chunk) {
    unsigned long hashValue1 = hash1(chunk->data);
    unsigned long hashValue2 = hash2(chunk->data);
    int index = hashValue1 % TABLE_SIZE;

    HashEntry* current = hashTable[index];
    while (current != NULL) {
        if (current->hashValue == hashValue2 && memcmp(current->chunk->data, chunk->data, CHUNK_SIZE) == 0) {
            return 1; // Duplicate chunk found
        }
        current = current->next;
    }

    return 0; // Chunk is unique
}

int main() {
    int i;
    // Initialize the hash table
    for (i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Simulate chunking and deduplication for a file
    FILE* file = fopen("example_file.txt", "rb");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    Chunk* chunk = (Chunk*)malloc(sizeof(Chunk));
    size_t bytesRead = fread(chunk->data, sizeof(char), CHUNK_SIZE, file);
    while (bytesRead > 0) {
        if (checkChunk(chunk)) {
            printf("Duplicate chunk found.\n");
        } else {
            printf("Unique chunk. Inserting into hash table.\n");
            insertChunk(chunk);
        }
        chunk = (Chunk*)malloc(sizeof(Chunk));
        bytesRead = fread(chunk->data, sizeof(char), CHUNK_SIZE, file);
    }

    fclose(file);

    return 0;
}
