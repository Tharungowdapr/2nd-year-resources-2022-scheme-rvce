#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char line[80];
    struct node *rlink;
    struct node *llink;
};

char buffer[80];
char newline[80];
int n, d;

struct node *first, *temp;

void insert(char l[])
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->rlink = NULL;
    newnode->llink = NULL;
    strcpy(newnode->line, l);

    if (first == NULL)
    {
        first = newnode;
        temp = first;
    }
    else
    {
        newnode->llink = temp;
        temp->rlink = newnode;
        temp = newnode;
    }
}

void insertnew(char nl[], int p)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->rlink = NULL;
    newnode->llink = NULL;
    strcpy(newnode->line, nl);

    if (p == 1)
    {
        newnode->rlink = first;
        first->llink = newnode;
        first = newnode;
    }
    else
    {
        temp = first;
        for (int i = 0; i < p - 2 && temp != NULL; i++)
        {
            temp = temp->rlink;
        }
        if (temp == NULL || temp->rlink == NULL)
        {
            printf("Invalid position\n");
            free(newnode);
            return;
        }
        newnode->llink = temp;
        newnode->rlink = temp->rlink;
        temp->rlink->llink = newnode;
        temp->rlink = newnode;
    }
}

void display()
{
    struct node *temp1 = first;
    printf("\nDisplaying:\n");
    while (temp1 != NULL)
    {
        printf("%s\n", temp1->line);
        temp1 = temp1->rlink;
    }
}

void Delete(int p)
{
    temp = first;

    if (p == 1)
    {
        if (first == NULL)
        {
            printf("List is empty.\n");
            return;
        }
        first = first->rlink;
        if (first != NULL)
            first->llink = NULL;
        free(temp);
    }
    else
    {
        for (int i = 0; i < p - 1 && temp != NULL; i++)
        {
            temp = temp->rlink;
        }
        if (temp == NULL)
        {
            printf("Invalid position\n");
            return;
        }
        if (temp->llink != NULL)
            temp->llink->rlink = temp->rlink;
        if (temp->rlink != NULL)
            temp->rlink->llink = temp->llink;
        free(temp);
    }
}

int main()
{
    first = NULL;
    temp = NULL;

    printf("Enter few lines (type 'end' to stop):\n");
    while (1)
    {
        scanf(" %[^\n]", newline);
        if (strcmp(newline, "end") == 0)
            break;
        insert(newline);
    }
    display();

    printf("\nEnter the Line no. to insert: ");
    scanf("%d", &n);
    printf("Enter the Line to be inserted: ");
    scanf(" %[^\n]", buffer);
    insertnew(buffer, n);
    display();

    printf("\nEnter the line to be deleted: ");
    scanf("%d", &d);
    Delete(d);
    display();

    return 0;
}
