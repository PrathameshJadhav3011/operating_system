#include<stdio.h>
#include<conio.h> 
#define max 30
int main()
{
    int bt[max],p[max],wt[max],tat[max],pr[max];
    int i,j,n,total=0,pos,temp,avg_wt,avg_tat;
   
    printf("Enter Total Number of Process:");
    scanf("%d",&n); 
    printf("\nEnter the Burst Time and Priority of process\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contains process number
    } 
 
  //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    } 
    wt[0]=0; //waiting time for first process is zero 
   
 //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]= wt[i]+bt[j];
 
        total= total+wt[i];
    } 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nPriority\t   Process\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total=total+tat[i];
        printf("\n%d\t\t  P[%d]\t\t  %d\t\t    %d\t\t%d",pr[i],p[i],bt[i],wt[i],tat[i]);
    } 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d\n",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat); 
  getch();
  }


