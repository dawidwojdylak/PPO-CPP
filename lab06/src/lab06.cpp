#include "../include/lab06.h"
#include <iostream>
#include <cmath>


/*typedef struct bits {
  int bit[B_SIZE];
  int bitSize; //liczba zajetych bitow
} Bits;*/

void set(Bits *bit, int *data, int size)
{
  if (bit == 0)
  {
    std::cout << "pusty wskaznik" << std::endl;
    return;
  }
  
  for (int i = 0; i < size; i++)
    bit -> bit[i] = data[i];
  bit -> bitSize = size;
}


void print(const Bits *bit)
{
  for(int i = 0; i < bit -> bitSize; i++)
    std::cout << bit -> bit[i];
  std::cout << std::endl << std::endl;  
}

Bits add_up(const Bits *bit1, const Bits *bit2)
{
      print(bit1);
      print(bit2);
  Bits sum;
  int biggerSize, temporarySum = 0, flag = 0;
  if(bit1 -> bitSize > bit2 -> bitSize) biggerSize = bit1 -> bitSize;
  else biggerSize = bit2 -> bitSize;
  sum.bitSize = biggerSize;

  int tempBit1[bit1->bitSize];
  for (int i = bit1->bitSize - 1; i >=0; i--)
  
    tempBit1[bit1->bitSize - i] = bit1->bit[i]; 

  
  //odwroc drugiego bita
  int tempBit2[bit2->bitSize];
  for (int i = bit2->bitSize - 1; i >=0; i--)
    tempBit2[bit2->bitSize - i] = bit2->bit[i]; 

  //dodaj bity
  for(int i = 0; i < biggerSize; i++)
  {
    temporarySum = (tempBit1[i] + tempBit2[i] + flag);
    sum.bit[i] = temporarySum % 2;
    if(tempBit1[i] == 1 && tempBit2[i] == 1)
            flag = 1;
          else flag = 0; 
  }

  return sum;
}

Bits add_upV2(const Bits *bit1, const Bits *bit2)
{
  /*std::cout << "*** add_upV2 ***\n ------------------------------------\n";
  std::cout << "bit1: \n";
  print(bit1);
  std::cout << "bit2: \n";
  print(bit2);
  */
  Bits sum;

  int whichIsBigger, flag = 0, temporarySum = 0;
  if(bit1 -> bitSize > bit2 -> bitSize) whichIsBigger = bit1 -> bitSize;
  else whichIsBigger = bit2 -> bitSize;
  sum.bitSize = whichIsBigger;
  //std::cout << "whichIsBigger: " << whichIsBigger << std::endl;

  //std::cout << "\n\n";
  //odwracam 1. bit
  Bits tempBit1;
  tempBit1.bitSize = bit1 -> bitSize;
  for(int i = bit1 -> bitSize - 1; i >= 0; i--)
  {
    tempBit1.bit[bit1 -> bitSize - i - 1] = bit1 -> bit[i];
    //pomocniczo
  /*std::cout << "i: " << i << std::endl;
    std::cout << "bit1 -> bit[i]: " << bit1 -> bit[i] << std::endl;
    std::cout << "tempBit1.bit[bit1 -> bitSize - i]: " << tempBit1.bit[bit1 -> bitSize - i] << std::endl;
    std::cout << "bit1 -> bitSize - i - 1: " << bit1 -> bitSize - i -1 << std::endl;
  */
  }
  //std::cout << "\n\n";

  //odwracam 2. bit
  Bits tempBit2;
  tempBit2.bitSize = bit2 -> bitSize;
  for(int i = bit2 -> bitSize - 1; i >= 0; i--)
    tempBit2.bit[bit2 -> bitSize - i - 1] = bit2 -> bit[i];

  //std::cout << "------------------\ntempBit1: \n";
  //print(&tempBit1);
  //std::cout << "------------------\ntempBit2: \n";
  //print(&tempBit2);

  for(int i = 0; i < whichIsBigger; i++)
  {
    temporarySum = (tempBit1.bit[i] + tempBit2.bit[i] + flag);
    sum.bit[i] = temporarySum % 2;
    if((tempBit1.bit[i] == 1 && tempBit2.bit[i] == 1 && flag == 0)
      || (tempBit1.bit[i] == 0 && tempBit2.bit[i] == 1 && flag == 1)
      || (tempBit1.bit[i] == 1 && tempBit2.bit[i] == 0 && flag == 1)
      || (tempBit1.bit[i] == 1 && tempBit2.bit[i] == 1 && flag == 1))
            flag = 1;
          else flag = 0; 

  /*std::cout << "i: " << i << std::endl;
    std::cout << "tempBit1.bit[i]: " << tempBit1.bit[i] << std::endl;
    std::cout << "tempBit2.bit[i]: " << tempBit2.bit[i] << std::endl;
    std::cout << "sum.bit[i]: " << sum.bit[i] << std::endl;
    std::cout << "flag: " << flag << std::endl;
    std::cout << "\n";
    */
  }
  //print(&sum);

  //std::cout << "********** END ************" << std::endl;
  //odwracam sume
  Bits finalSum;
  finalSum.bitSize = sum.bitSize;
  for(int i = sum.bitSize - 1; i >= 0; i--)
    finalSum.bit[sum.bitSize - i - 1] = sum.bit[i];
  return finalSum;
}


void bit_and(Bits *bit1, Bits *mask)
{
  int size;
  if(bit1 -> bitSize > mask -> bitSize) size = bit1 -> bitSize;
  else size = mask -> bitSize;

  for(int i = 0; i < size; i++)
  {
    if(mask -> bit[i] ==  bit1 -> bit[i])
      bit1 -> bit[i] = 1;
    else bit1 -> bit[i] = 0;
  }
}

void bit_xor(Bits *bit1, Bits *mask)
{
  int size;
  if(bit1 -> bitSize > mask -> bitSize) size = bit1 -> bitSize;
  else size = mask -> bitSize;

  for(int i = 0; i < size; i++)
  {
    if(mask -> bit[i] ==  bit1 -> bit[i])
      bit1 -> bit[i] = 0;
    else bit1 -> bit[i] = 1;
  }
}

int potega(int a, int n)
{ 
  int output = 1;
  for(int i = 0; i < n; i++)
  {
    output *= a;
  }
  return output;
}

int to_decimal(const Bits *bit)
{
  int output = 0;
  for (int i = 0; i < bit -> bitSize; i++)
    if(bit -> bit[bit -> bitSize - (i + 1)] == 1)
      output += pow(2, (i));   
  return output;
}