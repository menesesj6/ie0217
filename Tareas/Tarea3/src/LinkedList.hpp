#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ContactNode{
    string name;
    int number;
    ContactNode* nextContactNode; 
};

#endif