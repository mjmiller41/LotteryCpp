#ifndef LOTTERYCPP_MAIN_CPP_
#define LOTTERYCPP_MAIN_CPP_

#include "main.h"

int main() {
  std::string api_data{};
  try {
    api_data = Api::get();
  } catch (ApiGetException e) {
    std::cerr << e.what() << '\n';
  }
  DataTable table(api_data);
  MegaMillions mega_millions(table);
  DataTable mm_history = mega_millions.history();
  // std::cout << table << '\n';
  std::cout << mega_millions.history().headers() << '\n';

  const std::string timestamp{"2017-11-07T00:00:00.000"};
  std::vector<std::string> row1 = mm_history.row(timestamp);
  std::cout << row1 << '\n';

  std::vector<std::string> row2 = mm_history.row(22);
  std::cout << row2 << '\n';

  std::vector<std::string> column1 = mm_history.column(0);
  std::cout << column1 << '\n';

  std::vector<std::string> column2 = mm_history.column("winning_numbers");
  std::cout << column2 << '\n';

  return 0;
}

#endif  // LOTTERYCPP_MAIN_CPP_
