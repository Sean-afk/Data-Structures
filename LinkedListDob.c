#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next,*prev;
}node;

typedef struct LL{
    node *start;
}LL;

void display(LL *l){
    int ch;
    node *p;
    printf(" 1.Forward Direction \n 2.Backward Direction \n");
    scanf("%d",&ch);
    if(ch==1){
        p=l->start;
        while(p!=NULL){
        printf("\t %d",p->data);
        p=p->next;}
    }else if(ch==2){
        p=l->start;
        while(p->next!=NULL){
            p=p->next;
        }
        while(p!=NULL){
            printf("\t %d",p->data);
            p=p->prev;
        }
    }else{
            printf("\n Invalid Choice");
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

void insertbegin(LL*l,int ele){
    node *newrec;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->prev=NULL;
    newrec->next=NULL;
    if(l->start==NULL){
        l->start=newrec;
    }else{
        newrec->next=l->start;
        l->start->prev=newrec;
        l->start = newrec;
    }
}

void insertend(LL *l,int ele){
    node *newrec,*p;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=newrec->prev=NULL;
    if(l->start==NULL){
        l->start=newrec;
    }else{
        p=l->start;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newrec;
        newrec->prev=p;
    }
}

void insertatpos(LL *l,int ele,int pos){
    node *newrec,*p,*q;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=newrec->prev=NULL;
    int len=count(l);
    if(pos>len+1){
        printf("\n Invalid position");
        printf("List contains only %d nodes \n",len);
    }
    else if(pos==1){
        newrec->next=l->start;
        l->start->prev=newrec;
        l->start=newrec;
    }else{
        p=l->start;
        for(int i=1;i<pos-1;i++){
            p=p->next;
        }
        q=p->next;
        p->next=newrec;
        newrec->prev=p;
        newrec->next=q;
        q->prev=newrec;
    }
}

void deletebegin(LL*l){
    node *p;
    if(l->start==NULL){
        printf("\n List is empty");
    }else{
        p=l->start;
        l->start=p->next;
        l->start->prev=NULL;
        free(p);
    }
}

void deleteend(LL *l){
    node *p,*q;
    if(l->start==NULL){
        printf("\n List is empty");
    }else if(l->start->next==NULL){
        p=l->start;
        l->start=NULL;
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

void deleteatpos(LL *l,int pos){
    node *p,*q;
    if(pos>count(l)){
        printf("\n Invalid Position");
    }else if(pos==1){
        p=l->start;
        l->start=p->next;
        l->start->prev=NULL;
        free(p);
    }else{
        q=l->start;
        for(int i=1;i<pos-1;i++){
            q=q->next;
        }
        p=q->next;
        q->next=p->next;
        p->next->prev=q;
        free(p);
    }
}

int main(){
    LL l;
    l.start=NULL;
    int ch,ele,pos,c;
    while(1){
        printf("\n Menu \n 1.Insert at beginning \n 2.Insert at end \n 3.Insert at specific position \n 4.Delete from beginning \n 5.Delete from End \n 6.Delete from specific position \n 7.Count Nodes \n 8.Display List \n 9.Exit \n");
        scanf("%d",&ch);
        if(ch==9){
            break;
        }
        switch(ch){

            case 1:{
                printf("Enter element to insert: \n");
                scanf("%d",&ele);
                insertbegin(&l,ele);
            }break;

            case 2:{
                printf("Enter element to insert: \n");
                scanf("%d",&ele);
                insertend(&l,ele);
            }break;

            case 3:{
                printf("Enter element & position: \n");
                scanf("%d %d",&ele,&pos);
                insertatpos(&l,ele,pos);
            }break;

            case 4:{
                deletebegin(&l);
            }break;

            case 5:{
                deleteend(&l);
            }break;

            case 6:{
                printf("Enter position to delete \n");
                scanf("%d",&pos);
                deleteatpos(&l,pos);
            }break;

            case 7:{
                c=count(&l);
                printf("Number of nodes: %d \n",c);
            }break;

            case 8: {
                display(&l);
            }break;

            default:{
                printf("Invalid Choice \n");
            }
        }
    }
    return 0;
}