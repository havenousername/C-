#include <string>
#include <iostream>

#define LENGTH 10

std::string createPhoneNumber(const int arr[LENGTH])
{
  std::string output = "";
  for (int i = 0; i < LENGTH; i++)
  {
    if (i == 0)
    {
      output.push_back('(');
      output.push_back((char)arr[i]);
    }
    if (i == 2)
    {
      output.push_back((char)arr[i]);
      output.push_back(')');
      output.push_back(' ');
    }
    if (i == 5)
    {
      output.push_back((char)arr[i]);
      output.push_back('-');
    }
    else
    {
      output.push_back((char)arr[i]);
    }
  }

  return output;
}

  int main()
  {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << createPhoneNumber(arr);
    return 0;
  }
