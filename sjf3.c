// code of sjf when there is gap btween p1 completion and p2 arival.
#include<stdio.h>
 void main()
 {
    int at[5],bt[5],p[5],tat[5],wt[5],rt[5],n,i,time=0,Minimum,Position,rn,temp,j;
    float atat=0.00,awt=0.00;
    printf("Enter the number of process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       printf("Enter p[%d]",i+1);     // p[] = number of process
       scanf("%d",&p[i]);
       printf("Enter at[%d]",i+1);
       scanf("%d",&at[i]);            // at[] = arival time
       printf("Enter bt[%d]",i+1);
        scanf("%d",&bt[i]);            // bt[] = burst time
        rt[i]=bt[i];                // rt[] = remaining time
    }
    rn=n;                          // rn = remaining number of process
    while(rn!=0)
    {
        Minimum=9999;
        Position=-1;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time&&rt[i]!=0)
            {
                if(Minimum>bt[i])
                {
                    Minimum=bt[i];
                    Position=i;
                }
            }
        }
        if(Position!=-1)
        {
        wt[Position]=time-at[Position];            // wt[] = wating time
        time +=bt[Position];
        tat[Position]=time-at[Position];           // tat[] = turnaround time
        rt[Position]=0;
        rn--;
        atat +=tat[Position];                // atat = average turnaround time
        awt +=wt[Position];                  // awt = average wating time
        }
        else 
        {
             time++;
        }
    }
    awt=awt/n;
   atat=atat/n;
   printf("\npno.\tat\tbt no.\twt no.\ttat no.");
   for(i=0;i<n;i++)
   {
    printf("\n%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
   }
   printf("\nAverage Wating time = %f",awt);
   printf("\nAverage Turn Around time =  %f",atat);
}