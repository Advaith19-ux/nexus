#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack 
{
    int size;
    int top;
    char * arr;
};
int isFull(struct stack * st)
{
    if(st->top==st->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct stack * st)
{
    if(st->top==-1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack * st,char val)
{
    st->top++;
    st->arr[st->top]=val;
}
char pop(struct stack * st)
{
    if(isEmpty(st))
    {
        return '\0';
    }
    else 
    {
        int n=st->arr[st->top];
        st->top--;
        return n;
    }
}
int main()
{
    char exp[100];
    scanf("%s",exp); 
    int size=strlen(exp)/sizeof(char);
    struct stack * stak=(struct stack* )malloc(size*sizeof(char));
    
    stak->size=size;
    stak->top=-1;
    stak->arr=malloc(size*sizeof(char));
    int i=0;
    while(exp[i]!='\0')  
    {
        if(exp[i]=='(')
        {
            push(stak,'(');
        }
        else if(exp[i]==')')
        {
            if(isEmpty(stak))
            {
                printf("not a perfect use of brackets");
                free(stak->arr);
                free(stak);
                return 0;
            }
            else 
            {
                pop(stak);
            }
        }
        i++;
    }
    if(isEmpty(stak))
    {
        printf("Yes , a perfect use of brackets");
    }
    else 
    {
        printf("Not a perfect use of brackets");
    }
    free(stak->arr);
    free(stak);
    return 0;
}