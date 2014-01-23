cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0025 OLD) # Clang, AppleClang
project(Foo)

include(CMakePackageConfigHelpers) # configure_package_config_file

set(CMAKE_DEBUG_POSTFIX d)

add_subdirectory(util/sources)

add_library(core core.cpp)
add_executable(foo foo.cpp)
target_link_libraries(foo core util)

include_directories("./")
include_directories("./util/sources")

target_compile_definitions(core PUBLIC "CORE_DEBUG=$<CONFIG:Debug>")
target_include_directories(
    core
    PUBLIC
    $<INSTALL_INTERFACE:include>
)

set(CONFIG_DEST lib/cmake/Foo)
configure_package_config_file(
    FooConfig.cmake.in
    ${PROJECT_BINARY_DIR}/FooConfig.cmake
    INSTALL_DESTINATION ${CONFIG_DEST}
    PATH_VARS CONFIG_DEST
)

install(TARGETS core DESTINATION lib EXPORT FooTargets)

install(FILES core.hpp DESTINATION include)
install(EXPORT FooTargets NAMESPACE Foo:: DESTINATION ${CONFIG_DEST})
install(
    FILES "${PROJECT_BINARY_DIR}/FooConfig.cmake" DESTINATION ${CONFIG_DEST}
)

if(CMAKE_XCODE_EFFECTIVE_PLATFORMS)
  # iOS build
  set_target_properties(
      foo
      PROPERTIES
      MACOSX_BUNDLE YES
      MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.iOSFixTest"
      XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer"
  )
endif()
