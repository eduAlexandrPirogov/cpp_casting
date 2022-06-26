#include <iostream>
#include <fstream>

struct test
{
   int a;
   char b;
   float c;
};

int main()
{
   test* t = new test();
   t->a = 10;
   t->b = 'A';
   t->c = 0.2f;

   std::cout << sizeof(*t) << " ref: " << t << '\n';
   auto tt = reinterpret_cast<test*>(t);
   auto bin = reinterpret_cast<char*>(t);
   
   std::cout << tt << " ref: " << tt << '\n';
   std::cout << bin << " ref: " << bin << '\n';
    std::cout << reinterpret_cast<char*>(t) << " ref: " << '\n';

   std::cout << reinterpret_cast<test*>(bin) << '\n';

};
