// Non-Preemptive Priority Scheduling Algorithm in C    
// We are assuming that before completion of a process, the next process is arrived. 
#include<stdio.h>
void main()
{
    int at[10], bt[10], p[10], pr[10], tat[10], wt[10];
    int n, i, j, time = 0, completed = 0, pos;
    float atat = 0.0, awt = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter process id p[%d]: ", i+1);
        scanf("%d", &p[i]);
        printf("Enter arrival time at[%d]: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter burst time bt[%d]: ", i+1);
        scanf("%d", &bt[i]);
        printf("Enter priority pr[%d] (smaller number = higher priority): ", i+1);
        scanf("%d", &pr[i]);
    }

    int done[10] = {0}; // track completed processes

    while(completed < n)
    {
        pos = -1;
        int minPriority = 9999;

        // find process with highest priority among arrived ones
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time)
            {
                if(pr[i] < minPriority && done[i] == 0)
                {
                    minPriority = pr[i];
                    pos = i;
                }
            }
        }

            time += bt[pos]; // run to completion
            tat[pos] = time - at[pos];
            wt[pos] = tat[pos] - bt[pos];
            done[pos] = 1;
            completed++;
            atat += tat[pos];
            awt += wt[pos];
    }
    atat /= n;
    awt /= n;

    printf("\nPNo.\tAT\tBT\tPR\tWT\tTAT");
    for(i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", atat);
}