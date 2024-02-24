#include <stdio.h>
#define N 5

typedef struct queue{
    int a[N];
    int front,rear;
}queue;

void enqueue(queue *q){
    if(q->rear==N){
        printf("Queue Overflow \n");
    }else{
        int ele;
        printf("Enter element to be inserted: \n");
        scanf("%d",&ele);
        q->a[q->rear]=ele;
        q->rear++;
    }
}

int isempty(queue *q){
    if(q->front == q->rear){
        return 1;
    }else{
        return 0;
    }
}

int dequeue(queue *q){
    int ele;
    if(isempty(q)){
        printf("Queue is empty \n");
    }else{
        ele=q->a[q->front];
        for(int i=0;i<q->rear-1;i++){
            q->a[i]=q->a[i+1];
        }
        q->rear--;
        printf("Element Dequeued=%d \n",ele);
    }
}

void display(queue *q){
    int i;
    if(isempty(q)){
        printf("Queue is empty \n");
    }else{
        for(i=q->front;i<=q->rear-1;i++){
            printf("%d \t",q->a[i]);
        }
        printf("\n");
    }
}

int main(){
    queue q;
    q.front=0;
    q.rear=0;
    int ch;
    while(1){
        printf(" 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit \n");
        printf("Enter Choice: \n");
        scanf("%d",&ch);
        if(ch==4){
            break;
        }
        switch(ch){
            case 1:enqueue(&q);
                   break;
            case 2:dequeue(&q);
                   break;
            case 3:display(&q);
                   break;
            default:printf("Invalid Choice \n");
        }
    }
    return 0;
}