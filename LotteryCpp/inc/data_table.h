#ifndef LOTTERYCPP_DATA_TABLE_H_
#define LOTTERYCPP_DATA_TABLE_H_

#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

#include "drawing.h"
#include "utils.h"

std::ostream &operator<<(std::ostream &out,
                         const std::vector<std::string> &row);

class DataTable {
 public:
  DataTable(const std::string &data);
  const Drawings drawings() const;
  const std::vector<std::string> headers() const;
  const std::vector<std::string> row(const size_t index) const;
  const std::vector<std::string> row(const std::string &timestamp) const;
  const std::vector<std::string> column(const size_t index) const;
  const std::vector<std::string> column(const std::string &header) const;
  friend std::ostream &operator<<(std::ostream &, const DataTable &);

 private:
  std::vector<Drawing> m_data;
  std::vector<std::string> m_headers;
  void createTable(const std::string &str);
};

#endif  // LOTTERYCPP_DATA_TABLE_H_
