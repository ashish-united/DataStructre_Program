#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[100],n,i,j;
    while(1){
    printf("Enter the number you want to enter");
    scanf("%d",&n);
    if(n>100||n<0)
    {
        printf("wrong input");
        exit(0);
    }
}
    for(i=0;i<n;i++)
    {
        printf("enter the number");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted Array");
    for(i=0;i<n;i++)
    {
        printf(" %d",a[i]);
    }
}