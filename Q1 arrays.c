#include<stdio.h>
int main()
{
	int p1[100],p2[100],prod[100]={};
	int i,j,n;
	printf("Enter number of coeffiecients of first polynomial\n");
	scanf("%d",&n);
	printf("Enter coeffiecients\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",p1[i]);		
	}
	printf("Enter number of coeffiecients of second polynomial\n");
	scanf("%d",&n);
	printf("Enter coeffiecients\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",p2[i]);		
	}
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			prod[i+j]=prod[i+j]+p1[i]*p2[j];
		}
	}
}
