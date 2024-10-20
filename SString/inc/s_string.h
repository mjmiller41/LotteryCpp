#ifndef STRING_H
#define STRING_H

#include <algorithm>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class SString {
 private:
  string m_str;

 public:
  SString();
  SString(const string str);

  string data() const;
  void setData(const string str);

  vector<SString> split(const char& delimiter = ',');
  void replace(const std::string& old_char, const std::string& new_char = "");
  size_t last_i() const;
  void l_strip();
  void r_strip();
  void clean();
  void strip_inv();
  void strip();
};

#endif
