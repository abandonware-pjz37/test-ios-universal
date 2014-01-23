cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0025 OLD) # Clang, AppleClang
project(Boo)

find_package(Foo CONFIG REQUIRED)

add_executable(boo boo.cpp)
target_link_libraries(boo Foo::core Foo::util)

if(CMAKE_XCODE_EFFECTIVE_PLATFORMS)
  # iOS build
  set_target_properties(
      boo
      PROPERTIES
      MACOSX_BUNDLE YES
      MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.iOSFixTest"
      XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer"
  )
endif()

enable_testing()
add_test(boo boo)
