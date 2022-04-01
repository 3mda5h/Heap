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
  void clear();
  void insert(int value);
  void sort();
  void downHeap(int parent);
  void display(int parent, int depth);
  void printTabs(int level);
};
#endif