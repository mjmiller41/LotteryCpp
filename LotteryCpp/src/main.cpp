#ifndef MAIN
#define MAIN

#include "main.h"

int main() {
  SString text = Api::get();
  DataTable table(text);
  table.print();

  return 0;
}

#endif
