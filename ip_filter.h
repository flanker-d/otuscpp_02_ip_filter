#pragma once

#include <vector>
#include <string>
#include <iostream>

using ip_pool_t = std::vector<std::vector<std::string>>;

int version();
std::vector<std::string> split(const std::string &str, char d);
void print_ip_pool(ip_pool_t &ip_pool);
void reverse_lexicographically_sort(ip_pool_t &ip_pool);
