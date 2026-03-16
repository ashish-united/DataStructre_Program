#include<stdio.h>
void main()
{
    int a[5],i,n,f=0;
    for(i=0;i<5;i++)
    {
    printf("Enter any 5 Number ");
    scanf("%d",&a[i]);
    }
    printf("Enter the number you want to search");
    scanf("%d",&n);
    for(i=0;i<5;i++)
    {
        if(a[i]==n)
        {
           f++;
           break; 
        }
    }
    if(f==1)
    {
        printf("Number found");
    }
    else
    {
        printf("Number not found");
    }
}
