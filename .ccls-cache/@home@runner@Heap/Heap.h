#ifndef HEAP_H
#define HEAP_H

#include <iostream>

class Heap
{
  public:
  Heap();
  int* heap; //pointer to array of ints 
  void clear();
  void insert(int value);
  void sort();
  void downHeap(int parent);
  void display(int parent, int depth);
  void printTabs(int level);
};
#endif