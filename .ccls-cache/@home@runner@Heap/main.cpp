#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
  char* input[10000];
  int numbers[1000];
  while(strcmp(input, "quit") != 0)
  {
    cout << "Enter INPUT, OUTPUT, DISPLAY, or QUIT" << endl;
    if(strcmp(input, "insert") == 0)
    {
      cin.getline(input, 100);
      cout << "FILE or CONSOLE?" << endl;
      if(strcmp(input, "file") == 0)
      {
        cin.getline(input, 100);
      }
      if(strcmp(input, "console") == 0)
      {
        cout << "enter list of numbers seperated by spaces" << endl;
        cin.getline(input, 10000);
        char* number[10];
        int j = 0;
        int k = 0;
        for(int i = 0; i < strlen(input); i++)
        {
          if(input[i] != " ")
          {
            number[j] = input[i];
            j++
          }
          if(input[i] == " ")
          {
            numbers[k] = atoi(number);
            k++;
          }
        }
      }
    }
  }
}