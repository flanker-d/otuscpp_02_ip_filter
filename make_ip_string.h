#pragma once

#include <tuple>
#include <sstream>

template<std::size_t...> struct seq{};

template<std::size_t N, std::size_t... Is>
struct gen_seq : gen_seq<N-1, N-1, Is...>{};

template<std::size_t... Is>
struct gen_seq<0, Is...> : seq<Is...>{};

template<typename Ch, typename Tr, typename Tuple, std::size_t... Is>
void print_tuple(std::basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>)
{
  using swallow = int[];
  (void)swallow{0, (void(os << (Is == 0? "" : ".") << std::get<Is>(t)), 0)...};
}

template<typename Ch, typename Tr, typename... Args>
auto operator<<(std::basic_stringstream<Ch, Tr>& ss, std::tuple<Args...> const& t) -> std::basic_stringstream<Ch, Tr>&
{
  print_tuple(ss, t, gen_seq<sizeof...(Args)>());
  return ss;
}

template<typename... Args>
std::string make_ip_string(std::tuple<Args...> const& t)
{
  std::stringstream ss;
  ss << t;
  return ss.str();
}
