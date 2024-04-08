#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*Linked List: Lista de nodos

Cada nodo tiene la informacion y la posicion del siguiente nodo
*/

class Node{
    public:
        int value; // Data
        Node* next; // Nodo puntero, direecion del siguiente nodo
};

int main() {
    // Instanciaciones nodos
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL; 

    // Posiciones en el heap
    one = new Node();
    two = new Node();
    three = new Node();

    // Asignar valores a values
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Asignar proximo nodo
    one->next = two;
    two->next = three;
    three->next = NULL;

    // DEfinir cabeza, punto de inicio
    head = one;

    // Flujo de desarrollo, pasa por todos los nodos
    while(head != NULL){
        cout << head->value;
        head = head->next;
    }

    return 0;
}