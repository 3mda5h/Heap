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
void Heap::output()
{
  int output[100];
  int outputi = 0;
  for(int j = 0; j < 100; j++) output[j] = 0;

  //find last element
  int last = 99;
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
    cout << "root is now " << heap[0] << endl;
    heap[last] = 0;
    cout << "root after downHeap is " << heap[0] << endl;
    downHeap(0); //re-establish heap property
    last--;
    //add root to output
    output[outputi] = heap[0];
    outputi++;
  } while(last != 0);

  for(int i = 0; i < 100; i++)
  {
    if(output[i] != 0)
    {
      cout << output[i] << ", ";
    }
  }
  cout << endl;
}

//if parent is not greater than both children, replace parent with greatest child
void Heap::downHeap(int i)
{
  int parent = heap[i];
  int rightChild = heap[(2*parent) + 1];
  int leftChild = heap[(2*parent) + 2];
  if((parent < rightChild || parent < leftChild) && rightChild > leftChild)
  {
    //swap parent with right child
    heap[i] = rightChild;
    cout << "heap[i]: " << leftChild << endl;
    cout << "parent: " << parent << endl;
    heap[(2*parent) + 1] = parent;
    downHeap((2*parent) + 1);
  }
  else if((parent < rightChild || parent < leftChild) && leftChild > rightChild)
  {
    //swap parent with left child
    heap[i] = leftChild;
    cout << "heap[i]: " << leftChild << endl;
    cout << "parent: " << parent << endl;
    heap[(2*parent) + 2] = parent;
    downHeap((2*parent) + 2);
  }
  else if(parent > leftChild && parent > rightChild)
  {
    return;
  }
}

//visually display heap as a tree using tabs
void Heap::display(int i)
{
  //temporary display
  if(heap[i] != 0)
  {
    cout << "parent " << heap[i] << " has children " << heap[(2*i) + 1] << " and " << heap[(2*i) + 2] << endl;
    display((2*i) + 1);
    display((2*i) + 2);
  }

  /*
  start at the far right bottom end of the tree
  print it 
  pint its parent 
  print left child of that parent 
  print parent of parent 
  ??
  
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