#pragma once

#include <vector>
#include <string>
#include <iostream>

using ip_pool_t = std::vector<std::vector<std::string>>;

int version();
std::vector<std::string> split(const std::string &str, char d);
void print_ip_pool(ip_pool_t &ip_pool);
void reverse_lexicographically_sort(ip_pool_t &ip_pool);
void filter_by_first_byte_and_output(const ip_pool_t &ip_pool, const std::string &first);
void filter_by_first_and_second_bytes_and_output(const ip_pool_t &ip_pool, const std::string &first, const std::string &second);
void filter_by_any_byte_and_output(const ip_pool_t &ip_pool, const std::string &any);
