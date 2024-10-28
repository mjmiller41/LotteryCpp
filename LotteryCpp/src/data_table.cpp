#ifndef LOTTERYCPP_DATA_TABLE_CPP_
#define LOTTERYCPP_DATA_TABLE_CPP_

#include "data_table.h"

// PUBLIC members
DataTable::DataTable(const std::string &data) { /*createTable(data);*/ }

const Drawings DataTable::drawings() const { return m_data; }

const std::vector<std::string> DataTable::headers() const { return m_headers; }

const std::vector<std::string> DataTable::row(const size_t index) const {
  return m_data[index];
};

const std::vector<std::string> DataTable::row(
    const std::string &timestamp) const {
  std::vector<std::string> items;
  size_t index = m_data.size();
  try {
    for (size_t i = 0; i < m_data.size(); i++) {
      index = Utils::find(timestamp, m_data[i]);
      if (index < m_data[i].size()) break;
    }
  } catch (const char *txtExcpt) {
    std::cerr << txtExcpt << '\n';
  } catch (...) {
    std::cerr << "Unknown exception occured!\n";
  };
  return m_data[index];
};

const std::vector<std::string> DataTable::column(const size_t index) const {
  std::vector<std::string> column;
  // for (std::vector<std::string> row : m_data) {
  for (size_t i = 0; i < m_data.size(); i++) {
    column.push_back(m_data[i][index]);
  }
  return column;
};

const std::vector<std::string> DataTable::column(
    const std::string &header) const {
  size_t index = Utils::find(header, m_headers);
  return column(index);
};

std::ostream &operator<<(std::ostream &out, const DataTable &data_table) {
  const auto t_len = data_table.m_data.size();
  out << "[";
  for (size_t i = 0; i < t_len; i++) {
    const auto &row = data_table.m_data[i];
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

std::ostream &operator<<(std::ostream &out,
                         const std::vector<std::string> &row) {
  out << "[";
  for (size_t i = 0; i < row.size(); i++) {
    if (i < row.size() - 1) {
      out << "\"" << row[i] << "\",\n";
    } else {
      out << "\"" << row[i] << "\"]";
    }
  }
  return out;
}

// PRIVATE members
void DataTable::createTable(const std::string &str) {
  std::vector<std::string> str_rows = Utils::split(str, '\n');
  for (auto &str_row : str_rows) {
    std::vector<std::string> row = Utils::split(str_row, ',');
    for (auto &item : row) {
      Utils::replace(item, '"', "");
    }
    if (row.size() != 4) continue;
    m_data.push_back(row);
  }
  m_headers = m_data[0];
  m_data.erase(m_data.begin());
}

#endif  // LOTTERYCPP_DATA_TABLE_CPP_
