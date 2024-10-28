#ifndef LOTTERYCPP_MEGA_MILLIONS_H_
#define LOTTERYCPP_MEGA_MILLIONS_H_

#include <iostream>
#include <string>

#include "history.h"

class MegaMillions
{
public:
  MegaMillions(std::string &data_str);
  const History *history() const;
  ~MegaMillions();

private:
  History *m_history = nullptr;
  const int m_white_ball_limit{70};
  const int m_mega_ball_limit{25};
};

#endif // LOTTERYCPP_MEGA_MILLIONS_CPP_
