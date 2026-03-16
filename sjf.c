//sjf without arival time and without sorting.
#include<stdio.h>
 void main()
 {
    int p[20],bt[20],tat[20],wt[20],n,j,i,temp,time=0;
    float atat=0.00,awt=0.00;
    printf("Enter the number of process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       printf("Enter p[%d]",i+1);     
       scanf("%d",&p[i]);          
       printf("Enter bt[%d]",i+1);
      scanf("%d",&bt[i]);               
    } 
    for(i=0;i<n;i++)
    {
     for(j=0;j<n-i-1;j++)
     {
        if(bt[j]>bt[j+1])
        {
            temp=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=temp;
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
        }
     }
    }
    for(i=0;i<n;i++)
    { 
     wt[i]=time;
     time +=bt[i];
     tat[i]=time;
     awt+=wt[i];
     atat=atat+tat[i];
    }  
    awt=awt/n;
    atat=atat/n;
    printf("\npno.\tbt no.\twt no.\ttat no.");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time: %f",awt);
    printf("\nAverage turnaround time: %f",atat);
}