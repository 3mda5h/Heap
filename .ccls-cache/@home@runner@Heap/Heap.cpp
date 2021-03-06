#include <iostream>
#include "Heap.h"
#include <math.h>

using namespace std;

Heap::Heap()
{
  heap = new int[100];
}

//sets all values in the heap to 0, for if user inputs new dataset without sorting(removing) the old one
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
  int parentI = (int)floor((i-1)/2); //parent index
  heap[i] = newNumber;
  while(heap[i] > heap[parentI] && i > -1) //while child is greater than parent
  {
    //swap parent and current node 
    int temp = heap[parentI];
    heap[parentI] = newNumber; 
    heap[i] = temp;
    i = parentI; 
    parentI = (int)floor((i-1)/2);
  }
}

//remove numbers from heap in order from greatest to least, the print out the sorted output
void Heap::sort()
{
  if(heap[0] == 0)
  {
    cout << "There's no input to sort D:" << endl;
    return;
  }
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
  heap[0] = 0;
}

//if parent is not greater than both children, swap parent with greatest child
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
  else if(parent < rightChild || parent < leftChild) //both children are the same value so there's no greater child 
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

//visually display tree using tabs
void Heap::display(int parentI, int level)
{
  if(heap[parentI] == 0 && level == 0)
  {
    cout << "Tree is empty :(" << endl;
    return;
  }
  if(heap[parentI] != 0)
  {
    display((2*parentI) + 2, level + 1);
    printTabs(level);
    cout << heap[parentI] << endl;
    display((2*parentI) + 1, level + 1);
  }
  else return;
}

//prints tabs according to level of tree that value is at
void Heap::printTabs(int level)
{
  for(int i = 0; i < level; i++)
  {
    cout << "     ";    
  }
}