#ifndef DATA_TABLE
#define DATA_TABLE

#include "data_table.h"

// PUBLIC members
DataTable::DataTable(const std::map<std::string, std::string>& data) {
  const std::string& str = data.at("data");
  createTable(str);
};
const std::vector<std::vector<std::string>> DataTable::table() const {
  return m_rows;
}
const std::vector<std::string> DataTable::headers() const { return m_headers; }
const std::vector<std::string> DataTable::row(size_t index) const {
  return m_rows[index];
};
const std::vector<std::string> DataTable::row(
    const std::string& timestamp) const {
  size_t index = 0;
  for (size_t i = 0; i < m_rows.size(); i++) {
    if (timestamp == m_rows[i][0]) {
      index = i;
    }
  }
  return m_rows[index];
};
// std::vector<std::string> DataTable::columnAt() {};
std::ostream& operator<<(std::ostream& out, const DataTable& data_table) {
  const auto t_len = data_table.m_rows.size();
  out << "[";
  for (size_t i = 0; i < t_len; i++) {
    const auto& row = data_table.m_rows[i];
    const auto r_len = row.size();
    for (size_t j = 0; j < r_len; j++) {
      j < r_len - 1   ? out << "\"" << row[j] << "\", "
      : i < t_len - 1 ? out << "\"" << row[j] << "\"\n"
                      : out << "\"" << row[j] << "\"";
    }
  }
  out << "]";
  return out;
}

std::ostream& operator<<(std::ostream& out,
                         const std::vector<std::string>& row) {
  out << "[";
  for (size_t i = 0; i < row.size(); i++) {
    if (i < row.size() - 1) {
      out << "\"" << row[i] << "\", ";
    } else {
      out << "\"" << row[i] << "\"]\n";
    }
  }
  return out;
}

// PRIVATE members
void DataTable::createTable(const std::string& str) {
  std::vector<std::string> str_rows = Utils::split(str, '\n');
  std::vector<std::vector<std::string>> rows;
  for (auto& str_row : str_rows) {
    auto row = Utils::split(str_row, ',');
    for (auto& item : row) {
      Utils::replace(item, "\"", "");
    }
    rows.push_back(row);
  }
  m_headers = rows[0];
  rows.erase(rows.begin());
  m_rows = rows;
}

#endif
