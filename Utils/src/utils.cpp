#ifndef UTILS_UTILS_CPP_
#define UTILS_UTILS_CPP_

#include "utils.h"

namespace Utils {

void replace(std::string &str, const char old_char, const char *new_char) {
  size_t pos = str.find(old_char);
  size_t count = 1;
  while (pos != str.npos) {
    str.replace(pos, count, new_char);
    pos = str.find(old_char);
  }
}

std::vector<std::string> split(const std::string &str, char delimiter) {
  std::vector<std::string> result;
  int startIndex = 0, endIndex = 0;
  for (int i = 0; i <= str.size(); i++) {
    // If we reached the end of the word or the end of the input.
    if (str[i] == delimiter || i == str.size()) {
      endIndex = i;
      std::string temp;
      temp.append(str, startIndex, endIndex - startIndex);
      result.push_back(temp);
      startIndex = endIndex + 1;
    }
  }
  return result;
}

void zFill(std::string &str, const size_t digits) {
  while (str.size() < digits) {
    str.insert(str.begin(), '0');
  }
}

size_t find(const std::string &item, const std::vector<std::string> &items) {
  auto p = [item](const std::string &item_) { return item == item_; };
  auto it = std::find_if(items.begin(), items.end(), p);
  auto diff = it - items.begin();
  // Verification of non-negative result before casting from unsigned long
  if (diff >= 0) {
    return static_cast<size_t>(diff);
  } else {
    throw "Error: Conversion from unsigned long to long not possible.";
  }
};

}  // namespace Utils

#endif  // UTILS_UTILS_CPP_
