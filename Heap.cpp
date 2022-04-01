#include <iostream>
#include "Heap.h"
#include <math.h>

using namespace std;

Heap::Heap()
{
  heap = new int[100];
}

void Heap::clear()
{
  for(int i = 0; i < 100 ; i++) heap[i] = 0;
}

//insert number into the heap
void Heap::insert(int newNumber)
{
  //find empty spot at end of tree to insert new number
  int i = 99;
  while(heap[i-1] == 0 && i != 0)
  {
    i--;    
  }
  //i is now first empty spot in array
  if(i == 0) //if this is the first number inserted into array 
  {
    heap[i] = newNumber;
    return;
  }
  //children: 2i+1, 2i+2 parent: ⌊(i−1)/2⌋, L = floor
  int parentI = (int)floor((i-1)/2); //parent index
  heap[i] = newNumber;
  while(heap[i] > heap[parentI] && i > -1) //while child is greater than parent
  {
    //swap parent and current node 
    int temp = heap[parentI];
    heap[parentI] = newNumber; 
    heap[i] = temp;
    i = parentI; //move current index to parent index
    parentI = (int)floor((i-1)/2);
  }
}

//print out numbers in order from greatest to smallest
void Heap::sort()
{
  int output[100];
  int outputi = 0;
  for(int j = 0; j < 100; j++) output[j] = 0;

  //find last element
  int last = 99;//index of last element in array/tree
  while(heap[last] == 0 && last != 0)
  {
    last--;    
  }
  //add root to output
  output[outputi] = heap[0];
  outputi++;
  do
  {
    //replace root with last element
    heap[0] = heap[last];
    if(last > 0) 
    {
      heap[last] = 0;
      downHeap(0); //re-establish heap property
    }
    //add root to output
    output[outputi] = heap[0];
    outputi++;
    last--;
  } while(last > 0);

  for(int i = 0; i < 100; i++)
  {
    if(output[i] != 0)
    {
      cout << output[i] << ", ";
    }
  }
  cout << endl;
}

//if parent is not greater than both children, replace swap parent with greatest child
void Heap::downHeap(int i)
{
  int parent = heap[i];
  int rightChild = heap[(2*i) + 1];
  int leftChild = heap[(2*i) + 2];
  if((parent < rightChild || parent < leftChild) && rightChild > leftChild)
  {
    //swap parent with right child
    heap[i] = rightChild;
    heap[(2*i) + 1] = parent;
    downHeap((2*i) + 1);
  }
  else if((parent < rightChild || parent < leftChild) && leftChild > rightChild)
  {
    //swap parent with left child
    heap[i] = leftChild;
    heap[(2*i) + 2] = parent;
    downHeap((2*i) + 2);
  }
  else if(parent < rightChild || parent < leftChild) //both children are the value so there's no greater child 
  {
    //swap parent with right child
    heap[i] = rightChild;
    heap[(2*i) + 1] = parent;
    downHeap((2*i) + 1);
  }
  else if(parent > leftChild && parent > rightChild)
  {
    return;
  }
}

//visually display heap as a tree using tabs
void Heap::display(int parentI, int level)
{
  //temporary display
  /*if(heap[parentI] != 0)
  {
    cout << "parent " << heap[parentI] << " has children " << heap[(2*parentI) + 1] << " and " << heap[(2*parentI) + 2] << endl;
    display((2*parentI) + 1, 0);
    display((2*parentI) + 2, 0);
  } */
  if((2*parentI) + 2 < 100 || heap[(2*parentI) + 1] != 0 ) //if parent has a right child
  {
    display((int)floor((parentI-1)/2), level++);
  }
  else if((2*parentI) + 1 < 100 || heap[(2*parentI) + 1] != 0 ) //if parent has left child but no right??
  {
    display((int)floor((parentI-1)/2), level++);
  }
  else
  {
    printTabs(level);
    cout << heap[parentI] << endl;
    return;
  }
 
  /*
  
            84
        89
            82  
    99
            81
        96  
            80
100
            89
        94
            90  
    98
            91
        95
            87

*/
}

//prints tabs according to level of tree that value is at
void Heap::printTabs(int level)
{
  for(int i = 0; i < level+1; i++)
  {
    cout << "  ";    
  }
}