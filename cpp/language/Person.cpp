#include "Person.h"

std::ostream& operator<<(std::ostream& os, Person const& person) {
  return os << person.getName() ;
}