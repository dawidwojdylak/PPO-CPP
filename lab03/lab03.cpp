#include "lab03.h"
#include <iostream>

void printArray(struct myArray a) //prints an array which is a part of structure myArray
{
  if(a.N < 1) //size of array cannot be less than 1
  {
    std::cout << "Cannot print empty array." << std::endl;
    return;
  }
  int i;
  //printing array
  std::cout << "[";
  for(i = 0; i < a . N - 1; i++)
    std::cout << a . arr[i] << ",";
  std::cout << a . arr[i] << "]";

}

int fillArrayWithFibonacci(struct myArray *a, int n) //fills array of struct myArray with Fibonacci series
{
  if(a == 0)//"a" has to exist 
  {
    std::cout << "Empty pointer provided." << std::endl;
    return 0;
  }
  if (n < 1) //size of array cannot be less than 1
  {
    std::cout << "Wrong number of dimensions." << std::endl;
    return 0;
  }
  //setting size of the array to user's n
  a -> N = n;
  for(int i = 0; i < n; i++) //filling array with Fibonacci series
    a -> arr[i] = Fibonacci(i);

  return 1;
}

int Fibonacci(int n)//recursive Fibonacci series generator
{
  if (n < 2)
    return 1;
  else 
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void revert(struct myArray *a)
{
  if(a == 0)
  {
    std::cout << "Empty pointer provided." << std::endl;
    return;
  }
  int i, temp[MAX_SIZE];
  for (i = 0; i < a -> N; i++)
    temp[a -> N - i - 1] = a -> arr[i];
  for (i = 0; i < a -> N; i++)
    a -> arr[i] = temp[i];
  printArray(*a);
  std::cout << " (reverting done)" << std::endl;
}

void extend(struct myArray *a, int n)
{
  if(a == 0)
  {
    std::cout << "Empty pointer provided." << std::endl;
  }
  if(n > MAX_SIZE)
  {
    std::cout << "Wow, you've just gone crazy (" << n << ">" << MAX_SIZE << ")." << std::endl;
  }
  else
  {
    a -> N += n; 
    printArray(*a);
    std::cout << " (extending by " << n << " done)" << std::endl;
  }
}

void truncate(struct myArray *a, int n)
{
  if(a == 0)
  {
    std::cout << "Empty pointer provided." << std::endl;
    return;
  }
  if(n > a -> N)
  {
    std::cout << "Reducing array size to 0" << std::endl;
    a -> N = 0;
  }
  else
  {
    a -> N -= n;
    printArray(*a);
    std::cout << " (truncation by " << n << " done)" << std::endl;
  }
}

void checkArraySpouse(struct myArray *a)
{
  if(a -> spouse == 0)
  {
    printArray(*a);
    std::cout << " has no spouse." << std::endl;
  }
  else
  {
    printArray(*a);
    std::cout << " is paired with ";
    printArray(*(a -> spouse));
    std::cout << std::endl;
  }
}

void marry(struct myArray *a, struct myArray *b)//tries to make pair of two arrays (of struct myArray)
{
  if(a == 0 || b == 0)
  {
    std::cout << "Null pointer provided" << std::endl;
    return;
  }
  if(a == b)//checks if they are the same array
  {
    std::cout << "Can't marry myself" << std::endl;
    return;
  }
  int counter = 0;//finds out if arrays have the same content
  for(int i = 0; i < a -> N; i++)
    if(a -> arr[i] == b -> arr[i])
      counter++;
  if(counter == a -> N) //if they have the same content
  {
    std::cout << "Can't marry my twin" << std::endl;
    return;
  }
  
  a -> spouse = b;
  b -> spouse = a;
}

void divorce(struct myArray *a, struct myArray *b)
{
  a -> spouse = b -> spouse = 0; //undoes pair of two arrays
}

struct myArray formChild(struct myArray *a, struct myArray *b)
{
  struct myArray child;
  if(a == 0 && b == 0)
  {
    std::cout << "I ain't God." << std::endl;
    return child;
  }
  if(a == 0 || b == 0)
  {
    std::cout << "No partenogenesis possible." << std::endl;
    return child;
  }
  if(a -> spouse == b)
  {
    child.parent1 = a;
    child.parent2 = b;
  
    child.N = a -> N + b -> N;
    for (int i = 0; i < a->N; i++)
    {
      child.arr[i] = a -> arr[i];
    }
      for (int i = 0; i < b->N; i++)
    {
      child.arr[i] = b -> arr[i];
    }
      return child;
  }
  else
  {
    std::cout << "Only spouses may have children." << std::endl;
    return child;
  }
}

void  printParents(struct myArray *a)
{
  if(a -> parent1 == 0 || a -> parent2 == 0)
  {
    printArray(*a);
    std::cout<<" has no parents." << std::endl;
    return;
  }
  std::cout << "Parents of ";
  printArray(*a);
  std::cout << " are ";
  printArray(*(a->parent1));
  std::cout << " and ";
  printArray(*(a->parent2));
}