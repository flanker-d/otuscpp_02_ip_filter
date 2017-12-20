#pragma once

#include <vector>
#include <string>
#include <tuple>
#include <iostream>

using ip_t = std::tuple<std::string, std::string, std::string, std::string>;
using ip_pool_t = std::vector<ip_t>;

int version();
std::vector<std::string> split(const std::string &str, char d);
ip_t ip_vector_to_tuple(const std::vector<std::string> &v);
std::string get_ip_string(const ip_t& ip);
void print_ip_pool(ip_pool_t &ip_pool);
void reverse_lexicographically_sort(ip_pool_t &ip_pool);
void filter_by_first_byte_and_output(const ip_pool_t &ip_pool, const std::string &first);
void filter_by_first_and_second_bytes_and_output(const ip_pool_t &ip_pool, const std::string &first, const std::string &second);
void filter_by_any_byte_and_output(const ip_pool_t &ip_pool, const std::string &any);
