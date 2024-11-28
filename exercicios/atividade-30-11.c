#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* init() {
    return NULL;
}

struct Node* create(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) { 
        printf("Erro ao alocar memória.\n"); 
        return NULL; 
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    struct Node* newNode = create(data);
    if (root == NULL) return newNode;

    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else 
            return root;
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

struct Node* search(struct Node* root, int key) {
    struct Node* current = root;

    while (current != NULL && current->data != key) {
        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return current;
}

int count(struct Node* root) {
    if (root == NULL) return 0;

    int count = 0;
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        count++;
        current = current->right;
    }

    return count;
}

void print(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100]; 
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

int main() {
    struct Node* root = init();

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Árvore em ordem: ");
    print(root);
    printf("\n");
    
    int key = 40;
    struct Node* found = search(root, key);
    if (found) 
        printf("Chave %d encontrada na árvore.\n", key);
    else 
        printf("Chave %d não encontrada na árvore.\n", key);

    int total = count(root);
    printf("Número de elementos na árvore: %d\n", total);

 return 0;
}