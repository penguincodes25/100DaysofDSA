/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }
    while (head1 && head2) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, val;
    struct Node *head1 = NULL, *head2 = NULL, *temp, *tail1 = NULL, *tail2 = NULL;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        temp = createNode(val);
        if (!head1) head1 = tail1 = temp;
        else {
            tail1->next = temp;
            tail1 = temp;
        }
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &val);
        temp = createNode(val);
        if (!head2) head2 = tail2 = temp;
        else {
            tail2->next = temp;
            tail2 = temp;
        }
    }

    struct Node* result = findIntersection(head1, head2);

    if (result)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}