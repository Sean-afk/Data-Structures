#include <stdio.h>
#include <stdlib.h>

//creating a node
typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct LL{
    node *start;
}LL;

void display(LL *l){
    node *p;
    if(l->start==NULL){
        printf("List is empty \n");
    }else{
        p=l->start;
        while(p!=NULL){
            printf("\t %d",p->data);
            p=p->next;
        }
    }
}

int count(LL *l){
    int c=0;
    node *p;
    p=l->start;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void insert_begin(LL *l,int ele){
    node *newrec;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=NULL;
    if(l->start==NULL){
        l->start=newrec;
    }else{
        newrec->next=l->start;
        l->start=newrec;
    }
}

void insert_end(LL *l,int ele){
    node *newrec,*p;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=NULL;
    if(l->start==NULL){
        l->start=newrec;
    }else{
        p=l->start;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newrec;
    }
}

void insert_at_pos(LL *l,int ele,int pos){
    node *newrec,*p;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=NULL;
    if(pos>count(l)+1){
        printf("\n Invalid position");
    }else if(pos==1){
        newrec->next=l->start;
        l->start=newrec;
    }else{
        p=l->start;
        for(int i=1;i<pos-1;i++){
            p=p->next;
        }
        newrec->next=p->next;
        p->next=newrec;
    }
}

void delete_begin(LL *l){
    node *p;
    if(l->start==NULL){
        printf("List is empty \n");
    }else{
        p=l->start;
        l->start=p->next;
        free(p);
    }
}

void delete_end(LL *l){
    node *p,*q;
    if(l->start==NULL){
        printf("List if empty \n");
    }else if(l->start->next==NULL){
        p=l->start;
        l->start=NULL;                  //Only one element exists
        free(p);
    }else{
        q=l->start;
        while(q->next->next!=NULL){
            q=q->next;
        }
        p=q->next;
        q->next=NULL;
        free(p);
    }
}

void delete_at_pos(LL *l,int pos){
    node *p,*q;
    if(pos>count(l)){
        printf("Invalid Position \n");
    }else if(pos==1){
        p=l->start;
        l->start=p->next;
        free(p);
    }else{
        q=l->start;
        for(int i=1;i<pos-1;i++){
            q=q->next;
        }
        p=q->next;
        q->next=p->next;
        p->next=NULL;
        free(p);
    }

}

void reverse(LL *l){
    node *p,*q,*r;
    p = l->start;
    q = NULL;
    while(p!=NULL){
        r = p->next;
        p->next=q;
        q=p;
        p=r;
    }
    l->start=q;
}

int main(){
    LL l;
    l.start=NULL;
    int ch,ele,pos,c;
    while(1){
        printf("\n Menu \n 1.Insert at beginning \n 2.Insert at end \n 3.Insert at specific position \n 4.Delete from beginning \n 5.Delete from End \n 6.Delete from specific position \n 7.Count Nodes \n 8.Reverse List \n 9.Display List \n 10.Exit \n");
        scanf("%d",&ch);
        if(ch==10){
            break;
        }
        switch(ch){

            case 1:{
                printf("Enter element to insert: \n");
                scanf("%d",&ele);
                insert_begin(&l,ele);
                display(&l);
            }break;

            case 2:{
                printf("Enter element to insert: \n");
                scanf("%d",&ele);
                insert_end(&l,ele);
                display(&l);
            }break;

            case 3:{
                printf("Enter element & position: \n");
                scanf("%d %d",&ele,&pos);
                insert_at_pos(&l,ele,pos);
                display(&l);
            }break;

            case 4:{
                delete_begin(&l);
                display(&l);
            }break;

            case 5:{
                delete_end(&l);
                display(&l);
            }break;

            case 6:{
                printf("Enter position to delete \n");
                scanf("%d",&pos);
                delete_at_pos(&l,pos);
                display(&l);
            }break;

            case 7:{
                c=count(&l);
                printf("Number of nodes: %d \n",c);
            }break;

            case 8:{
                reverse(&l);
                display(&l);
            }break;

            case 9: {
                display(&l);
            }break;

            default:{
                printf("Invalid Choice \n");
            }
        }
    }
    return 0;
}

