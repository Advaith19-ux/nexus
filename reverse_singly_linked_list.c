#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
void linkedlisttraversal(struct node * ptr)
{
    while (ptr!=NULL)
    {
        printf("Element :%d \n",ptr->data);
        ptr=ptr->next;
    }
}
struct node * fun(struct node * head)
{
    struct node * curr=head,*pre=NULL,*post;
    while(curr!=NULL)
    {
        post=curr->next;
        curr->next=pre;
        pre=curr;
        curr=post;
    }
    return pre;
}
int main()
{
struct node * head;
struct node * second;
struct node * third;
struct node * fourth;
struct node * fifth;
struct node * sixth;
struct node * seventh;
struct node * eigth;

head=(struct node *)malloc(sizeof(struct node));
second=(struct node *)malloc(sizeof(struct node));
third=(struct node *)malloc(sizeof(struct node));
fourth=(struct node *)malloc(sizeof(struct node));
fifth=(struct node *)malloc(sizeof(struct node));
sixth=(struct node *)malloc(sizeof(struct node));
seventh=(struct node *)malloc(sizeof(struct node));
eigth=(struct node *)malloc(sizeof(struct node));

head->data=1;
head->next=second;

second->data=2;
second->next=third;

third->data=3;
third->next=fourth;

fourth->data=4;
fourth->next = fifth;

fifth->data=5;
fifth->next = sixth;

sixth->data=6;
sixth->next = seventh;

seventh->data=7;
seventh->next = eigth;

eigth->data=8;
eigth->next = NULL;

head=fun(head);
linkedlisttraversal(head);
return 0;
}