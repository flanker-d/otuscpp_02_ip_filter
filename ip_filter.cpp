#include "ip_filter.h"
#include "version.h"

#include <algorithm>

int version()
{
  return PROJECT_VERSION_PATCH;
}

std::vector<std::string> split(const std::string &str, char d)
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

void print_ip_pool(ip_pool_t &ip_pool)
{
  for(auto ip : ip_pool)
  {
    bool is_first_octet = true;
    for(auto ip_part : ip)
    {
      if(is_first_octet)
        is_first_octet = false;
      else
        std::cout << ".";

      std::cout << ip_part;
    }
    std::cout << std::endl;
  }
}

void reverse_lexicographically_sort(ip_pool_t &ip_pool)
{
  std::sort(ip_pool.begin(), ip_pool.end(), [](auto a, auto b){
    if(std::stoi(a[0]) > std::stoi(b[0]))
      return true;
    else if(std::stoi(a[0]) == std::stoi(b[0]))
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
