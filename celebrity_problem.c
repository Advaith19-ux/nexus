#include <stdio.h>
#include <stdlib.h>

int celeb(int **mat,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==1)
            {
                break;
            }
            if(j==n-1)
            {
                return i;
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int **mat=(int **)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        mat[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter the element mat[%d][%d]",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
    printf("%d",celeb(mat,n));
    return 0;
}