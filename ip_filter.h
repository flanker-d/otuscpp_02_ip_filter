#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>

using ip_t = std::tuple<int, int, int, int>;
using ip_pool_t = std::vector<ip_t>;

int version();
std::vector<std::string> split(const std::string &str, char d);
ip_t make_ip_from_str_vect(std::vector<std::string> b);
std::string get_ip_string(const ip_t& ip);
void print_ip_pool(ip_pool_t &ip_pool);
void reverse_lexicographically_sort(ip_pool_t &ip_pool);

template<typename T>
bool iterate(T *)
{
  return true;
}

template<typename T, typename... Args>
bool iterate(T *octet, T octet_to_cmp, Args... args)
{
  if(*octet == octet_to_cmp)
    return iterate(++octet, args...); // это не опасно?)
  else
    return false;
}

template<typename... Args>
void filter_by_octets_and_output(const ip_pool_t &ip_pool, int first, Args ...args)
{
  std::array<int, 4> octets_array;
  for(const ip_t& ip : ip_pool)
  {
    std::tie(octets_array[0], octets_array[1], octets_array[2], octets_array[3]) = ip;
    bool ret = iterate(&octets_array[0], first, args...);
    if(ret)
      std::cout << get_ip_string(ip) << std::endl;
  }
}

void filter_by_any_byte_and_output(const ip_pool_t &ip_pool, const int &any);

