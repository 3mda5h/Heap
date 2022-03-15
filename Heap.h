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
  void insert(Node* node);
};
#endif