#include <stdio.h>
#include <stdlib.h>

/*Defining the node structure*/
typedef struct node
{
    struct node *next;
    int data;
}node;

/*Prototypes*/
node *push(node *, int);
node *pop(node *, int *);
void display(node *);
int isEmpty(node *);

int main()
{
    node *head = NULL; // Start a node that points to NULL. This is repersent an empty stack linked list.
    int size, element, counter = 0;

    printf("Enter the number of elements in the stack. ");
    scanf("%d", &size);

    while(counter < size)
    {
        printf("Enter a number ");
        scanf("%d", &element);
        head = push(head, element); // add the element to the top of the stack.
        counter++;
    }

    while(!isEmpty(head)) // Keeping poping elements off the list until the stack is empty.
    {
        display(head);
        head = pop(head, &element);
    }

    return 0;
}

node *push(node *head, int data)  
{
   node *tmp = (struct node *)malloc(sizeof(struct node));
   tmp->data = data;
   tmp->next = head;
   head = tmp;   
   return head;
}

node *pop(node *head, int *element)
{
   node *tmp = head;
   *element = head->data;
   head = head->next;
   free(tmp);
   return head;
}

void display(node *head)
{
    node *current = head;

    printf("Stack: ");

    while(current != NULL)
    {
      printf("%d ",current->data);
      current = current->next;
    }

    printf("\n");
}

int isEmpty(node *head)
{
    return head == NULL ? 1 : 0;
}