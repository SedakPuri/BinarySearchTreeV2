//  Sedak Puri
//  main.cpp
//  FlightTest
//  Compiler: Xcode
//  Created by Sedak Puri on 8/24/18.
//  Copyright © 2018 Sedak Puri. All rights reserved.

#include "Header.h"
#include "BST.h"

int main() {
    //Setup
    BST tree;
    srand(static_cast<int>(time(nullptr)));
    
    //Filling the tree with random numbers
    for(int i = 0; i < 10; i++){
        int randomNum = (rand() % 500) + 1;
        cout<<randomNum<<endl;
        tree.add(randomNum);   
    }
    
    //Printint out the tree
    cout<<"There are total: "<<tree.size<<" elements in the tree!"<<endl;
    tree.display();
    return 0;
}
