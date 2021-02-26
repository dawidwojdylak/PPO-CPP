#pragma once


//struktura reprezentujaca wektor o wymiarze nDim
typedef struct vector{
  short *value;
  unsigned short nDim;
} Vector;

//struktura reprezentujaca macierz[rows x cols]
typedef struct matrix{
  short **value;
  unsigned short rows;
  unsigned short cols;
} Matrix;

//funkcja tworzaca wektor typu struct vector (wymiar, wartosc kazdej komorki)
Vector *form_Vector(unsigned short length = 3, short value = 0);

//funkcja tworzaca macierz typu struct matrix (rzedy, kolumny, wartosc kazdej komorki)
const Matrix *form_Matrix(unsigned short rows = 3, unsigned short cols = 3, short value = 0);

//procedura wypisujaca wektor typu struct vector
void print(const Vector vec);

//procedura wypisujaca macierz typu struct matrix
void print(const Matrix m);

//procedura zwalniajaca pamiec 
void deleteAll(const Matrix *m);

//procedura usuwajaca wektor typu struct vector zwalniajaca pamiec 
void deleteAll(const Vector *vec);

//procedura dodajaca dwa wektory typu struct vector
bool addFirstToSecond(Vector vec1, Vector vec2);

//procedura zmieniajaca wymiar wektora typu struct vector
void setNewDimension(Vector &vec, unsigned short newSize);