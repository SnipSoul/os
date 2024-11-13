#include <stdio.h>

#define MAX 100

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int priority;
};

// Function to print the Gantt chart
void printGanttChart(int processes[], int n, int burstTimes[]) {
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < burstTimes[i]; j++) {
            printf("-");
        }
        printf(" P%d |", processes[i]);
    }
    printf("\n");
}

// Function to calculate and print waiting and turnaround times
void calculateTimes(struct Process p[], int n) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        p[i].turnaroundTime = p[i].burstTime + p[i].waitingTime;
        totalWaitingTime += p[i].waitingTime;
        totalTurnaroundTime += p[i].turnaroundTime;

        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burstTime, p[i].waitingTime, p[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

// First Come First Serve (FCFS) Scheduling
void FCFS(struct Process p[], int n) {
    printf("\nFirst Come First Serve (FCFS) Scheduling:\n");

    // Calculate waiting time
    p[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    calculateTimes(p, n);
}

// Shortest Job First (SJF) Scheduling
void SJF(struct Process p[], int n) {
    printf("\nShortest Job First (SJF) Scheduling:\n");

    // Sort processes by burst time
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burstTime > p[j].burstTime) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time
    p[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    calculateTimes(p, n);
}

// Priority Scheduling
void priorityScheduling(struct Process p[], int n) {
    printf("\nPriority Scheduling:\n");

    // Sort processes by priority
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time
    p[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    calculateTimes(p, n);
}

// Round Robin Scheduling
void roundRobin(struct Process p[], int n, int quantum) {
    printf("\nRound Robin Scheduling (Quantum = %d):\n", quantum);

    int remainingBurstTime[n], t = 0, completed = 0;
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = p[i].burstTime;
        p[i].waitingTime = 0;
    }

    // Time cycle simulation
    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                if (remainingBurstTime[i] > quantum) {
                    t += quantum;
                    remainingBurstTime[i] -= quantum;
                } else {
                    t += remainingBurstTime[i];
                    p[i].waitingTime = t - p[i].burstTime;
                    remainingBurstTime[i] = 0;
                    completed++;
                }
            }
        }
    }

    calculateTimes(p, n);
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[MAX];
    int burstTimes[MAX], processOrder[MAX];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process P%d\n", i + 1);
        p[i].id = i + 1;
        printf("Burst Time: ");
        scanf("%d", &p[i].burstTime);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
        burstTimes[i] = p[i].burstTime;
        processOrder[i] = p[i].id;
    }

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);

    // FCFS Scheduling
    FCFS(p, n);
    printGanttChart(processOrder, n, burstTimes);

    // SJF Scheduling
    SJF(p, n);
    printGanttChart(processOrder, n, burstTimes);

    // Priority Scheduling
    priorityScheduling(p, n);
    printGanttChart(processOrder, n, burstTimes);

    // Round Robin Scheduling
    roundRobin(p, n, quantum);
    printGanttChart(processOrder, n, burstTimes);

    return 0;
}
