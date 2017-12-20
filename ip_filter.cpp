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

  std::string::size_type start = 0;
  std::string::size_type stop = str.find_first_of(d);
  while(stop != std::string::npos)
  {
    r.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(d, start);
  }

  r.push_back(str.substr(start));

  return r;
}

ip_t ip_vector_to_tuple(const std::vector<std::string>& v)
{
  return std::make_tuple(v[0], v[1], v[2], v[3]);
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
  {
    std::cout << get_ip_string(ip) << std::endl;
  }
}

void reverse_lexicographically_sort(ip_pool_t& ip_pool)
{
  std::sort(ip_pool.begin(), ip_pool.end(), [](auto a, auto b){
    if(std::get<0>(a) > std::get<0>(b))
      return true;
    else if(std::get<0>(a) == std::get<0>(b))
    {
      if(std::get<1>(a) > std::get<1>(b))
        return true;
      else if(std::get<1>(a) == std::get<1>(b))
      {
        if(std::get<2>(a) > std::get<2>(b))
          return true;
        else if(std::get<2>(a) == std::get<2>(b))
        {
          if(std::get<3>(a) > std::get<3>(b))
            return true;
          else
            return false;
        }
        return false;
      }
      else
        return false;
    }
    else
      return false;
  });
}

void filter_by_first_byte_and_output(const ip_pool_t& ip_pool, const std::string& first)
{
  std::count_if(ip_pool.begin(), ip_pool.end(), [first](auto a){
    if(std::get<0>(a) == first)
    {
      std::cout << get_ip_string(a) << std::endl;
      return true;
    }
    else
      return false;
  });
}

void filter_by_first_and_second_bytes_and_output(const ip_pool_t& ip_pool, const std::string& first, const std::string& second)
{
  std::count_if(ip_pool.begin(), ip_pool.end(), [first, second](auto a){
    if((std::get<0>(a) == first) && (std::get<1>(a) == second))
    {
      std::cout << get_ip_string(a) << std::endl;
      return true;
    }
    else
      return false;
  });
}

void filter_by_any_byte_and_output(const ip_pool_t& ip_pool, const std::string& any)
{
  std::count_if(ip_pool.begin(), ip_pool.end(), [any](auto a){
    if((std::get<0>(a) == any) || (std::get<1>(a) == any) || (std::get<2>(a) == any) || (std::get<3>(a) == any))
    {
      std::cout << get_ip_string(a) << std::endl;
      return true;
    }
    else
      return false;
  });
}
