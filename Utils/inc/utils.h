#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace Utils {

void replace(std::string &str, const std::string old_char,
             const std::string new_char);

std::vector<std::string> split(const std::string &str, const char &delimiter);

void zFill(std::string &str, size_t places);

}  // namespace Utils

#endif
