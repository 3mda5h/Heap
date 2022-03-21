#include <iostream>
#include "Heap.h"
#include <math.h>

using namespace std;

Heap::Heap()
{
  heap = new int[1000];
}

void Heap::insert(int value)
{
  if(heap[0] == NULL) //if first node inserted
  {
    heap[0] = value;
  }
  else
  {
    //children: 2i+1, 2i+2 parent: ⌊(i−1)/2⌋, L = floor
    int i = 999;
    int parentI = (int)floor((i-1)/2); //parent index
    while(value > heap[parentI] && i > -1)
    {
      //swap parent and current node 
      int* temp = &heap[parentI];
      heap[parentI] = value; 
      heap[i] = *temp;
      i--;
      parentI = (int)floor((i-1)/2);
    }
  }
}

void Heap::output(int index)
{
  if(index < 1000 && heap[index] != 0)
  {
    cout << heap[index] << ", "; //print value at current index
    output((2 * index) + 1); //call function for right child
    output((2 * index) + 2); //call function for left child
  }
  else return;
}