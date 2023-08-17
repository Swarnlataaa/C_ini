#include <stdio.h>
#include <stdbool.h>

#define MAX_JOBS 100

typedef struct
{
    int id;
    int arrivalTime;
    int executionTime;
    int deadline;
} Job;

void earliestDeadlineFirst(Job jobs[], int numJobs)
{
    int currentTime = 0;

    while (true)
    {
        int minDeadline = INT_MAX;
        int nextJob = -1;

        // Find the job with the earliest deadline
        for (int i = 0; i < numJobs; i++)
        {
            if (jobs[i].arrivalTime <= currentTime && jobs[i].deadline < minDeadline && jobs[i].executionTime > 0)
            {
                minDeadline = jobs[i].deadline;
                nextJob = i;
            }
        }

        if (nextJob == -1)
        {
            // No available jobs at the moment
            printf("Time %d: Idle\n", currentTime);
            currentTime++;
        }
        else
        {
            // Execute the selected job
            printf("Time %d: Job %d\n", currentTime, jobs[nextJob].id);
            jobs[nextJob].executionTime--;
            currentTime++;
        }

        // Check if all jobs are completed
        bool allJobsCompleted = true;
        for (int i = 0; i < numJobs; i++)
        {
            if (jobs[i].executionTime > 0)
            {
                allJobsCompleted = false;
                break;
            }
        }

        if (allJobsCompleted)
        {
            break;
        }
    }
}

int main()
{
    int numJobs;
    printf("Enter the number of jobs: ");
    scanf("%d", &numJobs);

    Job jobs[MAX_JOBS];

    printf("Enter job details (arrival time, execution time, deadline):\n");
    for (int i = 0; i < numJobs; i++)
    {
        jobs[i].id = i + 1;
        scanf("%d %d %d", &jobs[i].arrivalTime, &jobs[i].executionTime, &jobs[i].deadline);
    }

    earliestDeadlineFirst(jobs, numJobs);

    return 0;
}
