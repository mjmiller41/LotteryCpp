#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <iostream>
#include <map>
#include <vector>

#include "data_table.h"
#include "s_string.h"

class DataTable {
 public:
  DataTable(map<std::string, SString>& data);

  std::vector<std::vector<SString>> table();
  std::vector<SString> headers();
  std::vector<SString> types();
  std::vector<SString> index();
  void print();

 private:
  std::vector<std::vector<SString>> m_table;
  std::vector<SString> m_headers;
  std::vector<SString> m_types;
  std::vector<SString> m_index;

  void create_table(SString& str);
  void set_headers(SString& str);
  void set_types(SString& str);
};
#endif
