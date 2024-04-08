#include <iostream>
using namespace std;

// Nodos del arbol
struct Node { 
    int data; // Valor almacenado
    struct Node *left, *right; // Ramificaciones

    // Pseudo clase
    Node(int data) {
        // Valores iniciales
        this->data = data;

        // NO tiene hijos, por ahora
        left = right = NULL;
    }
};

// Primero raiz y despues los de la izquierda y despue slos de la derecha
void preorderTraversal(struct Node* node) {
    if(node == NULL)
        return;
    
    // Va imprimiendo el camino por recursividad
    cout << node->data << "->";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

// Primero izquierda, luego derecha y por ultimo raiz
void postorderTraversal(struct Node* node){
    if(node == NULL)
        return;

    // Va imprimiendo el camino por recursividad
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << "->";
}

// Primero izquierdos, luego raiz y luego derechos
void inorderTraversal(struct Node* node){
    if(node == NULL)
        return;

    inorderTraversal(node->left);
    cout << node->data << "->";
    inorderTraversal(node->right);
}

int main() {
    // Se disena el arbol
    struct Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    /*
          1
        /    \
       12     9
      /  \
     5    6
    */

   // Recorrer e imprimir
    cout << "Inorder traversal ";
    inorderTraversal(root);

    cout << "\nPreorder traversal ";
    preorderTraversal(root);

    cout << "\nPostorder traversal ";
    postorderTraversal(root);

    return 0;
}