add_library(util util.cpp)

target_include_directories(
    util
    PUBLIC
    $<INSTALL_INTERFACE:include>
)

install(TARGETS util DESTINATION lib EXPORT FooTargets)
install(FILES util.hpp DESTINATION include)
