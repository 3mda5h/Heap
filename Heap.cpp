#include <iostream>
#include "Heap.h"
#include <math.h>

using namespace std;

Heap::Heap()
{
  heap = new int[1000];
}

//insert number into the heap
void Heap::insert(int newNumber)
{
  //find empty spot at end of tree to insert new number
  int i = 999;
  while(heap[i-1] == 0 && i != 0)
  {
    i--;    
  }
  //i is now first empty spot in array
  cout << "index " << i << " is the first empty spot" << endl;
  if(i == 0) //if this is the first number inserted into array 
  {
    heap[i] = newNumber;
    return;
  }
  //children: 2i+1, 2i+2 parent: ⌊(i−1)/2⌋, L = floor
  int parentI = (int)floor((i-1)/2); //parent index
  cout << "the parent of this index is index " <<parentI << " (" << heap[parentI] << ")" << endl;
  heap[i] = newNumber;
  if(heap[i] < heap[parentI]) 
  {
    return; //parent greater than child, heap property maintained
  }
  while(newNumber > heap[parentI] && i > -1) //while child is greater than parent
  {
    //swap parent and current node 
    cout << "swapping " << heap[i] << " with parent " << heap[parentI] << endl;
    int temp = heap[parentI];
    heap[parentI] = newNumber; 
    heap[i] = temp;
    i--;
    parentI = (int)floor((i-1)/2);
  }
}

//print out numbers in order from greatest to smallest
void Heap::output()
{
  int output[100];
  int outputi = 0;
  for(int j = 0; j < 100; j++) output[j] = 0;

  do
  {
    //find last element
    int last = 999;
    while(heap[last] == 0 && last != 0)
    {
      last--;    
    }
    //replace root with last element
    heap[0] = heap[last];
    heap[last] = 0;
    downHeap(0);
    output[outputi] = heap[0];
    outputi++;
  } while(last != 0);

  /*if(index < 1000 && heap[index] != 0)
  {
    cout << heap[index] << ", "; //print value at current index
    output((2 * index) + 1); //call function for right child
    output((2 * index) + 2); //call function for left child
  }
  else return;*/
}
void Heap::downHeap(int parent)
{
  int rightChild = heap[2*i + 1];
  int leftChild = heap[2*i + 2];
  if(heap[parent] < rightChild && rightChild > leftChild)
  {
    //swap parent with right child
    int temp = heap[parent];
    heap[parent] = rightChild;
    heap[2*i + 1] = temp;
    swap(2*i + 1);
  }
  if(heap[parent] < leftChild && leftChild > rightChild)
  {
    //swap parent (heap[i]) with right child
    int temp = heap[parent];
    heap[parent] = leftChild;
    heap[2*i + 2] = temp;
    swap(2*i + 2);
  }
}

//visually display heap as a tree using tabs
void Heap::display()
{
  //start at the far right bottom end of the tree
  //print it endl
  //pint its parent endl
  //print left child of that parent endl
  //print parent of parent endl 

  /* un ejemplo de como quedaría: 

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