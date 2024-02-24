#include <stdio.h>
#define N 20 

/*Define MACRO using preprocessor directive because 
we cannot use ordinary variable to specify size
Preprocessing Phase means before Compilation & at 
Compilation the value will be substituted*/

typedef struct stack{
    int a[N]; // We can use only macro 
    int top;
}stack;

void push(stack *s, int ele){
    if(s->top==N-1){
        printf("Stack Overflow \n");
        return;
    }else{
        s->top++;
        s->a[s->top]=ele;
    }
}

int isempty(stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int pop(stack *s){
    int x;
    if(isempty(s)){
        return -1;
    }
    else{
        x = s->a[s->top];
        s->top--;
        return x;
    }
}

int stacktop(stack *s){
    if(isempty(s)){
        return -1;
    }else{
        return s->a[s->top];
    }
}

void display(stack *s){
    int i;
    if (isempty(s)){
        printf("Stack is empty \n");
        return;
    }else{
        for(i=s->top;i>=0;i--){
            printf("%d \t",s->a[i]);
        }printf("\n");
    }
}

int main(){
    int ch,ele;  //ch=choice, ele=element
    stack s;     //creating a stack s
    s.top = -1;
    while(1){
        printf("\n 1: Push \n 2: Pop \n 3: Stacktop \n 4: Display \n 5: Exit \n");
        printf("Enter choice \n");
        scanf("%d",&ch);
        if(ch == 5){
            break;
        }
        switch(ch){
            case 1:
            {
                printf("Enter Element to push \n");
                scanf("%d", &ele);
                push(&s,ele);
            }break;
            
            case 2:
            {
                ele=pop(&s);
                if(ele==-1){
                    printf("Stack Underflow \n");
                }
                else{
                    printf("Element Popped = %d \n",ele);
                    }
            }break;
            
            case 3:
            {
                ele=stacktop(&s);
                if(ele==-1){
                    printf("Stack is empty \n");
                }
                else{
                    printf("Stacktop Element= %d \n",ele);
                }
            }break;

            case 4:
            {
                display(&s);
            }break;

            default:
            {
                printf("Invalid Choice \n");
            }
        }
    }
return 0;
}