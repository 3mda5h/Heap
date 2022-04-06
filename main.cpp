/*Max heap - binary tree where the parent must be greater than its children. Implemented as an array. 
User can input numbers, output them sorted from greast to least, or visually display tree
By Emily MacPherson 4/2/22
*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
#include "Heap.h"

using namespace std;

void consoleInput(Heap* heap);
void fileInput(Heap* heap);

int main() 
{
  char input[100];
  Heap* heap = new Heap();
  while(strcmp(input, "quit") != 0)
  {
    cout << "Enter INPUT, SORT, DISPLAY, or QUIT" << endl;
    cin.getline(input, 100);
    if(strcmp(input, "input") == 0)
    {
      cout << "FILE or CONSOLE?" << endl;
      cin.getline(input, 100);
      if(strcmp(input, "file") == 0)
      {
        heap->clear();
        fileInput(heap);
      }
      else if(strcmp(input, "console") == 0)
      {
        heap->clear();
        consoleInput(heap);
        cout << "Input successful" << endl;
      }
    }
    else if(strcmp(input, "sort") == 0)
    {
      heap->sort();
    }
    else if(strcmp(input, "display") == 0)
    {
      heap->display(0, 0);
    }
    cout << "----------" << endl;
  }
}

//read in list of numbers seperated by spaces from the console
void consoleInput(Heap* heap)
{
  char input[10000];
  cout << "Enter a list of numbers seperated by spaces" << endl;
  cin.getline(input, 10000);
  int j = 0;
  char currentNumber[5]; //current number
  for(int i = 0; i < strlen(input); i++)
  {
    if(input[i] != ' ')
    {
      currentNumber[j] = input[i]; //add current char in input to current number 
      j++; //j keeps track of where we are in currentnumber[]
    }
    if(input[i] == ' ' || i == strlen(input) - 1)//if reaches space or end of input array 
    {
      heap->insert(atoi(currentNumber));
      j = 0; 
      for(int i = 0; i < 4; i++) //reset current number
      {
        currentNumber[i] = 0;
      }
    }
  }
}

//read in list of numbers seperated by spaces from a file
void fileInput(Heap* heap)
{
  char input[100];
  int number;
  cout << "Name of file?" << endl;
  cin.getline(input, 100);
  ifstream file(input);
  if(!file.is_open())
  {
    cout << "Could not open file D:" << endl;
    return;
  }
  while (file >> number) //reads in ints from file till end of file reached
  {
    heap->insert(number);
  }
  cout << "Input successful" << endl;
}