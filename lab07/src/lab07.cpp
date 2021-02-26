#include <iostream>
#include "../include/lab07.h"

Vector *form_Vector(unsigned short length, short value)
{
  //alokacja pamieci na nowy wektor
  Vector *newVector = new Vector;
  newVector -> nDim = length;
  //alokacja tablicy (1D)
  newVector -> value = new short [length];
  //wypelnienie wektora wartoscia value
  for(int i = 0; i < length; i++)
    newVector -> value[i] = value;
  return newVector;

}

const Matrix *form_Matrix(unsigned short rows, unsigned short cols, short value)
{
  //tworzenie nowej macierzy
  Matrix *newMatrix = new Matrix; 
  newMatrix -> rows = rows;
  newMatrix -> cols = cols;
  int i,j;

  //alokacja pamieci (tablica 2D)
  newMatrix -> value = new short * [rows];
  for(i = 0; i < rows; i++)
    newMatrix -> value[i] = new short [cols];

  //wypelnienie macierzy wartoscia value
  for(i = 0; i < rows; i++)
    for(j = 0; j < cols; j++)
      newMatrix -> value[i][j] = value;

  return newMatrix;
}
void print(const Vector vec)
{
  unsigned short i;
  std::cout << "[";
  for (i = 0; i < vec.nDim - 1; i++)
    std::cout << vec.value[i] << ", ";
  std::cout << vec.value[i] << "]\n";
}

void print(const Matrix m)
{
  int i,j;
  for (i = 0; i < m.rows; i++)
  {
    std::cout << "[ ";
    for(j = 0; j < m.cols; j++)
      std::cout << m.value[i][j] << " ";
    std::cout << "]\n";
  }
}

void deleteAll(const Vector *vec)
{
  delete [] vec -> value;
  delete vec;
  vec = 0;
}

void deleteAll(const Matrix *m)
{
  //zwalniam kazda komorke i na koncu cala tablice
  for(int i = 0; i < m -> rows; i++)
    delete [] m -> value[i];
  delete [] m -> value; 
  //zwalniam strukture
  delete m;
  m = 0;
}


bool addFirstToSecond(Vector vec1, Vector vec2)
{
  if(vec1.nDim != vec2.nDim) return 0;
  for(int i = 0; i < vec1.nDim; i++)
    vec2.value[i] += vec1.value[i];
  return 1;
}

void setNewDimension(Vector &vec, unsigned short newSize)
{
  int i;

  //zapamietaj elementy wektora
  int tempArr[vec.nDim];
  for (i = 0; i < vec.nDim; ++i)
    tempArr[i] = vec.value[i];

  //zwolnij tablice wektora
  delete [] (vec.value);

  //przydziel nowa wieksza pamiec
  vec.value = new short [newSize];

  //wczytaj stare wartosci do wektora
  for (i = 0; i < vec.nDim; i++)
    vec.value[i] = tempArr[i];

  int temp = i;

  //wypelnij nowe komorki zerami
  for(i = temp; i < newSize; i++)
    vec.value[i] = 0;

  vec.nDim = newSize;
}