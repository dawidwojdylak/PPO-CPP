#pragma once

typedef int counter;
void initCounter(counter * a);
double *initGeometricalSequence(double a1, double q, int n);//(pierwszy wyraz, iloraz, liczba elementow)
double *initArithmeticSequence(double a1, double r, int n);//(pierwszy wyraz, roznica, liczba elementow)
void printSequence(const double *sequence, int n);
void deleteSequence(const double **sequence);
void addSequence(const double*** sequencesList, double** sequencesLenghtsList, 
double *initedSequence, int length);
void printAllSequences(const double** sequencesList, double* sequencesLenghtsList);
void deleteAllSequences(const double** sequencesList, double* sequencesLenghtsList);