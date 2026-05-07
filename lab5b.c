#include<stdio.h>

int main()
{
    int allocation[10][10], request[10][10];
    int available[10];
    int finish[10], safeSequence[10];
    int i, j, k, p, r, count = 0;

     printf("USN-1BF24CS328\n");

    printf("Enter the number of processes: ");
    scanf("%d", &p);

    printf("Enter the number of resources: ");
    scanf("%d", &r);

    // Allocation Matrix
    printf("Enter the allocation matrix:\n");
    for(i = 0; i < p; i++)
    {
        printf("Process %d: ", i);

        for(j = 0; j < r; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Request Matrix
    printf("Enter the request matrix:\n");
    for(i = 0; i < p; i++)
    {
        printf("Process %d: ", i);

        for(j = 0; j < r; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    // Available Resources
    printf("Enter the available resources: ");
    for(i = 0; i < r; i++)
    {
        scanf("%d", &available[i]);
    }

    // Initialize finish array
    for(i = 0; i < p; i++)
    {
        finish[i] = 0;
    }

    while(count < p)
    {
        int found = 0;

        for(i = 0; i < p; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < r; j++)
                {
                    if(request[i][j] > available[j])
                    {
                        break;
                    }
                }

                if(j == r)
                {
                    for(k = 0; k < r; k++)
                    {
                        available[k] += allocation[i][k];
                    }

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            break;
        }
    }

    if(count == p)
    {
        printf("\nSystem is in safe state.\n");
        printf("Safe Sequence is: ");

        for(i = 0; i < p; i++)
        {
            printf("P%d ", safeSequence[i]);
        }
    }
    else
    {
        printf("\nDeadlock detected in the system.\n");
    }

    return 0;
}