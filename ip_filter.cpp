#include "ip_filter.h"
#include "version.h"

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
  std::stringstream ss;
  ss << std::get<0>(ip) << "." << std::get<1>(ip) << "." << std::get<2>(ip) << "." << std::get<3>(ip);
  return ss.str();
}

void print_ip_pool(ip_pool_t& ip_pool)
{
  for(auto ip : ip_pool)
    std::cout << get_ip_string(ip) << std::endl;
}

void reverse_lexicographically_sort(ip_pool_t& ip_pool)
{
  std::sort(ip_pool.begin(), ip_pool.end(), [](auto& a, auto& b){
    return a > b;
  });
}

void filter_by_first_byte_and_output(const ip_pool_t& ip_pool, const int& first)
{
  std::count_if(ip_pool.begin(), ip_pool.end(), [first](const auto& a){
    bool ret = (std::get<0>(a) == first);
    if(ret)
      std::cout << get_ip_string(a) << std::endl;
    return ret;
  });
}

void filter_by_first_and_second_bytes_and_output(const ip_pool_t& ip_pool, const int &first, const int &second)
{
  std::count_if(ip_pool.begin(), ip_pool.end(), [first, second](const auto& a){
    bool ret = ((std::get<0>(a) == first) && (std::get<1>(a) == second));
    if(ret)
      std::cout << get_ip_string(a) << std::endl;
    return ret;
  });
}

void filter_by_any_byte_and_output(const ip_pool_t& ip_pool, const int& any)
{
  std::count_if(ip_pool.begin(), ip_pool.end(), [any](const auto& a) {
    bool ret = ((std::get<0>(a) == any) || (std::get<1>(a) == any) || (std::get<2>(a) == any) || (std::get<3>(a) == any));
    if(ret)
      std::cout << get_ip_string(a) << std::endl;
    return ret;
  });
}

