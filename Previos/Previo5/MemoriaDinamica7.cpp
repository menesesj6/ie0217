#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    float *ptr, *new_ptr;

    ptr = (float*) malloc(5 * sizeof(float));

    if(ptr == NULL){
        cout << "Memory Allocation Failed";
        exit(1);
    }

    for(int i = 0; i < 5; i++){
        ptr[i] = i * 1.5;
    }

    new_ptr = (float*) realloc(ptr, 10 * sizeof(float));
    if(new_ptr == NULL){
        cout << "Memory re-allocation Failed";
        exit(1);
    }

    for( int i = 0; i < 10; i++){
        new_ptr[i] = i * 2.5;
    }

    cout << "Printing values " << endl;

    for(int i = 0; i < 10; i++){
        cout << new_ptr[i] << endl;
    }

    free(new_ptr);

    return 0;
}