#ifndef API
#define API

#include "api.h"

std::map<std::string, std::string> Api::get(const cpr::Url& url,
                                            const cpr::Parameters& params) {
  std::cout << "Requesting api data ...\n";
  cpr::Response res =
      cpr::Get(cpr::Url{"https://data.ny.gov/resource/5xaw-6ayf.csv"},
               cpr::Parameters{params});
  std::map<std::string, std::string> data;
  switch (res.status_code) {
    case 200:
      std::cout << "Request successful\n";
      data["data"] = std::string(res.text);
      data["fields"] = std::string(res.header["X-Soda2-Fields"]);
      data["types"] = std::string(res.header["X-Soda2-Types"]);
      return data;
    case 202:  // 202 == Request Processing, try again
      std::cout << "Retrying request ...\n";
      return get(url, params);
    default:
      print_err(res);
      return data;
  }
}

void Api::print_err(cpr::Response res) {
  if (res.error) {
    std::cerr << "Error Message: " << res.error.message << '\n';
  }
  std::cerr << "Status Code: [" << res.status_code << "]\n";
  std::cerr << "Status: " << res.status_line << '\n';
  std::cerr << "Response Body: " << res.text << '\n';
};

#endif
