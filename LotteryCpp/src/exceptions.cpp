#ifndef LOTTERYCPP_EXCEPTIONS_CPP_
#define LOTTERYCPP_EXCEPTIONS_CPP_

#include "exceptions.h"

ApiGetException::ApiGetException(const std::string& message)
    : m_message(message) {};

#endif  // LOTTERYCPP_EXCEPTIONS_CPP_
