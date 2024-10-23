#ifndef LOTTERYCPP_MEGA_MILLIONS_H_
#define LOTTERYCPP_MEGA_MILLIONS_H_

#include <iostream>
#include <string>

#include "data_table.h"

class MegaMillions {
 public:
  MegaMillions(DataTable data_table);
  const DataTable history() const;

 private:
  DataTable m_history;
  const int m_white_ball_limit{70};
  const int m_mega_ball_limit{25};
};

#endif  // LOTTERYCPP_MEGA_MILLIONS_CPP_
