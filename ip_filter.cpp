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

std::string get_ip_string(const ip_t& ip)
{
  std::stringstream ss;
  ss << ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3];
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
    if(std::stoi(a[0]) > std::stoi(b[0]))
      return true;
    else if(a[0] == b[0])
    {
      if(std::stoi(a[1]) > std::stoi(b[1]))
        return true;
      else if(std::stoi(a[1]) == std::stoi(b[1]))
      {
        if(std::stoi(a[2]) > std::stoi(b[2]))
          return true;
        else if(std::stoi(a[2]) == std::stoi(b[2]))
        {
          if(std::stoi(a[3]) > std::stoi(b[3]))
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
    if(a[0] == first)
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
    if((a[0] == first) && (a[1] == second))
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
    if((a[0] == any) || (a[1] == any) || (a[2] == any) || (a[3] == any))
    {
      std::cout << get_ip_string(a) << std::endl;
      return true;
    }
    else
      return false;
  });
}
