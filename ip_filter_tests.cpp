#define BOOST_TEST_MODULE ip_filter_tests

#include "ip_filter.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ip_filter_tests)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
  BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test_print_ip)
{
  BOOST_CHECK_EQUAL(get_ip_string(std::make_tuple("1","2","3","4")), std::string("1.2.3.4"));
}

BOOST_AUTO_TEST_CASE(test_vector_to_tuple)
{
  std::vector<std::string> vect = {"1", "2", "3", "4"};
  ip_t tup = std::make_tuple("1", "2", "3", "4");
  ip_t vect_to_tup = ip_vector_to_tuple(vect);


  BOOST_CHECK_EQUAL(get_ip_string(tup), get_ip_string(vect_to_tup));
}

BOOST_AUTO_TEST_SUITE_END()
