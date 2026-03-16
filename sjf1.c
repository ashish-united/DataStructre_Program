 // code of sjf without arival time with sorting of process according to their number.
#include<stdio.h>
void main()
{
    int p[5],bt[5],wt[5],tat[5],n,time=0,i,j,temp;
    float awt, atat;
    printf("Enter the number the process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter p[%d]",i+1); 
        scanf("%d",&p[i]);                  // p[] = number of process
         printf("Enter bt[%d]",i+1);        // bt[] = brust time
        scanf("%d",&bt[i]);  
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
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
    wt[i]=time;                  // wt[] = wating time
    time=time + bt[i];
    tat[i]=wt[i]+bt[i];          // tat[] = turnaround time
    awt=awt+wt[i];               // awt = average wating time
    atat=atat+tat[i];            // atat = average turnaround time
   }
   awt=awt/n;
   atat=atat/n;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(p[j]>p[j+1])
            {
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
   printf("\n p\tbt\twt\ttat");
   for(i=0;i<n;i++)
   {
    printf("\n %d\t%d\t%d\t%d",p[i],bt[i],wt[i],tat[i]);
   }
   printf("\nAverage Wating time = %f",awt);
   printf("\nAverage Turn Around time =  %f",atat);
}