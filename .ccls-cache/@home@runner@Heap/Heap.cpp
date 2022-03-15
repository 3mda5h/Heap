#include <iostream>
#include "Heap.h"
#include <math.h>

using namespace std;

Heap::Heap()
{
  max = NULL;
  heap = new Node*[1000];
}

void Heap::insert(Heap::Node* node)
{
  if(max == NULL) //if first node inserted
  {
    max = node; //do i even need this ?
    heap[0] = node;
  }
  else
  {
    //children: 2i+1, 2i+2 parent: ⌊(i−1)/2⌋, L = floor
    int i = 999;
    int parentI = (int)floor((i-1)/2); //parent index
    while(node->value > heap[parentI]->value && i > -1)
    {
      //swap parent and current node 
      Node* temp = heap[parentI];
      heap[parentI] = node; 
      heap[i] = temp;
      i--;
      parentI = (int)floor((i-1)/2);
    }
  }
}

void Heap::output(int index)
{
  cout << heap[index]->value << ", "; //print value at current index
  output((2 * index) + 1); //call function for right child
  output(2 * index); //call function for left child
}