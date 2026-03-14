#include <stdio.h>
#include <stdbool.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    bool completed;
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

        p[i].completed = false;
    }

    int current_time = 0;
    int completed_count = 0;

    while (completed_count < n) {

        int highest_priority = 9999;
        int selected_process = -1;

        for (int i = 0; i < n; i++) {

            if (p[i].arrival_time <= current_time && p[i].completed == false) {

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
            int start_time = current_time;

            p[selected_process].completion_time =
                start_time + p[selected_process].burst_time;

            p[selected_process].turnaround_time =
                p[selected_process].completion_time - p[selected_process].arrival_time;

            p[selected_process].waiting_time =
                p[selected_process].turnaround_time - p[selected_process].burst_time;

            current_time = p[selected_process].completion_time;

            p[selected_process].completed = true;
            completed_count++;
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