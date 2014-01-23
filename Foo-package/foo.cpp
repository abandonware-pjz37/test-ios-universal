#include <iostream> // std::cout
#include <cstdlib> // EXIT_SUCCESS
#include "core.hpp"
#include "util.hpp"

int main() {
  int x = util();
  int y = core();

  std::cout << "util: " << x << ", core: " << y << std::endl;
  return EXIT_SUCCESS;
}
