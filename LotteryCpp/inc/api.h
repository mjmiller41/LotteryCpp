#ifndef API_H
#define API_H

#include <cpr/cpr.h>

#include <iostream>
#include <vector>

#include "s_string.h"

namespace Api {
const SString api_key{"yalOK0Ng6TYejhZ35N4aN3pqg"};
const SString q{"draw_date >= '2017-10-31T00:00:00.000'"};
const cpr::Parameter token{"$$app_token", api_key.data()};
const cpr::Parameter query{"$where", q.data()};
const cpr::Parameters params_{token, query};
const cpr::Url url_{"https://data.ny.gov/resource/5xaw-6ayf.csv"};

SString get(const cpr::Url& url = url_,
            const cpr::Parameters& params = params_);
void print_err(cpr::Response res);
};  // namespace Api

#endif
