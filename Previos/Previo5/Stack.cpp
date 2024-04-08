#include <stdlib.h>
#include <iostream>

#define MAX 10

int size = 0;

//Crear stack
struct stack{
    int items[MAX];
    int top;
};
typedef struct stack st;

void createEmptyStack(st *s) {
    s->top = -1;
}

// Revisar si esta lleno
int isfull(st *s) {
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

// Revisar si esta vacio
int isempty(st *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// Agregar elementos
void push(st *s, int newitem){
    if(isfull(s)){
        std::cout << "STACK FULL";
    } else {
        s->top++;
        s->items[s->top] = newitem;
    }
    size++;
}

// Quitar elementos
void pop(st *s){
    if(isempty(s)){
        std::cout << "\nSTACK EMPTY\n";
    } else{
        std::cout << "Item popped = " << s->items[s->top];
        s->top--;
    }
    size--;
    std::cout << std::endl;
}

// Imprimir elementos
void printStack(st *s){
    printf("Stack: ");
    for (int i = 0; i < size; i++){
        std::cout << s->items[i] << " ";
    }
    std::cout << std::endl;
}

// Main
int main() {
    st *s = (st*)malloc(sizeof(st));

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    std::cout << "\nAfter popping out\n";
    printStack(s);
}