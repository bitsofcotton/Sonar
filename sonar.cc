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
  vector<typename Sonar<num_t>::sensors_t> sensors;
  for(int i = 0; i < argc; i ++) {
    typename Sonar<num_t>::sensors_t work;
    sensors.emplace_back(work);
  }
  Sonar<num_t> sonar;
  auto volumes(sonar.volumes(sensors));
  return 0;
}

