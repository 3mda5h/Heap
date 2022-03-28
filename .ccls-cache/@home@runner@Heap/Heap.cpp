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