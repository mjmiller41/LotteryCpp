#ifndef STRING
#define STRING

#include "s_string.h"

using namespace std;

SString::SString() {}
SString::SString(const string str) : m_str{str} {}

string SString::data() const { return m_str; }
void SString::setData(const string str) { m_str = str; }

vector<SString> SString::split(const char& delimiter) {
  vector<SString> result;
  stringstream ss(m_str);
  string line;
  while (getline(ss, line, delimiter)) {
    SString s_line{line};
    s_line.strip();
    result.push_back(s_line);
  }
  return result;
}

void SString::replace(const char& old_char, const char& new_char) {
  string new_str;
  for (size_t i = 0; i < m_str.size(); i++) {
    if (m_str[i] != old_char) {
      new_str.push_back(m_str[i]);
    } else if (new_char != '\0') {
      new_str.push_back(new_char);
    }
  }
  m_str = new_str;
  strip_inv();
}

size_t SString::last_i() const { return m_str.size() - 1; }

void SString::l_strip() {
  char c = m_str[0];
  while (isspace(c)) {
    m_str.erase(0, 1);
    c = m_str[0];
  }
}

void SString::r_strip() {
  char c = m_str[last_i()];
  while (isspace(c)) {
    m_str.erase(last_i());
    c = m_str[last_i()];
  }
}

void SString::strip_inv() {
  function f = [](unsigned char x) { return isspace(x) && x != ' '; };
  string::iterator i = remove_if(m_str.begin(), m_str.end(), f);
  m_str.erase(i, m_str.end());
}

void SString::strip() {
  l_strip();
  r_strip();
  strip_inv();
}

int test() {
  SString str{"Hello, World!, \"This is a test\""};
  str.replace('"');
  vector<SString> list = str.split();

  for (SString item : list) {
    cout << item.data() << '\n';
    assert(item.data() == "Hello" || item.data() == "World!" ||
           item.data() == "This is a test");
  }

  return 0;
}

#endif
