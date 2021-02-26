#pragma once

//rozmiar tablicy bitow
#define B_SIZE 32 

//struktura reprezentujaca tablice typu int (zawiera pojedyncze bity) 
//oraz informacje o dlugosci bitu
typedef struct bits {
  int bit[B_SIZE] = {0};
  int bitSize; //liczba zajetych bitow
} Bits;

//procedura tworzaca bit na podstawie tablicy int
void set(Bits *bit, int *data, int size);

//procedura wypisujaca bit typu struct bits
void print(const Bits *bit);

//funkcja dodajaca bity
Bits add_up(const Bits *bit1, const Bits *bit2);

//druga proba funkcji dodajacej bity
Bits add_upV2(const Bits *bit1, const Bits *bit2);

//procedura wykonujaca operacje logiczna AND na bicie
void bit_and(Bits *bit1, Bits *mask);

//procedura wykonujaca operacje logiczna XOR na bicie
void bit_xor(Bits *bit1, Bits *mask);

//funkcja konwertujaca liczbe binarna (w typie struct bits)
//na dziesietna (w typie int)
int to_decimal(const Bits *bit);

//funckja liczaca potegowanie a^n
int potega(int a, int n);