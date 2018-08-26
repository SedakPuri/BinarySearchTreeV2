//  Sedak Puri
//  BST.c
//  FlightTest
//  Compiler: Xcode
//  Created by Sedak Puri on 8/24/18.
//  Copyright © 2018 Sedak Puri. All rights reserved.

#include "BST.h"

BST:: BST(){
    size = 0;
    root = nullptr;
}

BST:: ~BST(){
    if (root == nullptr)
        delete root;
}

Node:: ~Node(){
    if(left != nullptr)
        delete left;
    if(right != nullptr)
        delete right;
}

Node:: Node(int val){
    this->value = val;
    left = nullptr;
    right = nullptr;
}

Node* BST::find(Node* n, int value){
    //Case: Tree is empty
    if (n == nullptr){
        return nullptr;
    }
    
    //Case: The n node contains value
    if(n->value == value){
        return n;
    }
    
    //Case: The n node contains a value that is less than value
    if ((n->value < value) && (n->right != nullptr)){
        return find(n->right, value);
    }
    //Case: The n node contains a value that is greater than value
    if ((n->value < value) && (n->left != nullptr)){
        return find(n->left, value);
    }
    
    //General Case: Return the value of the node pointer
    return n;
}

bool BST::add(int val){
    //Receiving a node that is either the node we are looking for or the parent of where the node will be created
    Node* found = find(root, val);
    
    if(found == nullptr){              //Case: Tree is empty
        root = new Node(val);
    } else if(found->value == val){    //Case: Value already exists
        return false;
    } else if(found->value > val){     //Case: Value is less
        found->left = new Node(val);
    }else if(found->value < val){      //Case: Value is more
        found->right = new Node(val);
    }
    size++;
    return true;
}

bool BST::remove(int val){
    int oldSize = size;
    root = remove(root, val);
    return (oldSize > size);
}

Node* BST::remove(Node* n, int value){
    //Case: Tree is empty
    if(root == nullptr){
        return nullptr;
    }
    
    //Case: Searching subtrees
    if(n->value > value){
        n->right = remove(n->right, value);
    } else if (n->value < value){
        n->left = remove(n->left, value);
    } else {
        //Found
        size--;
        
        //Case 1: Leaf
        if(n->right == nullptr && n->left == nullptr){
            return nullptr;
        }
        
        //Case 2: single child
        if(n->right == nullptr){
            return n->left;
        }
        if(n->left == nullptr){
            return n->right;
        }
        
        //Case 3: Two children
        Node* pred = n->left;
        while(n->right != nullptr){
            pred = pred->right;
        }
        n->value = pred->value;
        n->left = remove(n->left, pred->value);
    }
    return n;
}

const void BST:: display(){
    display(root, 0);
}

const void BST:: display(Node* n, int level){
    if(n != nullptr){
        for (int i = 0; i < 2 * level; i++){
            std::cout<<" ";
        }
        std::cout<<n->value<<"\n";
        display(n->left, level + 1);
        display(n->right, level + 1);
    }
}
