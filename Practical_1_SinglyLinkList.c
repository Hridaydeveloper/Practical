#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert at end
void insert(struct Node **head, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete
void deleteNode(struct Node **head, int value) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

// Reverse
void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Display
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int n, value, deleteValue;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        insert(&head, value);
    }

    printf("\nOriginal List: ");
    display(head);

    // Delete
    printf("\nEnter value to delete: ");
    scanf("%d", &deleteValue);

    deleteNode(&head, deleteValue);

    printf("After deletion: ");
    display(head);

    // Reverse
    reverse(&head);

    printf("After reverse: ");
    display(head);

    return 0;
}
