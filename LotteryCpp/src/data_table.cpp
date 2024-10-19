#ifndef DATA_TABLE
#define DATA_TABLE

#include "data_table.h"

// PUBLIC members
DataTable::DataTable(SString& str) {
  create_table(str);
  set_headers();
};

std::vector<std::vector<SString>> DataTable::table() { return m_table; };
std::vector<SString> DataTable::headers() { return m_headers; };
std::vector<SString> DataTable::index() { return m_index; };
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
}
void DataTable::set_headers() {
  m_headers = m_table[0];
  m_table.erase(m_table.begin());
}

#endif
