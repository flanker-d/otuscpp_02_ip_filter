#define BOOST_TEST_MODULE make_ip_string_tests

#include "ip_filter.h"
#include "make_ip_string.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(make_ip_string_tests)

BOOST_AUTO_TEST_CASE(test_make_ip_string)
{
  BOOST_CHECK_EQUAL(make_ip_string(ip_t{1, 2, 3, 4}), std::string("1.2.3.4"));
}

BOOST_AUTO_TEST_SUITE_END()
