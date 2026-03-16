#include<stdio.h>
void main()
{
     int a[100],i,n,f,l,target,midd;
     printf("Enter the number of element you want to enter");
     scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    printf("Enter any Number ");
    scanf("%d",&a[i]);
    }
    printf("Enter the number you want to search");
    scanf("%d",&target);
    l=n-1;
    f=0;
    while(f<=l)
    {
        midd=(f+l)/2;
    
    if(a[midd]==target)
    {
        printf("Number found");
        break;
    }
    else if(a[midd]>target)
    {
        l=midd-1;
    }
      else if(a[midd]<target)
    {
        f=midd+1;
    }
    else
    {
    printf("Number not found");
    }
    }
}