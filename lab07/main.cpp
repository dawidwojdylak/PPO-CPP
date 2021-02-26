#include "include/lab07.h"
#include <iostream>

int main(){
  Vector * w1 = form_Vector();
  const Matrix * m1 = form_Matrix();

  std::cout << "Vector #1:" << std::endl;
  print(*w1);
  std::cout << "\nMatrix #1:" << std::endl;
  print(*m1);

  deleteAll(w1);
  deleteAll(m1);

  std::cout << "\n-----------------" << std::endl;

  w1 = form_Vector(3);
  m1 = form_Matrix(2,4);

  std::cout << "\nVector #1 again:" << std::endl;
  print(*w1);
  std::cout << "\nMatrix #1 again:" << std::endl;
  print(*m1);

  std::cout << "\n-----------------" << std::endl;

  /*const*/ Vector * const w2 = form_Vector(2,4); // odkomentowanie "const" powinno spowodowac blad kompilatora
  const Matrix * const m2 = form_Matrix(2,4,4);

  std::cout << "\nVector #2:" << std::endl;
  print(*w2);
  std::cout << "\nMatrix #2:" << std::endl;
  print(*m2);

  std::cout << "\n-----------------\n" << std::endl;

  std::cout << "Adding two vectors: " << (addFirstToSecond(*w2, *w1) ? "SUCCESS" : "FAIL") << std::endl;
  setNewDimension(*w2, w1->nDim);
  std::cout << "\nVector #2 again:" << std::endl;
  print(*w2);
  //std::cout << "w2 ndiw = " << w2 -> nDim;
  std::cout << "\nAdding two vectors: " << (addFirstToSecond(*w2, *w1) ? "SUCCESS" : "FAIL") << std::endl;

  std::cout << "\nVector #1 again:" << std::endl;
  print(*w1);

  deleteAll(w1);
  deleteAll(m1);
  deleteAll(w2);
  deleteAll(m2);
  
}


/* //OUTPUT:
Vector #1:
[0, 0, 0]

Matrix #1:
[ 0 0 0 ]
[ 0 0 0 ]
[ 0 0 0 ]

-----------------

Vector #1 again:
[0, 0, 0]

Matrix #1 again:
[ 0 0 0 0 ]
[ 0 0 0 0 ]

-----------------

Vector #2:
[4, 4]

Matrix #2:
[ 4 4 4 4 ]
[ 4 4 4 4 ]

-----------------

Adding two vectors: FAIL

Vector #2 again:
[4, 4, 0]

Adding two vectors: SUCCESS

Vector #1 again:
[4, 4, 0]
*/