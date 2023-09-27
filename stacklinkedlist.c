#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;

struct node
{
    int data;
    Node *next;
};
struct stack
{
  Node *top;
};
typedef struct stack Stack;

Node *createNode(int data){
    Node *newNode=(Node*) malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Stack *createStack(){
    Stack *stack=(Stack*)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}

void push(Stack *stack, int data){
    Node *newNode=createNode(data);
    newNode->next=stack->top;
    stack->top=newNode;
}
void printstack(Stack* stack){
     Node* temp = stack->top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int pop(Stack *stack){
    Node* temp=stack->top;
    int data=temp->data;
    stack->top=temp->next;
    free(temp);
    return data;
}





int main(){

    Stack *stack=createStack();
    push(stack,10);
    push(stack,20);
    push(stack,30);
    printstack(stack);
    printf("%d",pop());


}