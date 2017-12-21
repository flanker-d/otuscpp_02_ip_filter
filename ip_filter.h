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
void filter_by_first_byte_and_output(const ip_pool_t &ip_pool, const int &first);
void filter_by_first_and_second_bytes_and_output(const ip_pool_t &ip_pool, const int &first, const int &second);
void filter_by_any_byte_and_output(const ip_pool_t &ip_pool, const int &any);
