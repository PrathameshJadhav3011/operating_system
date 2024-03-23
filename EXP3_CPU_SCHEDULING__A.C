#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,bt[100],wt=0,tat=0;
    float avg_wt,avg_tat;
    
    printf("Enter a number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of process[%d]",i+1);
        scanf("%d",&bt[i]);
    }
    printf("\npid\t\tBT\t\tWT\t\tTAT");
    for(i=0;i<n;i++)
    {
        tat=bt[i]+wt;
        printf("\n%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt,tat);
        avg_wt=avg_wt+wt;
        avg_tat=avg_tat+tat;
        wt=wt+bt[i];
    }
    avg_wt=avg_wt/n;
    avg_tat=avg_tat/n;

    printf("\nAverage waiting time is:%f",avg_wt);
    printf("\nAverage turn around time is:%f",avg_tat);
    getch();
    
}