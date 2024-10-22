#ifndef UTILS
#define UTILS

#include "utils.h"

namespace Utils {

void replace(std::string &str, std::string old_char, std::string new_char) {
  size_t pos = str.find(old_char);
  size_t count = 1;
  while (pos != str.npos) {
    str.replace(pos, count, new_char);
    pos = str.find(old_char);
  }
}

std::vector<std::string> split(const std::string &str, const char &delimiter) {
  std::vector<std::string> result;
  std::stringstream stream(str);
  std::string line;
  while (getline(stream, line, delimiter)) {
    std::string s_line(line);
    result.push_back(s_line);
  }
  return result;
}

void zFill(std::string &str, size_t places) {
  while (str.size() < places) {
    str.insert(str.begin(), '0');
  }
}

}  // namespace Utils

#endif
