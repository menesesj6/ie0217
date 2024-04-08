#include <iostream>
#define SIZE 5

using namespace std;

/*Los queue es como el queue de Spotify.
Es de la forma FIFO (First In First Out).
Tiene un problema, cuando se va desencolando y solo queda el ultimo, se debe desencolar
ese para poder encolar algo mas.
*/

// Definir queue
class Queue{
    private:
        int items[SIZE], front, rear; // Array y los indices de princiipio y fin
    public:
        // Constructor
        Queue(){
            front = -1;
            rear = -1;
        }

        // Definir si esta lleno
        bool isFull(){
            if(front == 0 && rear == SIZE -1){
                return true;
            }
            return false;
        }

        // Definir si esta vacio
        bool isEmpty(){
            if (front == -1)
                return true;
            else
                return false;
        }

        // Encolar
        void enQueue(int element){
            if(isFull()){
                cout << "Queue is full";
            } else{
                // POner front en 0 e ir aumentando rear
                if (front == -1) front = 0;
                rear++;
                // ASignar el elemento en el indice rear
                items[rear] = element;
                cout << endl << "Inserted " << element << endl;
            }
        }

        // Desencolar
        int deQueue(){
            int element;
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return (-1);
            } else{
                // Va a salir el front
                element = items[front];
                if(front <= rear) {
                    front = -1;
                    rear = -1;
                } else {
                    // Ir reduciendo el tamano, acercando front a rear
                    front++;
                }
                cout << endl << "Deleted -> " << element << endl;
                return (element);
            }
        }

        // Imprimir el queue
        void display(){
            int i;
            if(isEmpty()){
                cout << endl << "Empty Queue" << endl;
            } else{
                cout << endl << "Front index ->" << front;
                cout << endl << "Items ->";
                for(i = front; i <= rear; i++)
                    cout << items[i] << " ";
                cout << endl << "Rear index -> " << rear << endl;
            }
        }
};

int main() {
    Queue q; // INstanciacion de Queue

    // Da error, esta vacia
    q.deQueue();

    // Encolar 5 elementos
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    // Da error, esta llena
    q.enQueue(1);

    // Imprimir
    q.display();

    // Desencolar
    q.deQueue();

    // Imprimir
    q.display();

    return 0;
}