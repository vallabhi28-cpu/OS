#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        printf("Enter Process ID: ");
        scanf("%d", &p[i].id);

        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].arrival_time);

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].burst_time);

        printf("Enter Priority (smaller number = higher priority): ");
        scanf("%d", &p[i].priority);

        p[i].remaining_time = p[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;

    while (completed < n) {

        int highest_priority = 9999;
        int selected_process = -1;

        for (int i = 0; i < n; i++) {

            if (p[i].arrival_time <= current_time && p[i].remaining_time > 0) {

                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    selected_process = i;
                }
            }
        }

        if (selected_process == -1) {
            current_time++;
        }
        else {

            p[selected_process].remaining_time--;
            current_time++;

            if (p[selected_process].remaining_time == 0) {

                p[selected_process].completion_time = current_time;

                p[selected_process].turnaround_time =
                    p[selected_process].completion_time -
                    p[selected_process].arrival_time;

                p[selected_process].waiting_time =
                    p[selected_process].turnaround_time -
                    p[selected_process].burst_time;

                completed++;
            }
        }
    }
     float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].id,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].priority,
               p[i].waiting_time,
               p[i].turnaround_time);

        avg_wt += p[i].waiting_time;
        avg_tat += p[i].turnaround_time;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
