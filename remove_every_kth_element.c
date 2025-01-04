#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
void linkedlisttraversal(struct node * head)
{
    struct node * p=head;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}

struct node * fun(struct node * head,int k)
{
    struct node * curr=head;
    struct node * prev =NULL;
    int count=1;
    if(head==NULL||k<=1)
    {
        return NULL;
    }

    while(curr!=NULL)
    {
        if ((count%k)==0)
        {
            prev->next=curr->next;
            free(curr);
            curr=prev->next;
            count++;
        }
        else
        {
            prev=curr;
            curr=curr->next;
            count++;
        }
    }
    return head;
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

head=fun(head,3);
linkedlisttraversal(head);
return 0;
}