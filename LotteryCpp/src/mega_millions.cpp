#ifndef LOTTERYCPP_MEGA_MILLIONS_CPP_
#define LOTTERYCPP_MEGA_MILLIONS_CPP_

#include "mega_millions.h"

// PUBLIC MEMBERS
MegaMillions::MegaMillions(std::string &data_str)
    : m_history(new History(data_str))
{
}
const History *MegaMillions::history() const { return m_history; }
MegaMillions::~MegaMillions() { delete m_history; }

// PRIVATE MEMBERS

#endif // LOTTERYCPP_MEGA_MILLIONS_CPP_
