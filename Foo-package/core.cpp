#include <iostream>

int core() {
  std::cout << "[core]: ";
#if (CORE_DEBUG)
  std::cout << "Debug";
#else
  std::cout << "Release";
#endif
  std::cout << std::endl;
  return 0x42;
}
