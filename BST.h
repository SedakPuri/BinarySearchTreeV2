//  Sedak Puri
//  BST.h
//  FlightTest
//  Compiler: Xcode
//  Created by Sedak Puri on 8/24/18.
//  Copyright © 2018 Sedak Puri. All rights reserved.

#ifndef BST_h
#define BST_h
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

class Node{
    friend class BST;
public:
    Node(int val);
    ~Node();
private:
    int value;
    Node *left;
    Node *right;
};

class BST{
    friend class Node;
private:
    //Member Variables
    Node* root;
    
    //Member Functions
    Node* find(Node* n, int value);
    Node* remove(Node* n, int value);
    const void display(Node* n, int level);
public:
    //Member Variables
    int size;
    
    //Member Functions
    BST();
    ~BST();
    const void display();
    bool add(int val);
    bool remove(int val);
};

#endif /* BST_h */
