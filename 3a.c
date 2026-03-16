#include<stdio.h>
void main()
{
    int a[10],i,f,temp;
    for(i=0;i<10;i++)
    {
        printf("Enter the number");
        scanf("%d",&a[i]); 
    } 
    for(i=0;i<10;i++)
    { if(a[i]>a[i+1])
   temp=a[i];
   a[i]=a[i+1];
   a[i+1]=temp;
    } 
   printf("Second largest number %d",a[8]);
}