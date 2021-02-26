//#pragma once

#define MAX_SIZE 50

struct myArray{
  int arr[MAX_SIZE] = {0};
  int N = 0;
  struct myArray *spouse = 0;
  struct myArray *parent1 = 0;
  struct myArray *parent2 = 0;
};

void printArray(struct myArray a);

int fillArrayWithFibonacci(struct myArray *a, int n);

int Fibonacci(int n);

void revert(struct myArray *a);

void extend(struct myArray *a, int n);

void truncate(struct myArray *a, int n);

void checkArraySpouse(struct myArray *a);

void marry(struct myArray *a, struct myArray *b);

void divorce(struct myArray *a, struct myArray *b);

struct myArray formChild(struct myArray *a, struct myArray *b);

void  printParents(struct myArray *a);