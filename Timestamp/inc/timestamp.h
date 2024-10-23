#ifndef TIMESTAMP_TIMESTAMP_H_
#define TIMESTAMP_TIMESTAMP_H_

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std::chrono;
using Clock = system_clock;
using TimePoint = time_point<Clock>;

class Timestamp {
 public:
  Timestamp(const std::string& timestamp) : m_timestamp{timestamp} {
    m_timepoint = toTimePoint(timestamp);
  };
  const std::string timestamp() const;
  friend std::ostream& operator<<(std::ostream& out, const Timestamp& dt);

 private:
  const std::string fmt = "%Y-%m-%dT%H:%M:%S.000";
  std::string m_timestamp;
  TimePoint m_timepoint;
  TimePoint toTimePoint(std::string timestamp);
  std::string toTimestamp(TimePoint time_point);
};

#endif  // TIMESTAMP_TIMESTAMP_H_
