#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

NODE createbst(NODE root, int key) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = key;
    temp->left = temp->right = NULL;

    if (root == NULL) {
        return temp;
    }

    struct node *cur = root;
    struct node *prev = NULL;
    while (cur != NULL) {
        prev = cur;
        if (key < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    // Now cur is NULL; prev is the parent where we should attach
    if (key < prev->data) {
        prev->left = temp;
    } else {
        prev->right = temp;
    }
    return root;
}

void preorder(NODE root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(NODE root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

int main() {
    NODE root = NULL;
    int item, ch;

    for (;;) {
        printf("\n1. Insert\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                root = createbst(root, item);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
