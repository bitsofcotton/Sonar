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
  vector<RGW<double>::sensors_t> sensors;
  for(int i = 0; i < argc; i ++) {
    RGW<double>::sensors_t work;
    sensors.push_back(work);
  }
  RGW<double> rgw;
  auto volumes(rgw.volumes(sensors));
  return 0;
}

