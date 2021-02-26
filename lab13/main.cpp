#include "MyString.h"
#include <iostream>

using namespace mystring;

int main() 
{
    std::cout << "Rozpoczynamy zadanie 13: MyString i operatory!\n" << std::endl;
    
    MyString s;

	MyString s0("Sesja juz niedlugo.");  
	MyString s1("Sesja juz niedlugo");
	const MyString s2(s0);  

	s0.print("S0: "); s1.print("S1: "); s2.print("S2: "); 
	
  
  std::cout << "\n*** Porownywanie napisow ***" << std::endl;
	std::cout << "Napisy s0 i s2 " << (s0 == s2 ? "sa identyczne" :"nie sa identyczne") << std::endl;
	std::cout << "Napisy s2 i s1 " << (s2 == s1 ? "sa identyczne" :"nie sa identyczne") << std::endl;
	std::cout << "Napisy s2 i \"Sesja juz niedlugo.\" " 
            << (s2 == "Sesja juz niedlugo." ? "sa identyczne" :"nie sa identyczne") << std::endl;
	
 
 
	std::cout << "\n*** Dodawanie i przypisywanie napisow ***" <<  std::endl;

	std::cout << "S2: " << static_cast<char*>(s2) << std::endl; //= s2.print("S2: :");
	

	{
		std::cout << "poczatek bloku\n";
		s1 = "Warto wreszcie przylozyc sie do nauki!!!"; //
		std::cout << "S1: " << s1 << std::endl;
		std::cout << "koniec bloku\n";
	}
	MyString s3 = s2 + " Tu i teraz..."; //
	s3.print("S3: " );
	MyString s4 = s2 + ".. " + s1 + "\n\t" + s3 + /*'!'*/ "!"; // uwaga na typ char
	s4.print("S4: " );
	
 
	std::cout << "\n*** Powielanie napisow ***" << std::endl;
    MyString s5 = 2 * String(":-)");
    s5.print("S5: ");
    MyString s6 = 4 * s5 + ":-D ";
	  s6.print("S6: " );   

	MyString const s7 = std::move(s1);
    std::cout << "S7: "<< s7 << std::endl; 
    s1.print("S1: ");
 
}

/* // OUTPUT:
Rozpoczynamy zadanie 13: MyString i operatory!

S0: Sesja juz niedlugo.
S1: Sesja juz niedlugo
S2: Sesja juz niedlugo.

*** Porownywanie napisow ***
Napisy s0 i s2 sa identyczne
Napisy s2 i s1 nie sa identyczne
Napisy s2 i "Sesja juz niedlugo." sa identyczne

*** Dodawanie i przypisywanie napisow ***
S2: Sesja juz niedlugo.
S1: Warto wreszcie przylozyc sie do nauki!!!
S3: Sesja juz niedlugo. Tu i teraz...
S4: Sesja juz niedlugo... Warto wreszcie przylozyc sie do nauki!!!
    Sesja juz niedlugo. Tu i teraz...!

*** Powielanie napisow ***
S5: :-):-)
S6: :-):-):-):-):-):-):-):-):-D 
S7: Warto wreszcie przylozyc sie do nauki!!!
S1: 
*/
