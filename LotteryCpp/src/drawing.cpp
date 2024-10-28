#ifndef LOTTERYCPP_DRAWING_CPP_
#define LOTTERYCPP_DRAWING_CPP_

#include "drawing.h"

Drawing::Drawing(std::string &data_str)
{
  std::vector<std::string> data_vctr = Utils::split(data_str, ',');
  m_draw_date = data_vctr[0];
  m_winning_numbers = Utils::split(data_vctr[1], ' ');
  Utils::zFill(data_vctr[2], 2);
  m_mega_ball = data_vctr[2];
  m_multiplier = data_vctr[3];
}

const std::string Drawing::draw_date() const { return m_draw_date; }

const winning_nums Drawing::winning_numbers() const
{
  return m_winning_numbers;
}

const std::string Drawing::mega_ball() const { return m_mega_ball; }

const std::string Drawing::multiplier() const { return m_multiplier; }

const std::string Drawing::win_nums_str() const
{
  std::string str = std::format("[\"{}\", \"{}\", \"{}\", \"{}\", \"{}\"]",
                                m_winning_numbers[0], m_winning_numbers[1],
                                m_winning_numbers[2], m_winning_numbers[3],
                                m_winning_numbers[4]);
  return str;
}

std::ostream &operator<<(std::ostream &out, const Drawing &drawing)
{
  out << std::format("{{draw_date: \"{}\", ", drawing.m_draw_date);
  out << std::format("winning_numbers: {}, ", drawing.win_nums_str());
  out << std::format("mega_ball: \"{}\", ", drawing.m_mega_ball);
  out << std::format("multiplier: \"{}\"}}", drawing.m_multiplier);
  return out;
}

Drawing::~Drawing() { /*std::cout << "Drawing deleted\n";*/ }

#endif // LOTTERYCPP_DRAWING_CPP_
