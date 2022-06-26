#include <iostream>

int main()
{
   //C-style
   int a = 'A';
   std::cout << "Before cast int a = " << a << '\n';
   std::cout << "After cast  " << (char)a <<'\n';


   //Static_cast
   int b = 'B';
   char b1 = static_cast<char>(b);
   std::cout << "Before cast int b = " << b << '\n';
   std::cout << "After cast  = " << b1 <<'\n';
};
