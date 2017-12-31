#include "ip_filter.h"
#include "version.h"
#include "make_ip_string.h"

#include <algorithm>
#include <sstream>

int version()
{
  return PROJECT_VERSION_PATCH;
}

std::vector<std::string> split(const std::string& str, char d)
{
  std::vector<std::string> r;

  auto start = 0;
  auto stop = str.find_first_of(d);
  while(stop != std::string::npos)
  {
    r.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(d, start);
  }

  r.push_back(str.substr(start));

  return r;
}

ip_t make_ip_from_str_vect(std::vector<std::string> v)
{
  return std::make_tuple(std::stoi(v[0]), std::stoi(v[1]), std::stoi(v[2]), std::stoi(v[3]));
}

std::string get_ip_string(const ip_t& ip)
{
  return make_ip_string(ip);
}

void print_ip_pool(ip_pool_t& ip_pool)
{
  for(auto ip : ip_pool)
    std::cout << get_ip_string(ip) << std::endl;
}

void reverse_lexicographically_sort(ip_pool_t& ip_pool)
{
  std::sort(ip_pool.begin(), ip_pool.end(), std::greater<ip_t>());
}

void filter_by_any_byte_and_output(const ip_pool_t& ip_pool, const int& any)
{
  for(const auto& ip : ip_pool)
  {
    bool ret = ((std::get<0>(ip) == any) || (std::get<1>(ip) == any) || (std::get<2>(ip) == any) || (std::get<3>(ip) == any));
    if(ret)
      std::cout << get_ip_string(ip) << std::endl;
  }
}

