#include <iostream>

class Base
{
   public:
      Base(int aa, char cc) : a(aa), c(cc) {};
      int a;
      char c;

      virtual void func() { std::cout << "Some function base\n";};
};

class Derived : public Base
{
   public:
      Derived(int aa, char cc, float ff) : Base(aa, cc), f(ff) {};
      float f;

      virtual void func() { std::cout << "Some function derived\n";};
      void derived_func() { std::cout << "External derived function\n";};
};


class AnotherDerived : public Base
{
  public:
      AnotherDerived(int aa, char cc, float ff) : Base(aa, cc), f(ff) {};
      float f;

      virtual void func() { std::cout << "Some function derived\n";};
      void other_func() { std::cout << "External derived function\n";};

};


int main()
{
   Base* der = new Derived{1, 'A', 0.2f};
   Base* other = new AnotherDerived{1, 'B', 0.3f};
  
   
   Derived* d = dynamic_cast<Derived*>(der);

   //Danger!
   //Derived* d1 = dynamic_cast<Derived*>(other);

   der->func();
   d->func();

   //Error occuers
   //d1->func();

   //Dangerous
   d->derived_func();
};
