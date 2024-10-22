#ifndef MAIN
#define MAIN

#include "main.h"

int main() {
  std::map<std::string, std::string> api_data = Api::get();
  DataTable table(api_data);
  std::cout << table << '\n';
  std::vector<std::string> row = table.row("2017-11-07T00:00:00.000");
  std::cout << row << " ";

  for (std::string item : row) {
    std::cout << item << " ";
  }
  std::cout << '\n';
  for (std::string header : table.headers()) {
    std::cout << header.data() << " ";
  }
  std::cout << '\n';

  return 0;
}

#endif
