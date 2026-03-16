// Srtf program with arival time
#include<stdio.h>
 void main()
 {
    int at[5],bt[5],p[5],tat[5],wt[5],rt[5],n,i,time=0,Minimum,Position,rn,temp,j;
    float atat=0.00,awt=0.00;
    printf("Enter the number of process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       printf("Enter p[%d]",i+1);
       scanf("%d",&p[i]);
       printf("Enter at[%d]",i+1);
       scanf("%d",&at[i]);
       printf("Enter bt[%d]",i+1);
        scanf("%d",&bt[i]); 
        rt[i]=bt[i];
    }
    rn=n;
    while(rn!=0)
    {
        Minimum=9999;
        Position=-1;
        for(i=0;i<n;i++)
        {
            if(at[i]<=time&&rt[i]!=0)
            {
                if(Minimum>rt[i])
                {
                    Minimum=rt[i];
                    Position=i;
                }
            }
        }
        if(Position!=-1)
        {
            rt[Position]--;
            time++;
            if(rt[Position]==0)
            {
             wt[Position]=time-at[Position]-bt[Position];
             tat[Position]=time-at[Position];
             rn--;
             atat +=tat[Position];
             awt +=wt[Position];
            }
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