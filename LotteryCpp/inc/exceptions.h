#ifndef LOTTERYCPP_EXCEPTIONS_H_
#define LOTTERYCPP_EXCEPTIONS_H_

#include <iostream>
#include <map>

class ApiGetException : public std::exception {
 public:
  ApiGetException(const std::string& message);
  const char* what() const noexcept override { return m_message.c_str(); };

 private:
  std::string m_message;
};

#endif  // LOTTERYCPP_EXCEPTIONS_H_
