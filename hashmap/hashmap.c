#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    char *val;
    struct node *next;
    struct node *prev;
} node;

node *create_node(int key, char *val, node *next) {
    node *temp = (node *) malloc(sizeof(node));
    temp->key = key;
    temp->val = (char *) malloc(strlen(val) * sizeof(char));
    strcpy(temp->val, val);
    temp->next = next;
    return temp;
}
node *root = NULL;
node *add(node *root, int key, char *val) {
    if (root == NULL) {
        return create_node(key, val, NULL);
    } 
    node* temp = root;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = create_node(key, val, NULL);
    return root;
}

node *delete(node *root, int key) {
    if (root == NULL) {
        printf("hash map empty\n");
        return root;
    }
    node *temp = root;
    if (temp->key == key) {
        node *to_be_freed = temp;
        printf("deleting :%d : %s\n", temp->key, temp->val);
        temp = temp->next;
        free(to_be_freed);
        return temp;
    }
    while (temp->next != NULL) {
        if (temp->next->key == key) {
            printf("deleting %d: %s\n", temp->next->key, temp->next->val);
            node *to_be_freed = temp->next;
            temp->next = temp->next->next;
            free(to_be_freed);
            return root;
        }
        temp = temp->next;
    }
    printf("couldn't find %d\n", key);
    return root;
}

void display(node *root) {
    if (root == NULL) {
        printf("nothing to print\n");
        return;
    }
    node *temp = root;
    while(temp != NULL) {
        printf("%d : %s\n", temp->key, temp->val);
        temp =temp->next;
    }
    return;
}

int main() {
    int opt = 0, insert_key;
    char *insert_val;
    do {
        printf("1. insert, 2. delete, 3. display, 4. exit: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                printf("enter the key: ");
                scanf("%d", &insert_key);
                printf("enter the value[str] for %d: ", insert_key);
                scanf("%s", insert_val);
                root = add(root, insert_key, insert_val);
                break;
            case 2:
                printf("Enter the key: ");
                scanf("%d", &insert_key);
                printf("deleting %d\n", insert_key);
                root = delete(root, insert_key);
                break;
            case 3:
                display(root);
                break;
            case 4:
                printf("bye\n");
                break;
            default:
                printf("invalid option\n");
                break;
            }
        } while(opt != 4);
    return 0;
}
