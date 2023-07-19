#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

/*void storePreOrder(struct Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }
    fprintf(file, "%d ", root->data);
    storePreOrder(root->left, file);
    storePreOrder(root->right, file);
}

void storeInOrder(struct Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }
    storeInOrder(root->left, file);
    fprintf(file, "%d ", root->data);
    storeInOrder(root->right, file);
}

void storePostOrder(struct Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }
    storePostOrder(root->left, file);
    storePostOrder(root->right, file);
    fprintf(file, "%d ", root->data);
}*/

int main() {
    struct Node* root = NULL;
    int i, num, count;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements to generate: ");
    scanf("%d", &count);

    FILE* randomNumberFile = fopen("random_numbers.txt", "w");
    if (randomNumberFile == NULL) {
        printf("Failed to open random_numbers.txt\n");
        return 1;
    }


    srand(time(NULL));

    for (i = 0; i < count; i++) {
        num = rand() % 100;
        fprintf(randomNumberFile, "%d ", num);
        root = insertNode(root, num);
    }
    fclose(randomNumberFile);
    printf("Random numbers stored in random_numbers.txt\n");

    /*FILE* preOrderFile = fopen("preorder.txt", "w");
    if (preOrderFile == NULL) {
        printf("Failed to open preorder.txt\n");
        return 1;
    }
    start = clock();
    storePreOrder(root, preOrderFile);
    end = clock();
    fclose(preOrderFile);
    cpu_time_used = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);
    printf("Pre-order traversal stored in preorder.txt\n");
    printf("Time taken for pre-order traversal: %.2f ms\n", cpu_time_used);

    FILE* inOrderFile = fopen("inorder.txt", "w");
    if (inOrderFile == NULL) {
        printf("Failed to open inorder.txt\n");
        return 1;
    }
    start = clock();
    storeInOrder(root, inOrderFile);
    end = clock();
    fclose(inOrderFile);
    cpu_time_used = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);
    printf("In-order traversal stored in inorder.txt\n");
    printf("Time taken for in-order traversal: %.2f ms\n", cpu_time_used);

    FILE* postOrderFile = fopen("postorder.txt", "w");
    if (postOrderFile == NULL) {
        printf("Failed to open postorder.txt\n");
        return 1;
    }
    start = clock();
    storePostOrder(root, postOrderFile);
    end = clock();
    fclose(postOrderFile);
    cpu_time_used = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);
    printf("Post-order traversal stored in postorder.txt\n");
    printf("Time taken for post-order traversal: %.2f ms\n", cpu_time_used);*/

    return 0;
}
