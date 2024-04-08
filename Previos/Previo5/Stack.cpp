#include <stdlib.h>
#include <iostream>

#define MAX 10

int size = 0;

/*Un stack es como unas Pringles.
EL ultimo que entro queda arriba y es el primero que se agarra.
LIFO: Last In First Out.*/

// Definir stack
struct stack{
    int items[MAX]; // Array
    int top; // INdice del ultimo que subio
};

// Definicion de un tipo st, que e sun struct stack
typedef struct stack st; 

// Crear stack vacio por puntero
void createEmptyStack(st *s) {
    // Indices del stack van 0-9, entonces top = -1 indica que esta vacia
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
        s->top++; // AUmentar el indice
        s->items[s->top] = newitem; // Agregar el elemento
    }
    size++; // Aumentar su tamano
}

// Quitar elementos
void pop(st *s){
    if(isempty(s)){
        std::cout << "\nSTACK EMPTY\n";
    } else{
        std::cout << "Item popped = " << s->items[s->top];
        s->top--; // Se devuelve un indice
    }
    size--; // Reduce el tamano
    std::cout << std::endl;
}

// Imprimir elementos
void printStack(st *s){
    // Imprime el stack
    printf("Stack: ");
    for (int i = 0; i < size; i++){
        std::cout << s->items[i] << " ";
    }
    std::cout << std::endl;
}

// Main
int main() {
    int ch;
    st *s = (st*)malloc(sizeof(st)); // memoria del heap

    createEmptyStack(s); // Crear el stack

    // Agregar elementos
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    // Imprimir
    printStack(s);

    // Quitar el ultimo
    pop(s);

    std::cout << "\nAfter popping out\n";
    // Imprimir
    printStack(s);
}