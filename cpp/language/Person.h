/**
 * Implementation of methods in Person.cpp
 */
#include<iostream>

class Person {
  std::string name;
public:
  // Default Constructor
  Person(){
    this->name = "__NOT_INITIALIZED__";
  }

  // Simple Constructor
  Person(std::string s):name(s){}

  // Copy Constructor
  Person(const Person& p){
    this->name = p.getName();
  }

  // Copy Assignment Operator
  Person& operator=(const Person& p) {
    this->name = p.getName();
    return *this;
  }

  ~Person() {
    std::cout << "Destroying Person object with name : " << this->name << std::endl;
  }

  std::string getName() const {
    return this->name;
  }
};

/**
 * Overloading the << operator to enable output of type Person.
 */
std::ostream& operator<<(std::ostream& os, Person const& person);