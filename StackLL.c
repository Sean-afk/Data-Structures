#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *top=NULL;

void push(){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter element: \n");
    scanf("%d",&temp->data);
    temp->link=top;
    top=temp;
}

void pop(){
    node *temp;
    temp=top;
    if(temp==NULL){
        printf("Stack empty \n");
    }else{
        printf("Element deleted is %d \n",temp->data);
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
}

void traverse(){
    node *temp;
    if(top==NULL){
        printf("Stack is empty \n");
    }else{
        temp=top;
        while(temp!=NULL){
            printf("%d \n",temp->data);
            temp=temp->link;
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\n 1: Push \n 2: Pop \n 3: Display \n 4: Exit \n");
        printf("Enter choice \n");
        scanf("%d",&choice);
        if(choice == 4){
            break;
        }
        switch (choice){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: traverse();
                    break;
            default: printf("Invalid choice \n");
                     break;
        }
    }
    return 0;
}