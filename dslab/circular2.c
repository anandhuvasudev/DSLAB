#include <stdio.h>
#include <stdlib.h>

int *a; 
int front = 0, rear = 0, n, count = 0; 

void display() {
    int i;

    if (count == 0) {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nThe queue is:\n");
    for (i = 0; i < count; i++) {
        int index = (front + 1 + i) % n;
        printf("%d ", a[index]);
    }
    printf("\n");
}

void push() {
    if (count == n) { 
        printf("Queue overflow\n");
    } else {
        rear = (rear + 1) % n;
        printf("\nEnter the element to push: ");
        scanf("%d", &a[rear]);
        count++; 
        display();
    }
}

void pop() {
    if (count == 0) { 
        printf("Queue underflow\n");
    } else {
        front = (front + 1) % n;
        printf("\nPopped element %d from queue\n", a[front]);
        count--;
        display();
    }
}

void search() {
    int element, i, position = -1;

    if (count == 0) {
        printf("Queue is empty, nothing to search.\n");
        return;
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &element);

    for (i = 0; i < count; i++) {
        int index = (front + 1 + i) % n;
        if (a[index] == element) {
            position = i + 1;
            break;
        }
    }

    if (position != -1) {
        printf("Element %d found at position %d from the front.\n", element, position);
    } else {
        printf("Element %d not found in the queue.\n", element);
    }
}

int main() {
    int choice;

    printf("Enter the size of the circular queue: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Search\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: search();
                    break;
            case 5: 
                free(a);
                exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
