#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct
                                                     Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node *subtractLists(struct Node *head1, struct Node *
                                                   head2)
{
    struct Node *result = NULL; 
    struct Node **lastRef = &result;
    int borrow = 0;
    while (head1 != NULL || head2 != NULL)
    {
        int diff = (head1 ? head1->data : 0) - (head2 ? head2->data : 0) - borrow;
        if (diff < 0)
        {
            diff = diff + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        *lastRef = createNode(diff);
        lastRef = &(*lastRef)->next;
        if (head1)
            head1 = head1->next;
        if (head2)
            head2 = head2->next;
    }
    return result;
}
 
void printList(struct Node *head)
{
    if (head == NULL) {
        return;
    }
    
    printList(head->next);
    
    printf("%d ", head->data);
}
void insertNode(struct Node **head, int data)
{
    struct Node *node = createNode(data);
    node->next = *head;
    *head = node;
}
int main()
{
    int n1, n2, i, x;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first linked list: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &x);
        insertNode(&head1, x);
    }
    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second linked list: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &x);
        insertNode(&head2, x);
    }
    printf("\nFirst linked list: ");
    printList(head1);
    printf("\nSecond linked list: ");
    printList(head2);
    struct Node *resultSubtract = subtractLists(head1, head2);
    printf("\nResult after subtracting the linked lists: ");
    printList(resultSubtract);
    return 0;
}
