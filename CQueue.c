#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1,rear=-1;
void enqueue(){
    char x;
    if((front==-1 && rear==max-1)||(front==((rear+1)%max))){
        printf("\nqueue is overflow");
    }
    else{
        printf("enter the element");
        scanf(" %c",&x);
        if(front == -1 && rear == -1){
            front = rear = 0;
            queue[rear] = x;
        }
        else{
            rear = (rear + 1) % max;
            queue[rear]=x;
        }
    }
}
void dequeue(){
    if (front == -1 && rear == -1)
        printf("queue is an empty\n");
    else if(front == rear){
        printf("dequeued element is: %c \n",queue[front]);
        front = rear = -1; 
    }
    else{
        printf("dequeued element is: %c \n",queue[front]);
            front = (front + 1) % max ;
    }
}
void display() {
    int i = front;
    if (front == -1 && rear == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue is : \n");
        while (i != rear) {
           printf("%c ", queue[i]);
           i = (i + 1) % max;
        }
        printf("%c \n", queue[i]);
    }
}
int main(){
    int choice;
    printf("1 for insert element\n2 for delete\n3 for display\n4 for exit\n");
    while (1){
       printf("enter your option\n");
       scanf("%d",&choice);
       switch (choice){
        case 1:
            enqueue();
                break;
        case 2:
            dequeue();
                break;
        case 3:
            display();
                break;
        case 4:
            exit(0);
                break;
       default:printf("invalid choice");
        break;
       }
    }   
    return 0;
}