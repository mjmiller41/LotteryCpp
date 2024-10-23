#ifndef LOTTERYCPP_MEGA_MILLIONS_CPP_
#define LOTTERYCPP_MEGA_MILLIONS_CPP_

#include "mega_millions.h"

// PUBLIC MEMBERS
MegaMillions::MegaMillions(DataTable data_table) : m_history{data_table} {}
const DataTable MegaMillions::history() const { return m_history; }

// PRIVATE MEMBERS

#endif  // LOTTERYCPP_MEGA_MILLIONS_CPP_
