#include<stdio.h>

#include<stdlib.h> // For exit()

//#include<conio.h> // This header is not standard, use it if required

#define n 5
 
void main() {

    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1, x = n;
 
    printf("Queue using Array");

    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");
 
    while(ch) {

        printf("\nEnter the Choice:");

        scanf("%d", &ch);
 
        switch(ch) {

            case 1:

                if(rear == n)

                    printf("\nQueue is Full");

                else {

                    printf("\nEnter number %d:", j++);

                    scanf("%d", &queue[rear++]);

                }

                break;
 
            case 2:

                if(front == rear) {

                    printf("\nQueue is empty");

                } else { 

                    printf("\nDeleted Element is %d", queue[front++]);

                    x++;

                }

                break;
 
            case 3:

                printf("\nQueue Elements are:\n");

                if(front == rear)

                    printf("Queue is Empty");

                else {

                    for(i = front; i < rear; i++) {

                        printf("%d\n", queue[i]);

                    }

                }

                break;
 
            case 4:

                exit(0);
 
            default:

                printf("Wrong Choice: please see the options");

        }

    }

    //getch(); // Uncomment this if using conio.h

}

 