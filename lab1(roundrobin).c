#include <stdio.h>

int main() {
    int n, tq;
    printf("USN:1BF24CS328 \n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n], rt_resp[n];
    int queue[100], front = 0, rear = 0;
    int visited[n];

    printf("Enter arrival times:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter burst times:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        visited[i] = 0;
        rt_resp[i] = -1;
    }

    int current_time = 0, completed = 0;

    queue[rear++] = 0;
    visited[0] = 1;

    while(front < rear) {

        int i = queue[front++];

        if(rt_resp[i] == -1)
            rt_resp[i] = current_time - at[i];

        if(rt[i] > tq) {
            current_time += tq;
            rt[i] -= tq;
        }
        else {
            current_time += rt[i];
            rt[i] = 0;

            ct[i] = current_time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            completed++;
        }

        for(int j = 0; j < n; j++) {
            if(at[j] <= current_time && visited[j] == 0) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        if(rt[i] > 0)
            queue[rear++] = i;

        if(front == rear) {
            for(int j = 0; j < n; j++) {
                if(rt[j] > 0) {
                    queue[rear++] = j;
                    visited[j] = 1;
                    break;
                }
            }
              }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nRRS scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt_resp[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage turnaround time: %.6fms\n", avg_tat/n);
    printf("Average waiting time: %.6fms\n", avg_wt/n);

    return 0;
}
