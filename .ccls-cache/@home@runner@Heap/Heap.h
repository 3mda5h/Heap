#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap
{
  struct Node
  {
    Node* left;
    Node* right;
    int value;
  };
  public:
  Heap();
  Node* max; //root
  Node** heap; //pointer to array of node pointers 
  void insert(Node* node);
  void output(int index);
};
#endif