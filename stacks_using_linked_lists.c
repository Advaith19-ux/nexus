#include <stdio.h>
#include <stdlib.h>
//make sure to try the POP function in the stack implementation using linked lists 
struct node 
{
    int data;
    struct node * next;
};
int isempty(struct node * top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
int isfull(struct node * top)
{
    struct node * n=(struct node *)malloc(sizeof(struct node ));
    if(n==NULL)
    {
        return 1;
    }
    free(n);
    return 0;
}
void linkedlisttraversal(struct node * top)
{
    struct node * p=top;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}
struct node * push(int value,struct node * top )
{
    if(isfull(top))
    {
        printf("Stack Overflow");
        return top;
    }
    else
    {
        struct node * n=(struct node *)malloc(sizeof(struct node));
        n->data=value;
        n->next=top;
        return n;
    }
}
int pop(struct node ** ptr)     //sweet and sassy//make sure to try it again
{
    if(isempty(*ptr))
    {
        return -1;
    }
    else
    {
    struct node * n=*ptr;
    *ptr=(*ptr)->next;   
    int x=n->data;
    free(n);
    return x;
    }
}
int peek(struct node * top,int pos)
{
    struct node * ptr=top;
    int count =1;
    while(ptr!=NULL)
    {
        if(count==pos)
        {
            return ptr->data;
        }
        else
        {
            ptr=ptr->next;
            count++;
        }
    }
    return -1;
}
int stackTop(struct node * top)
{
    return top->data;
}
int stackBottom(struct node * top)
{
    struct node * p=top;
    while(p!=NULL && p->next!=NULL)
    {
        p=p->next;
    }
    return p->data;
}
int main()
{
    struct node * top=NULL;
    top=push(1,top);
    top=push(2,top);
    top=push(3,top);
    top=push(4,top);
    top=push(5,top);
    top=push(6,top);
    top=push(7,top);
    int x=peek(top,4);
    printf("%d\n",x);
    int t=stackTop(top);
    int b=stackBottom(top);
    printf("the top of the stack is %d\n ",t);
    printf("the bottom of the stack is %d ",b);
    return 0;
}