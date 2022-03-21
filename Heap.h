#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap
{
  /* struct Node
  {
    Node* left;
    Node* right;
    int value;
  }; */
  public:
  Heap();
  //Node* max; //root
  int* heap; //pointer to array of node pointers 
  void insert(int value);
  void output(int index);
};
#endif