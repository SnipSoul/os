#include <stdio.h>

int max[5][3] = {
    {17, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

int allocation[5][3] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int avail[3] = {3, 3, 2};
int need[5][3];
int np = 5, nr = 3;

void display_matrix(int matrix[5][3]) {
    int i, j;
    for(i = 0; i < np; i++) {
        printf("\n P%d", i);
        for(j = 0; j < nr; j++) {
            printf(" %d", matrix[i][j]);
        }
    }
}

void calculate_need() {
    int i, j;
    for(i = 0; i < np; i++)
        for(j = 0; j < nr; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

void banker() {
    int i, j, k = 0, flag = 0;
    int finish[5] = {0}, safe_seq[5];

    for(i = 0; i < np; i++) {
        flag = 0;
        if(finish[i] == 0) { // Execute incomplete processes
            for(j = 0; j < nr; j++) { // Check a need of each process
                if(need[i][j] > avail[j]) {
                    flag = 1; // Break a loop as need is greater than avail and go to next process
                    break;
                }
            }
            if(flag == 0) { // Need is lesser than avail so complete process
                finish[i] = 1;
                safe_seq[k++] = i;
                for(j = 0; j < nr; j++)
                    avail[j] += allocation[i][j];
                i = -1;
            }
        }
    }
    printf("\n\n\n\n_______OUTPUT_______");
    flag = 0; // Check if all processes are completed
    for(i = 0; i < np; i++) {
        if(finish[i] == 0) {
            
            printf("\nThe system is in deadlock");
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("\nThe system is in safe state! \nSafe sequence is ==> ");
        for(i = 0; i < np; i++)
            printf(" P%d", safe_seq[i]);
    }
}

int main() {
    printf("\n****** Matrixes ******\n");
    printf("\nInitial allocation:\n");
    display_matrix(allocation);
    
    printf("\n\nMaximum Requirement:\n");
    display_matrix(max);
    
    printf("\n\nAvailable Resources:");
    for(int j = 0; j < nr; j++)
        printf(" %d", avail[j]);

    // Calculate and display need
    calculate_need();
    printf("\n\nNeed is\n");
    display_matrix(need);
    
    // Execute processes using Banker's Algorithm
    banker();
    printf("\n\n\n");
    return 0;
}
