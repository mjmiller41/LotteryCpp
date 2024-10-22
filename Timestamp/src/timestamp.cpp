#ifndef DATETIME
#define DATETIME

#include "timestamp.h"

// Public members
const std::string Timestamp::timestamp() const { return m_timestamp; }
std::ostream& operator<<(std::ostream& out, const Timestamp& dt) {
  out << dt.m_timestamp;
  return out;
}

// Private members
TimePoint Timestamp::toTimePoint(std::string timestamp) {
  std::tm tmb = {};
  tmb.tm_isdst = -1;  // -1 causes mktime() to determine if DST was in effect.
  std::istringstream is_stream(timestamp);
  is_stream >> std::get_time(&tmb, fmt.c_str());
  std::time_t time_t = std::mktime(&tmb);
  return Clock::from_time_t(time_t);
}
std::string Timestamp::toTimestamp(TimePoint time_point) {
  std::time_t time_t = Clock::to_time_t(time_point);
  std::tm* tp = std::gmtime(&time_t);
  char str[100];
  size_t count = sizeof("YYYY-MM-DDT00:00:00");
  std::strftime(str, count, fmt.c_str(), tp);
  return static_cast<std::string>(str);
}

#endif
