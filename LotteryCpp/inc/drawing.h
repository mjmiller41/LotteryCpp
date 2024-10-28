#ifndef LOTTERYCPP_DRAWING_H_
#define LOTTERYCPP_DRAWING_H_

#include <format>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"

using winning_nums = std::vector<std::string>;

class Drawing
{
private:
  std::string m_draw_date;
  std::vector<std::string> m_winning_numbers;
  std::string m_mega_ball;
  std::string m_multiplier;

public:
  Drawing(std::string &data_str);
  const std::string draw_date() const;
  const winning_nums winning_numbers() const;
  const std::string mega_ball() const;
  const std::string multiplier() const;
  const std::string win_nums_str() const;

  friend std::ostream &operator<<(std::ostream &out, const Drawing &drawing);

  ~Drawing();
};

#endif // LOTTERYCPP_DRAWING_H_
