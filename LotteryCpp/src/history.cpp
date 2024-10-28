#ifndef LOTTERYCPP_HISTORY_CPP_
#define LOTTERYCPP_HISTORY_CPP_

#include "history.h"

// PRIVATE
void History::initDrawings(std::string &data_str)
{
  std::vector<std::string> data_vctr = Utils::split(data_str, '\n');
  for (auto item : data_vctr)
  {
    if (item == "" || item.starts_with("draw_date"))
      continue;
    m_drawings.push_back(new Drawing(item));
  }
}

// PUBLIC
History::History(std::string &data_str) { initDrawings(data_str); }

const Drawings *History::drawings() const { return &m_drawings; }

void History::sort(SortOrder order) const
{
  if (order == SortOrder::descending)
  {
    std::sort(m_drawings.begin(), m_drawings.end(),
              [](const Drawing *drawing_a, const Drawing *drawind_b)
              { return drawing_a->draw_date() > drawind_b->draw_date(); });
  }
  else if (order == SortOrder::ascending)
  {
    std::sort(m_drawings.begin(), m_drawings.end(),
              [](const Drawing *drawing_a, const Drawing *drawind_b)
              { return drawing_a->draw_date() < drawind_b->draw_date(); });
  }
}

std::ostream &operator<<(std::ostream &out, const History &history)
{
  for (auto drawing : history.m_drawings)
  {
    out << *drawing << '\n';
  }
  return out;
}

History::~History()
{
  for (size_t i = 0; i < m_drawings.size(); i++)
  {
    // std::cout << "[" << i << "] ";
    delete m_drawings[i];
  }
  std::cout << "History deleted\n";
}

#endif // LOTTERYCPP_HISTORY_CPP_
