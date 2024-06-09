
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data)
{
    struct Node* newNode=createNode(data);
    newNode->next=*head;
    *head=newNode;
}
void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode=createNode(data);
    struct Node* temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
void deleteFromBeginning(struct Node** head)
{
    if(*head==NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }
    struct Node* temp=*head;
    *head=(*head)->next;
    free(temp);
}
void deleteFromEnd(struct Node** head)
{
    if(*head==NULL)
    {
        printf("Linked list is empty");
        return;
    }
    if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
        return;
    }
    struct Node* temp=*head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void deleteElement(struct Node** head, int data)
{
    if(*head==NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    if((*head)->data==data)
    {
        deleteFromBeginning(head);
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL && temp->next->data!=data)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        printf("element not found\n");
        return;
    }
    struct Node* toDelete=temp->next;
    temp->next=toDelete->next;
    free(toDelete);
}
void display(struct Node* head)
{
    if(head==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head=NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    display(head);
    deleteFromBeginning(&head);
    display(head);
    deleteFromEnd(&head);
    display(head);
    deleteFromEnd(&head);
    display(head);
    deleteElement(&head, 30);
    display(head);
    return 0;
}
