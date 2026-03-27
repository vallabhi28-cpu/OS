#include <stdio.h>

#define MAX 10
#define SIMULATION_TIME 20

int main()
{
    int n, i, time;
    int pid[MAX], burst[MAX], deadline[MAX], period[MAX];
    int remaining[MAX], next_arrival[MAX], abs_deadline[MAX];
    printf("1BF24CS328 ");
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nTask %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &pid[i]);
        printf("Burst Time: ");
        scanf("%d", &burst[i]);
        printf("Deadline: ");
        scanf("%d", &deadline[i]);
        printf("Period: ");
        scanf("%d", &period[i]);

        remaining[i] = 0;
        next_arrival[i] = 0;
        abs_deadline[i] = deadline[i];
    }

    printf("\nScheduling occurs for %d ms\n\n", SIMULATION_TIME);

    for(time = 0; time < SIMULATION_TIME; time++)
    {
        // Check for new task arrivals
        for(i = 0; i < n; i++)
        {
            if(time == next_arrival[i])
            {
                remaining[i] = burst[i];
                abs_deadline[i] = time + deadline[i];
                next_arrival[i] += period[i];
            }
        }

        int selected = -1;
        int min_deadline = 9999;

        for(i = 0; i < n; i++)
        {
            if(remaining[i] > 0)
            {
                if(abs_deadline[i] < min_deadline)
                {
                    min_deadline = abs_deadline[i];
                    selected = i;
                }
            }
        }

        if(selected == -1)
        {
            printf("%dms : CPU is idle.\n", time);
        }
        else
        {
            printf("%dms : Task %d is running.\n", time, pid[selected]);
            remaining[selected]--;
        }
    }

    return 0;
}