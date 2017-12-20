cmake_minimum_required(VERSION 3.2)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(ip_filter main.cpp)

add_executable(test_version test_version.cpp)

add_library(ipfilter ip_filter.cpp)

set_target_properties(ip_filter ipfilter test_version PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(test_version PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(ip_filter
  ipfilter
  pthread
)

target_link_libraries(test_version
  ${Boost_LIBRARIES}
  ipfilter
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT artyom.sorokoumov@gmail.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
