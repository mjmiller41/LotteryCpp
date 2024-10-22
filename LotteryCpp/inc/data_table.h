#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utils.h"

class DataTable {
 public:
  DataTable(const std::map<std::string, std::string>& data);
  const std::vector<std::vector<std::string>> table() const;
  const std::vector<std::string> headers() const;
  const std::vector<std::string> row(size_t index) const;
  const std::vector<std::string> row(const std::string& timestamp) const;
  // std::vector<std::string> columnAt();
  friend std::ostream& operator<<(std::ostream&, const DataTable&);
  friend std::ostream& operator<<(std::ostream&,
                                  const std::vector<std::string>&);

 private:
  std::vector<std::vector<std::string>> m_rows;
  std::vector<std::string> m_headers;

  void createTable(const std::string& str);
};
#endif
