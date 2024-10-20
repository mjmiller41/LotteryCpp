#ifndef DATA_TABLE
#define DATA_TABLE

#include "data_table.h"

// PUBLIC members
DataTable::DataTable(map<std::string, SString>& data) {
  create_table(data["data"]);
  set_headers(data["fields"]);
  set_types(data["types"]);
};

std::vector<std::vector<SString>> DataTable::table() { return m_table; }
std::vector<SString> DataTable::headers() { return m_headers; }
std::vector<SString> DataTable::types() { return m_types; }
std::vector<SString> DataTable::index() { return m_index; }
void DataTable::print() {
  for (std::vector<SString> row : m_table) {
    for (size_t i = 0; i < row.size(); i++) {
      if (i == row.size() - 1) {
        std::cout << '"' << row[i].data() << "\"\n";
      } else {
        std::cout << '"' << row[i].data() << "\", ";
      }
    }
  }
}

// PRIVATE members
void DataTable::create_table(SString& str) {
  std::vector<SString> lines = str.split('\n');
  for (SString& line : lines) {
    m_table.push_back(line.split());
  }
  for (size_t i = 0; i < m_table.size(); i++) {
    for (size_t j = 0; j < m_table[i].size(); j++) {
      m_table[i][j].replace({'"'});
    }
  }
  m_table.erase(m_table.begin());
}
void DataTable::set_headers(SString& str) { m_headers = str.split(); }
void DataTable::set_types(SString& str) { m_types = str.split(); }

#endif
