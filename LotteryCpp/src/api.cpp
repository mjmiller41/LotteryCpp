#ifndef LOTTERYCPP_API_CPP_
#define LOTTERYCPP_API_CPP_

#include "api.h"

std::string Api::get() {
  std::cout << "Requesting api data ...\n";
  cpr::Response res = cpr::Get(cpr::Url{url}, cpr::Parameters{params});
  std::map<std::string, std::string> data;
  switch (res.status_code) {
    case 200:
      std::cout << "Request successful\n";
      return std::string(res.text);
    case 202:  // 202 == Request Processing, try again
      std::cout << "Retrying request ...\n";
      return get();
    default:
      std::string message = std::format("Error: {}\n", res.status_code);
      message += std::format("{}", res.status_line);
      throw ApiGetException(message);
  }
}

#endif  // LOTTERYCPP_API_CPP_
