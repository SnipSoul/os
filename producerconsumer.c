#include <stdio.h>

int bufferSize = 3;
int itemsInBuffer = 0;

void producer()
{
    if (itemsInBuffer < bufferSize)
    {                   
        itemsInBuffer++;
        printf("Producer produces item %d\n", itemsInBuffer);
    }
    else
    {
        printf("Buffer is full! Producer can't add more items.\n");
    }
}
// Consumer function
void consumer()
{
    if (itemsInBuffer > 0)
    { 
        printf("Consumer consumes item %d\n", itemsInBuffer);
        itemsInBuffer--; 
    }
    else
    {
        printf("Buffer is empty! Consumer can't consume any items.\n");
    }
}
int main()
{
    int choice;
    printf("1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 to Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            printf("Exiting...\n");
            return 0; 
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}