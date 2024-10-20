#ifndef MAIN
#define MAIN

#include "main.h"

int main() {
  map<std::string, SString> api_data = Api::get();
  DataTable table(api_data);
  table.print();

  for (SString header : table.headers()) {
    std::cout << header.data() << " ";
  }
  std::cout << '\n';

  for (SString type : table.types()) {
    std::cout << type.data() << " ";
  }
  std::cout << '\n';

  return 0;
}

#endif
