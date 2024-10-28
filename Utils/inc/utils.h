#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#include <algorithm>
#include <format>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

namespace Utils {

void replace(std::string &str, const char old_char, const char *new_char);
std::vector<std::string> split(const std::string &str, const char delimiter);
void zFill(std::string &str, const size_t digits);
size_t find(const std::string &item, const std::vector<std::string> &items);

}  // namespace Utils

#endif  // UTILS_UTILS_H_
