#include <cstdlib> // EXIT_SUCCESS
#include <iostream> // std::cout

#include "core.hpp"
#include "util.hpp"

int main() {
  std::cout << "Boo!" << std::endl;
  int x = core();
  int y = util();

  std::cout << "core: " << x << ", util: " << y << std::endl;
  return EXIT_SUCCESS;
}
