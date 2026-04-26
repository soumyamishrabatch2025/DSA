#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void rangeSearch(Node* root, int low, int high) {
    if (!root) return;

    if (root->data > low)
        rangeSearch(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data < high)
        rangeSearch(root->right, low, high);
}

int main() {
    Node* root1 = NULL;
    int vals1[] = {17, 4, 18, 2, 9};
    for (int i = 0; i < 5; i++)
        root1 = insert(root1, vals1[i]);

    printf("Example 1 Output: ");
    rangeSearch(root1, 4, 24);
    printf("\n");

    Node* root2 = NULL;
    int vals2[] = {16, 7, 20, 1, 10};
    for (int i = 0; i < 5; i++)
        root2 = insert(root2, vals2[i]);

    printf("Example 2 Output: ");
    rangeSearch(root2, 13, 23);
    printf("\n");

    return 0;
}