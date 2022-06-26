#include <iostream>

void print(char* message)
{
   std::cout << message << '\n';
};

void modify(char* message)
{
   message[0] = 'A';
   std::cout << message << '\n';
};

int main()
{
   const char* greeting = "Hello, world!";
   
   //print(greeting); Error occurs!
   
   char* greet = const_cast<char*>(greeting);
   std::cout << &greeting << '\n';
   std::cout << &greet << '\n';
   print(const_cast<char*>(greeting));
   
   //modify(const_cast<char*>(greeting)); // compiles but occurs run-time error!
   //modify(greet); //comiples fune but occurs run-time error
   return 0;
};
