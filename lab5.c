#include<stdio.h>

int main()
{
    int allocation[10][10], max[10][10], need[10][10];
    int available[10], finish[10], safeSequence[10];
    int i, j, k, p, r, count = 0;
    printf("1BF24CS328 \n");
    printf("Enter number of processes: ");
    scanf("%d", &p);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < r; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter Maximum Demand Matrix:\n");
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(i = 0; i < r; i++)
    {
        scanf("%d", &available[i]);
    }

    // Calculate Need Matrix
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
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
                    if(need[i][j] > available[j])
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

                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            printf("\nSystem is not in a safe state.\n");
            return 0;
        }
    }

    printf("\nSystem is in a safe state.\n");
    printf("Safe sequence is: ");

    for(i = 0; i < p; i++)
    {
        printf("P%d", safeSequence[i]);

        if(i != p - 1)
        {
            printf(" -> ");
        }
    }

    return 0;
}