#ifndef LOTTERYCPP_MAIN_CPP_
#define LOTTERYCPP_MAIN_CPP_

#include "main.h"

int main()
{
  std::string api_data{};
  try
  {
    api_data = Api::get();
  }
  catch (ApiGetException &e)
  {
    std::cerr << e.what() << '\n';
  }
  // DataTable table(api_data);
  MegaMillions mega_millions(api_data);
  const History *mm_history = mega_millions.history();
  const Drawings *drawings = mm_history->drawings();

  mm_history->sort(SortOrder::descending);
  std::cout << mm_history << '\n';

  return 0;
}

#endif // LOTTERYCPP_MAIN_CPP_
