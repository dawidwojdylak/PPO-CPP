#include <iostream>
#include "lab02.h"

unsigned long long int counter = 0;

void printVec(struct vecM *vec)
{
  int i;
  if(vec->N == 0)
  {
    std::cout << "Cannot print empty vector." << std::endl;
    return;
  }
  std::cout << "[" ;
  for(i = 0; i < vec -> N - 1; i++)
    std::cout << vec -> vec[i] << ",";
  std::cout << vec -> vec[i] << "]"; //<< std::endl;
}

void swap(struct vecM *a, struct vecM *b)
{
  struct vecM *c = a;
  a = b;
  b = c;
}

int fillVecWithFibonacci(struct vecM *vec,int n)
{
  if(n < 1)
  {
    std::cout << "Wrong number of dimensions." << std::endl;
    return 0;
  }
  if(vec == NULL)
  {
    std::cout << "Empty pointer provided." << std::endl;
    return 0;
  }

vec -> N = n;
for(int i = 0; i < n; i++)
  vec -> vec[i] = fibbonaci(i);

//std::cout << counter;
return 1;
}

int fibbonaci(int n)
{
  //count();
  if(n < 2)
    return 1;
  else 
    return fibbonaci(n - 1) + fibbonaci(n - 2);
}

void revert(struct vecM *a)
{
  int i, temp[MAX_L];
  for(i = 0; i < a -> N; i++)
  {
    temp[a -> N - i - 1] = a -> vec[i];
  }
  for (i = 0; i < a -> N; ++i)
  {
    a->vec[i] = temp[i];
  }
  printVec(a);
  std::cout << " (Reverting done)" << std::endl;
}

void extend(struct vecM *a, int n)
{
  if(n > MAX_L)
  {
    std::cout << "Wow, you've just gone crazy (" << n << ">" << MAX_L << ")." << std::endl;
    return;
  }

  a -> N += n;
  printVec(a);
  std::cout << " (extending by " << n << " done)" << std::endl;
}

void truncate(struct vecM *a, int n)
{
  if(n > a -> N)
  {
    a -> N = 0;
    std::cout << "The vector's length has been reduced to 0" << std::endl;
  }
  a -> N = a -> N - n;
  printVec(a);
  std::cout << " (truncation by " << n << " done)" << std::endl;
}

void checkVecSpouse(struct vecM *a)
{
  if(a -> next == NULL)
  {
    printVec(a);
    std::cout << " has no spouse." << std::endl;
    return;
  }
  printVec(a);
  std::cout << " is paired with ";
  printVec(a -> next);
  std::cout << std::endl;
}

void marry (struct vecM *a, struct vecM *b)
{
  int counter = 0;
  for (int i = 0; i < a -> N; i++)
    if(a -> vec[i] == b -> vec[i])
      counter++;
  if(a == b) 
    std::cout << "I cant marry myself!" << std::endl;
  else if(counter == a -> N)
    std::cout << "Can't marry my twin!" << std::endl;
  else 
  {
    a -> next = b;
    b -> next = a;
  }
}

void divorce (struct vecM *a, struct vecM *b)
{
  a -> next = b -> next = NULL;
}

/*void count()
{
  counter++;
}*/