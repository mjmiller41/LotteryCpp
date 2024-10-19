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
  void replace(const char& old_char, const char& new_char = '\0');
  size_t last_i() const;
  void strip_inv();
  void l_strip();
  void r_strip();
  void strip();
};

#endif
