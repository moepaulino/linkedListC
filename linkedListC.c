#include <stdio.h>
#include <stdlib.h>

// Leandro Paulino
// This program creates a Linked List, accepts user input,
// and returns those values in reverse order.


struct node // structure to create linked list
{
    int value;
    struct node *next;
}node;

void printLst(struct node *head); // prints the linked list
void reverse(struct node **head); // reverses the Linked List
void insert(struct node **head, int data); // create Linked List and insert value into it

int main()
{
    int n = 0;
    int i = 1;
    struct node *HEAD = NULL;
    printf("Input data for node %d : ", i++);
    while(scanf("%d",&n) != EOF)
    {
        printf("Input data for node %d : ", i++);
        insert(&HEAD, n);
    }  
    /*
		I had to reverse the list to print it normally,
		and then reverse it again to get reversed list.
	*/
    reverse(&HEAD); // reverse list to get normal list
    printLst(HEAD); // print list
    reverse(&HEAD); // reverse again to get reversed list
	printLst(HEAD); // print list again
    
    return 0;
}

void insert(struct node **head, int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    newNode->value = data;
    newNode->next = *head;
    *head = newNode;
}

void reverse(struct node **head)
{
    struct node* prevNode = NULL;
    struct node* currNode = *head;
    struct node* next = NULL;
    while (currNode != NULL) {
        // Store next
        next = currNode->next;

        // Reverse current node's pointer
        currNode->next = prevNode;

        // Move pointers one position ahead.
        prevNode = currNode;
        currNode = next;
    }
    *head = prevNode;
}
void printLst(struct node *head)
{
    struct node *p = head;

    printf("\nData entered in the list are:\n");
    while (p != NULL) // if node is not NULL
    {
        printf("Data = %d\n",p->value);
        p = p->next;
    }
}

