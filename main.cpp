//#define LOCAL_TEST 1

#ifdef LOCAL_TEST
  #include <sstream>
#endif

#include "ip_filter.h"

int main(int argc, char** argv)
{
  try
  {
#ifdef LOCAL_TEST
    std::stringstream test_stream;

    test_stream
    << "113.162.145.156\t111\t0\n"
    << "157.39.22.224\t5\t6\n"
    << "79.180.73.190\t2\t1\n"
    << "179.210.145.4\t22\t0\n"
    << "219.102.120.135\t486\t0\n"
    << "67.232.81.208\t1\t0\n"
    << "85.254.10.197\t0\t7\n"
    << "23.240.215.189\t6\t0\n"
    << "1.29.168.152\t17\t0\n"
    << "185.69.186.168\t1\t3\n"
    << "110.152.103.161\t0\t1\n"
    << "185.182.81.131\t1\t1\n"
    << "68.45.152.8\t2\t0\n"
    << "114.221.179.117\t0\t1\n"
    << "185.89.100.249\t752\t0\n"
    << "46.70.113.73\t1\t0\n"
    << "188.68.0.38\t1\t0\n"
    << "119.42.115.97\t11\t0\n"
    << "194.106.108.214\t0\t3\n"
    << "24.210.239.177\t1\t0";
#endif
    ip_pool_t ip_pool;

#ifdef LOCAL_TEST
    for(std::string line; std::getline(test_stream, line);)
#else
    for(std::string line; std::getline(std::cin, line);)
#endif
    {
      std::vector<std::string> v = split(line, '\t');
      ip_pool.push_back(make_ip_from_str_vect(split(v.at(0), '.')));
    }

    // TODO reverse lexicographically sort
    reverse_lexicographically_sort(ip_pool);
    print_ip_pool(ip_pool);


    // 222.173.235.246
    // 222.130.177.64
    // 222.82.198.61
    // ...
    // 1.70.44.170
    // 1.29.168.152
    // 1.1.234.8

    // TODO filter by first byte and output
    // ip = filter(1)
    filter_by_first_byte_and_output(ip_pool, 1);

    // 1.231.69.33
    // 1.87.203.225
    // 1.70.44.170
    // 1.29.168.152
    // 1.1.234.8

    // TODO filter by first and second bytes and output
    // ip = filter(46, 70)
    filter_by_first_and_second_bytes_and_output(ip_pool, 46, 70);

    // 46.70.225.39
    // 46.70.147.26
    // 46.70.113.73
    // 46.70.29.76

    // TODO filter by any byte and output
    // ip = filter_any(46)
    filter_by_any_byte_and_output(ip_pool, 46);

    // 186.204.34.46
    // 186.46.222.194
    // 185.46.87.231
    // 185.46.86.132
    // 185.46.86.131
    // 185.46.86.131
    // 185.46.86.22
    // 185.46.85.204
    // 185.46.85.78
    // 68.46.218.208
    // 46.251.197.23
    // 46.223.254.56
    // 46.223.254.56
    // 46.182.19.219
    // 46.161.63.66
    // 46.161.61.51
    // 46.161.60.92
    // 46.161.60.35
    // 46.161.58.202
    // 46.161.56.241
    // 46.161.56.203
    // 46.161.56.174
    // 46.161.56.106
    // 46.161.56.106
    // 46.101.163.119
    // 46.101.127.145
    // 46.70.225.39
    // 46.70.147.26
    // 46.70.113.73
    // 46.70.29.76
    // 46.55.46.98
    // 46.49.43.85
    // 39.46.86.85
    // 5.189.203.46
  }
  catch(const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
