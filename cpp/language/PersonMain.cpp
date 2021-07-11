#include<iostream>
#include "Person.h"

int main() {
  // Uses Default Constructor
  Person p;
  std::cout << p << std::endl;

  Person p1("Swagat");
  std::cout << p1 << std::endl;

  // Uses Copy Constructor
  Person p2(p1);
  Person p3 = p1;
  std::cout << p2 << std::endl;
  std::cout << p3 << std::endl;

  // Uses Copy Assignment Operator
  Person p4;
  p4 = p1;
  std::cout << p3 << std::endl;

  return 0;
}
