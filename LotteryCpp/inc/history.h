#ifndef LOTTERYCPP_HISTORY_H_
#define LOTTERYCPP_HISTORY_H_

#include "drawing.h"
#include "utils.h"

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using Drawings = std::vector<Drawing *>;

enum DrawingField
{
  draw_date,
  winning_numbers,
  mega_ball,
  multiplier,
};
enum SortOrder
{
  ascending,
  descending,
};

class History
{
private:
  Drawings m_drawings;
  void initDrawings(std::string &data_str);

public:
  History(std::string &data_str);
  const Drawings *drawings() const;
  void sort(SortOrder order) const;
  friend std::ostream &operator<<(std::ostream &out, const History &history);

  ~History();
};

#endif // LOTTERYCPP_HISTORY_H_
