#pragma once
#define MAX_L 50 //maximum vector length

struct vecM
{
  int N = 0; 
  int vec[MAX_L] = {0};
  struct vecM *next = NULL;
};


void printVec(struct vecM *vec);

void swap(struct vecM *a, struct vecM *b);

int fillVecWithFibonacci(struct vecM *vec,int n);

int fibbonaci(int n);

void revert(struct vecM *a);

void extend(struct vecM *a, int n);

void truncate(struct vecM *a, int n);

void checkVecSpouse(struct vecM *a);

void marry (struct vecM *a, struct vecM *b);

void divorce (struct vecM *a, struct vecM *b);

//void count();