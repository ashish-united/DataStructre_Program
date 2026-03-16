// Code of fcfs without arival time
#include<stdio.h>
void main()
{
    int p[5],bt[5],wt[5],tat[5],n,time=0,i;
    float awt, atat;
    printf("Enter the number the process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter p[%d]",i+1);  // p = number of process
        scanf("%d",&p[i]);
        printf("Enter bt[%d]",i+1); // bt = Brust time
        scanf("%d",&bt[i]);
    }
   for(i=0;i<n;i++)
   {
    wt[i]=time;          // wt = wating time
    time=time + bt[i];
    tat[i]=time;        // tat = turnaround time
    awt=awt+wt[i];     // awt = average wating time
    atat=atat+tat[i];  // atat = average turnaround time
   }
   awt=awt/n;
   atat=atat/n;
   printf("\n p no. \t bt no.\t wt no.\t tat no.");
   for(i=0;i<n;i++)
   {
    printf("\n%d\t%d\t%d\t%d",p[i],bt[i],wt[i],tat[i]);
   }
   printf("\nAverage Wating time = %f",awt);
   printf("\nAverage Turn Around time =  %f",atat);
}