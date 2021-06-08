#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <assert.h>

#include "lieonn.hh"
typedef myfloat num_t;
#include "sonar.hh"

int main(int argc, const char* argv[]) {
  vector<pair<SimpleVector<num_t>, num_t> > sensors;
  for(int i = 0; i < argc; i ++)
    sensors.emplace_back(make_pair(SimpleVector<num_t>(3), num_t(0)));
  auto v(volumes<num_t>(sensors));
  return 0;
}

