// a program mmul(a,b,c) to set up the structure for c = a*b .
#include <stdio.h>
#include <stdlib.h>
struct mat
{
    int a;
    struct mat *link;
};
int main()
{
    int m,ii,jj,n,p,sum=0,count=0;
    struct mat *a=NULL,*b=NULL,*temp=NULL,*ptra=NULL,*ptrb=NULL,*ta=NULL,*tb=NULL,*c=NULL,*ptrc=NULL,*t=NULL;
    printf("FOR MATRIX A, enter array size as MxN...\n");
    scanf("%dx%d",&m,&n);

    for(int i=0; i<m*n; i++)
    {
        temp=malloc(sizeof(struct mat));
        if(a==NULL)ptra=a=temp;
        else ptra=ptra->link=temp;
        ptra->a=0;

    }


   while(count<m*n/2)
    {
count++;
        printf("enter numbers index as i,j...\nelse enter -1 to quit matrix A\n");
        scanf("%d,%d",&ii,&jj);
        if(ii==-1)break;
             if(ii>m||ii<1||jj>n||jj<1)
        {
            printf("invalid entry...\n");
            count--;
            continue;
        }
        temp=a;
        for(int j=0; j<(ii-1)*n+jj-1; j++)
        {
            temp=temp->link;
        }


        printf("enter numbers...\n");
        scanf("%d",&(temp->a));

    }

count =0;
    printf("FOR MATRIX B, enter array size as NxP...\n");
    scanf("%dx%d",&n,&p);

    for(int i=0; i<p*n; i++)
    {
        temp=malloc(sizeof(struct mat));
        if(b==NULL)ptrb=b=temp;
        else ptrb=ptrb->link=temp;
        ptrb->a=0;

    }



   while(count<n*p/2)
    {
count++;
        printf("enter numbers index as i,j...\nelse enter -1 to quit matrix B\n");
        scanf("%d,%d",&ii,&jj);
        if(ii==-1)break;
        if(ii>n||ii<1||jj>p||jj<1)
        {
            printf("invalid entry...\n");
            count--;
            continue;
        }
        temp=b;
        for(int j=0; j<(ii-1)*p+jj-1; j++)
        {
            temp=temp->link;
        }

        printf("enter numbers...\n");
        scanf("%d",&(temp->a));

    }
    printf("\nmatrix A:\n");
    temp=a;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d  ",temp->a);
            temp=temp->link;
        }
        printf("\n");
    }
    printf("\nmatrix B:\n");
    temp=b;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<p; j++)
        {
            printf("%d  ",temp->a);
            temp=temp->link;
        }
        printf("\n");
    }

    for(int k=0; k<m; k++)
    {
        t=a;
        for(int slide=0; slide<n*k; slide++)t=t->link;

        for(int j=0; j<p; j++)

        {
            sum=0;
            ta=t;
            tb=b;
            for(int move=0; move<j; move++)tb=tb->link;

            for(int i=0; i<n; i++)
            {
                if(i!=0)
                {
                    ta=ta->link;
                    for(int slideb=0; slideb<p; slideb++)tb=tb->link;

                }

                sum+=ta->a * tb->a;
            }

            temp=malloc(sizeof(struct mat));
            if(c==NULL)ptrc=c=temp;
            else ptrc=ptrc->link=temp;
            ptrc->a=sum;
        }
    }

    temp=c;
    printf("\nmatrix AxB:\n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<p; j++)
        {
            printf("%d  ",temp->a);
            temp=temp->link;
        }
        printf("\n");
    }
    return 0;
}