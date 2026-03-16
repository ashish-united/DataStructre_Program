// Code of fcfs with arival time
#include<stdio.h>
void main()
{
    int p[5],at[5],bt[5],wt[5],tat[5],n,time=0,i,j,temp;
    float awt, atat;
    printf("Enter the number the process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter p[%d]",i+1);
        scanf("%d",&p[i]);       // p[]= process number
        printf("Enter at[%d]",i+1);
        scanf("%d",&at[i]);      // at[]= Arival time
         printf("Enter bt[%d]",i+1);
        scanf("%d",&bt[i]);      // bt[]=  Brust time
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(at[j]>at[j+1])
            {
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;

            }
        }
    }
   for(i=0;i<n;i++)
   {
    wt[i]=time-at[i];      // wt  = wating time
    time=time + bt[i];
    tat[i]=time-at[i];     // tat = turn around time
    awt=awt+wt[i];         // awt = average wating time
    atat=atat+tat[i];      // atat = average turnaround time
   }
   awt=awt/n;
   atat=atat/n;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(p[j]>p[j+1])
            {
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                temp=tat[j];
                tat[j]=tat[j+1];
                tat[j+1]=temp;
                temp=wt[j];
                wt[j]=wt[j+1];
                wt[j+1]=temp;

            }
        }
    }
   printf("\nprocess\tat\tbt\twt\ttat"); 
   for(i=0;i<n;i++)
   {
    printf("\n%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
   }
   printf("\nAverage Wating time = %f",awt);
   printf("\nAverage Turn Around time =  %f",atat);
}