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
      if(strcmp(input, "console") == 0)
      {
        heap->clear();
        consoleInput(heap);
      }
    }
    if(strcmp(input, "sort") == 0)
    {
      heap->sort();
    }
    if(strcmp(input, "display") == 0)
    {
      heap->display(0, 0);
    }
  }
}

void consoleInput(Heap* heap)
{
  char input[10000];
  cout << "enter a list of numbers seperated by spaces" << endl;
  cin.getline(input, 10000);
  int j = 0;
  char currentNumber[4]; //current number
  for(int i = 0; i < strlen(input); i++)
  {
    if(input[i] != ' ')
    {
      cout << "adding " << input[i] << " to currentNumber" << endl;
      currentNumber[j] = input[i]; //add current char in input to current number 
      j++; //j keeps track of where we are in currentnumber[]
    }
    if(input[i] == ' ' || i == strlen(input) - 1)//if reaches space or end of input array 
    {
      cout << currentNumber << endl;
      heap->insert(atoi(currentNumber));
      j = 0; 
      for(int i = 0; i < 4; i++) //reset current number
      {
        currentNumber[i] = 0;
      }
    }
  }
}

void fileInput(Heap* heap)
{
  char input[100];
  int number;
  cout << "Name of file?" << endl;
  cin.get(input, 100);
  ifstream file(input);
  if(!file.is_open())
  {
    cout << "Could not open file D:" << endl;
  }
  while (file >> number)
  {
    heap->insert(number);
  }
}