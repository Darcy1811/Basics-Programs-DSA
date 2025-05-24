#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* CreateNode(int value) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory Allocation failed!");
    } else {
        new->data = value;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
}

struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return CreateNode(value);
    } else {
        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct node* search(struct node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    } else {
        if (value < root->data) {
            return search(root->left, value);
        } else {
            return search(root->right, value);
        }
    }
}

int calculateHeight(struct node* root) {
    if (root == NULL) {
        return -1; // Height is defined as the number of edges on the longest path from the root to a leaf
    } else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

int main() {
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 11);
    insert(root, 22);
    insert(root, 33);
    insert(root, 44);
    insert(root, 55);
    insert(root, 66);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    int searchValue = 66;
    struct node* searchResult = search(root, searchValue);
    if (searchResult != NULL) {
        printf("Value %d found in the binary search tree.\n", searchValue);
    } else {
        printf("Value %d not found in the binary search tree.\n", searchValue);
    }

    printf("Height of the binary tree: %d\n", calculateHeight(root));

    return 0;
}
