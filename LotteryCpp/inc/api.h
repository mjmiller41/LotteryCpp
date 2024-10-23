#ifndef LOTTERYCPP_API_H_
#define LOTTERYCPP_API_H_

#include <cpr/cpr.h>

#include <format>
#include <iostream>
#include <map>
#include <vector>

#include "exceptions.h"

namespace Api {

const cpr::Url url{"https://data.ny.gov/resource/5xaw-6ayf.csv"};
const std::string api_key{"yalOK0Ng6TYejhZ35N4aN3pqg"};
const std::string q{"draw_date >= '2017-10-31T00:00:00.000'"};
const cpr::Parameter token{"$$app_token", api_key.data()};
const cpr::Parameter query{"$where", q.data()};
const cpr::Parameters params{token, query};

std::string get();

};  // namespace Api

#endif  // LOTTERYCPP_API_H_
