#include <iostream>
#include "lab04.h"

void initCounter(counter * a){}

double *initGeometricalSequence(double a1, double q, int n){
  if(n < 1)
  {
    std::cout << "Size must be non-zero (and positive)" << std::endl;
    return 0;
  }

  double *sequence = 0;
  sequence = (double *)(malloc(n * sizeof(double))); 
  
  *sequence = a1;
  for(int i = 1; i < n; ++i)
    sequence[i] = sequence[i - 1] * q;

  return sequence;
}

double *initArithmeticSequence(double a1, double r, int n){
  if(n < 1)
  {
    std::cout << "Size must be non-zero (and positive)" << std::endl;
    return 0;
  }

  double *sequence = 0;
  sequence = (double *)malloc(n * sizeof(double));
  
  *sequence = a1;
  for(int i = 1; i < n; ++i)
    sequence[i] = sequence[i - 1] + r;

  return sequence;
}

void printSequence(const double *sequence, int n){
  if(sequence == 0 || n < 1)
    std::cout << "Nothing to print." << std::endl;
  else 
  {
    int i;
    std::cout << "(";
    for(i = 0; i < n - 1; i++)
      std::cout << sequence[i] << ",";
    std::cout << sequence[i] << ")" << std::endl;
  }
}

void deleteSequence(const double **sequence){
  if(sequence == 0)
  {
    std::cout << "Nothing to delete." << std::endl;
    return;
  }
  else 
  {
    free(sequence);
    std::cout << "Sequence deleted." << std::endl;
  }
}

void addSequence(const double*** sequencesList, double** sequencesLenghtsList, 
double *initedSequence, int length){
  
}

void printAllSequences(const double** sequencesList, double* sequencesLenghtsList)
{

}
void deleteAllSequences(const double** sequencesList, double* sequencesLenghtsList)
{

}

