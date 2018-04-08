#include <cstdio>
#include "rgeom.hh"

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

