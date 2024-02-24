#include <stdio.h>
#include <stdlib.h>

void create(void);
void display(void);
void insert_begin(void);
void insert_end(void);
void insert_pos(void);
void del_begin(void);
void del_end(void);
void del_pos(void);
void count(void);
void reverse(void);
void swap(void);

typedef struct node{
    int data;
    struct node *next;
}node;

node *start=NULL;

int main(){
    int choice;
    while(1){
        printf("-----MENU-----\n");
        printf("1.Create \n");
        printf("2.Display \n");
        printf("3.Insert at the beginning \n");
        printf("4.Insert at the end \n");
        printf("5.Insert at specified position \n");
        printf("6.Delete from beginning \n");
        printf("7.Delete from the end \n");
        printf("8.Delete from specified position \n");
        printf("9.Count number of elements \n");
        printf("10.Reverse the list \n");
        printf("11.Swap \n");
        printf("12.Exit \n");
        printf("--------------------------------------\n");
        printf("Enter your choice:\t \n");
        scanf("%d",&choice);
        switch(choice){
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert_begin();
                    break;
            case 4: insert_end();
                    break;
            case 5: insert_pos();
                    break;
            case 6: del_begin();
                    break;
            case 7: del_end();
                    break;
            case 8: del_pos();
                    break;
            case 9: count();
                    break;
            case 10:reverse();
                    break;
            case 11:swap();
                    break;
            case 12:exit(0);
                    break;
            default: printf("Wrong Choice \n");
                     break;
        }
    }
    return 0;
}

void create(){
    node *temp,*ptr;
    temp =(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("\n Out of Memory Space");
        exit(0);
    }
    printf("Enter the data value for the node: \t \n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }

}

void display(){
    node *ptr;
    if(start==NULL){
        printf("List is empty \n");
        return;
    }
    else{
        ptr=start;
        printf("The list elements are: \n");
        while(ptr!=NULL){
            printf("%d \t",ptr->data);
            ptr=ptr->next;
        }
    }
}

void count(){
    int count = 0;
    node *ptr;
    if(start==NULL){
        printf("List is empty \n");
        return;
    }
    else{
        ptr=start;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }
        printf("Count: %d \n",count);
    }
}

void reverse(){
    node *prev=NULL,*next=NULL;
    node *current=start;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    start=prev;
}

void insert_begin(){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("Out of Memory Space: ");
        return;
    }
    printf("Enter the data value for the node \n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }else{
        temp->next=start;
        start=temp;
    }
}


void insert_end(){
    node *temp,*ptr;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("Out of Memory Space \n");
        return;
    }
    printf("Enter the data value of the node \n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void insert_pos(){
    node *temp,*ptr;
    int i,pos;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("Out of Memory Space \n");
        return;
    }
    printf("Enter position for new node to be inserted \n");
    scanf("%d",&pos);
    printf("Enter data value for the node \n");
    scanf("%d",&temp->data);

    temp->next=NULL;
    if(pos==0){
        temp->next=start;
        start=temp;
    }else{
        for(i=0,ptr=start;i<pos-1;i++){
            ptr=ptr->next;
            if(ptr==NULL){
                printf("Position not found \n");
                return;
            }
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }                                                                                                                                                                                                                             
}

void del_begin(){
    node *ptr;
    if(ptr==NULL){
        printf("List Empty \n");
    }else{
        ptr=start;
        start=start->next;
        printf("Deleted Element is: %d \n",ptr->data);
        free(ptr);
    }
}

void del_end(){
    node *tmp,*ptr;
    if(start==NULL){
        printf("List Empty \n");
        exit(0);
    }else if(start->next==NULL){
        ptr=start;
        start=NULL;
        printf("Element deteled is %d \n",ptr->data);
        free(ptr);
    }else{
        ptr=start;
        while(ptr->next!=NULL){
            tmp=ptr;
            ptr=ptr->next;
        }
        tmp->next=NULL;
        printf("Deleted element is %d \n",ptr->data);
        free(ptr);
    }
}

void del_pos(){
    int i,pos;
    node *tmp,*ptr;
    if(start==NULL){
        printf("List if empty \n");
        exit(0);
    }else{
        printf("Enter the position of node to be deleted \n");
        scanf("%d",&pos);
        if(pos==0){
            ptr=start;
            start=start->next;
            printf("Element deleted %d ",ptr->data);
            free(ptr);
        }else{
            ptr=start;
            for(i=0;i<pos;i++){
                tmp=ptr;
                ptr=ptr->next;
                if(ptr==NULL){
                    printf("Position not Found: \n");
                    return;
                }
            }
            tmp->next=ptr->next;
            printf("Element deleted is %d", ptr->data);
            free(ptr);
        }
    }
}

void swap(){
    int i=0,pos;
    node *p,*q,*r;
    if(start==NULL){
        printf("List is empty \n");
        return;
    }else{
        printf("Enter position of node to be swapped \n");
        scanf("%d",&pos);
        if(pos==0){
            p=start;
            q=p->next;
            p->next=q->next;
            q->next=p;
            start=q;
        }else{
            p=start;
            while(i<pos-1){
                p=p->next;
                i++;
             }
             q=p->next;
             r=q->next;
             q->next=r->next;
             r->next=q;
             p->next=r;             
        }
    }
}

