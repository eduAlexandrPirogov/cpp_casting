# Casting in C++

Casting is instruction that converts between types using a combination of explicit and implicit conversions. 

In C++ exists four types of casting

1. Static casting
2. Const casting
3. Dynamic casting
4. Reinterpret casting

## Static casting

**static_cast<new-type>(expression)** -- returns a value of type `new-type`. 

For example we can conver char to int:

```cpp
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
```

**Only the following conversions can be done with static_cast, except when such conversions would cast away constness or volatility.** [cppref static_cast](https://en.cppreference.com/w/cpp/language/static_cast#:~:text=Only%20the%20following,or%20volatility.)


## Const casting

**const_cast<new-type>(expression)** -- converts between types with different cv-qualification. Returns a value of type new-type

For example we want convert const expression to non-const:

```cpp
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
```

Be carefull! Modifying casted expression throw an error!

**Only the following conversions can be done with const_cast. In particular, only const_cast may be used to cast away (remove) constness or volatility.** [cppref const_cast](https://en.cppreference.com/w/cpp/language/const_cast#:~:text=Only%20the%20following,constness%20or%20volatility.)


## Dynamic casting

Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.

For example we want to get child instance from base class pointer:

```cpp
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

   //Error occuers because we've get by dynamic cast nullptr
   //d1->func();

   //Dangerous
   d->derived_func();
};
```

Better avoid using dynamic_cast (as says experienced programmers).

**Only the following conversions can be done with dynamic_cast, except when such conversions would cast away constness or volatility.** [cppref dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast#:~:text=Only%20the%20following,or%20volatility.)

## Reinterpret casting TDB...
