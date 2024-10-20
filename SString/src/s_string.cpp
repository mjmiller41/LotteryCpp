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
  stringstream stream(m_str);
  string line;
  while (getline(stream, line, delimiter)) {
    SString s_line(line);
    s_line.strip();
    result.push_back(s_line);
  }
  return result;
}

void SString::replace(const std::string& old_char,
                      const std::string& new_char) {
  std::size_t index = m_str.find(old_char);
  std::size_t count = 1;
  while (index != m_str.npos) {
    m_str.replace(index, count, new_char);
    index = m_str.find(old_char);
  }
  strip_inv();
}

size_t SString::last_i() const { return m_str.size() - 1; }

void SString::l_strip() {
  std::size_t index = 0;
  std::size_t count = 1;
  char char_ = m_str[index];
  while (isspace(char_)) {
    m_str.erase(index, count);
    char_ = m_str[index];
  }
}

void SString::r_strip() {
  char char_ = m_str[last_i()];
  while (isspace(char_)) {
    m_str.erase(last_i());
    char_ = m_str[last_i()];
  }
}

void SString::clean() {
  replace("[");
  replace("]");
  replace("\"");
}

void SString::strip_inv() {
  auto f = [](unsigned char x) { return isspace(x) && x != ' '; };
  string::iterator i = remove_if(m_str.begin(), m_str.end(), f);
  m_str.erase(i, m_str.end());
}

void SString::strip() {
  l_strip();
  r_strip();
  clean();
  strip_inv();
}

int test() {
  SString str{"Hello, World!, \"This is a test\""};
  str.replace("\"");
  vector<SString> list = str.split();

  for (SString item : list) {
    cout << item.data() << '\n';
    assert(item.data() == "Hello" || item.data() == "World!" ||
           item.data() == "This is a test");
  }

  return 0;
}

#endif
