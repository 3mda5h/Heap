#include <iostream>
#include <cstring>
#include "Heap.h"

using namespace std;

int main() 
{
  char input[10000];
  int numbers[100];
  Heap* heap = new Heap();
  while(strcmp(input, "quit") != 0)
  {
    cout << "Enter INPUT, OUTPUT, DISPLAY, or QUIT" << endl;
    cin.getline(input, 100);
    if(strcmp(input, "input") == 0)
    {
      cout << "FILE or CONSOLE?" << endl;
      cin.getline(input, 100);
      if(strcmp(input, "file") == 0)
      {
        cin.getline(input, 100);
      }
      if(strcmp(input, "console") == 0)
      {
        cout << "enter a list of numbers seperated by spaces" << endl;
        cin.getline(input, 10000);
        int j = 0;
        int k = 0;
        char currentnumber[10]; //current number
        for(int i = 0; i < strlen(input); i++)
        {
          if(input[i] != ' ')
          {
            currentnumber[j] = input[i]; //add current char in input to current number 
            j++; //j keeps track of where we are in currentnumber[]
          }
          if(input[i] == ' ' || input[i + 1] == NULL)//if reaches space or end of input array 
          {
            numbers[k] = atoi(currentnumber); //current number char array converted to int and put in int array
            k++; //k keeps track of where we are in numebrs[]
            j = 0;
            for(int i = 0; i < 10; i++) //reset current number
            {
              currentnumber[i] = NULL;
            }
          }
        }
      }
      cout << "input arrary contains:" << endl;
      for(int i = 0; i < 100; i++)
      {
        if(numbers[i] != 0)
        {
          heap->insert(numbers[i]);
          cout << numbers[i] << ", ";
        }
      }
      cout << "outputting: " << endl;
      heap->output(0);
    }
  }
}