cmake_minimum_required(VERSION 3.2)

project(ip_filter VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(ip_filter main.cpp)

add_executable(ip_filter_tests ip_filter_tests.cpp)

add_library(ipfilter ip_filter.cpp)

add_executable(make_ip_string_tests make_ip_string_tests.cpp)

add_library(makeipstring make_ip_string.cpp)


set_target_properties(ip_filter ipfilter ip_filter_tests makeipstring make_ip_string_tests PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(ip_filter_tests PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(ip_filter
  ipfilter
  makeipstring
  pthread
)

target_link_libraries(ip_filter_tests
  ${Boost_LIBRARIES}
  ipfilter
)

set_target_properties(make_ip_string_tests PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(make_ip_string_tests
  ${Boost_LIBRARIES}
  makeipstring
)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT artyom.sorokoumov@gmail.com)

include(CPack)

enable_testing()

add_test(ip_filter_tests ip_filter_tests)
add_test(make_ip_string_tests make_ip_string_tests)
