#if !defined(_REVERSE_GEOMETRY_WAVE_)

#include <Eigen/Core>
#include <vector>
#include <cmath>

using std::vector;

template <typename T> class RGW {
public:
  typedef Eigen::Matrix<T, 3, 1> Vec3;
  typedef struct {
    Vec3      geom;
    vector<T> data;
  } sensors_t;
  typedef struct {
    Vec3 center;
    Vec3 normal;
  } dplane_t;
  RGW();
  ~RGW();
  void init();
  vector<Vec3> volumes(const vector<sensors_t>& sensors);

private:
  dplane_t                    diversity2(const sensors_t& p0, const sensors_t& p1) const;
  vector<vector<vector<T> > > Radon(const vector<sensors_t>& sensors) const;
  vector<T> dftWithWindow(const vector<T>& intensity) const;
  int density;
};

template <typename T> RGW<T>::RGW() {
  density = 20;
}

template <typename T> RGW<T>::~RGW() {
  ;
}

template <typename T> vector<Eigen::Matrix<T, 3, 1> > RGW<T>::volumes(const vector<sensors_t>& sensors) {
  assert(5 <= sensors.size());
  // collecting error loop.
  vector<Eigen::Matrix<T, 3, 1> > result;
  vector<sensors_t> csensors;
  for(int i = 0; i < sensors.size(); i ++) {
    sensors_t work;
    work.geom = sensors[i].geom;
    work.data = dftWithWindow(sensors[i].data);
    csensors.push_back(work);
  }
  for(T err(0); err < csensors[0].data.size(); ) {
    for(int i = 0; i < csensors.size(); i ++)
      for(int j = i + 1; j < csensors.size(); j ++) {
        const auto d(diversity2(csensors[i], csensors[j]));
      }
  }
  return result;
}

template <typename T> typename RGW<T>::dplane_t RGW<T>::diversity2(const sensors_t& p0, const sensors_t& p1) const {
  dplane_t result;
  // p0 - p1 diversity.
  return result;
}


template <typename T>  vector<vector<vector<T> > > RGW<T>::Radon(const vector<sensors_t>& sensors) const {
  assert(sensors.size() == 5);
  vector<vector<vector<T> > > result;
  result.resize(density);
  for(int i = 0; i < result.size(); i ++) {
    result[i].resize(density);
    for(int j = 0; j < result.size(); j ++)
      result[j].resize(density);
  }
  return result;
}

template <typename T> vector<T> RGW<T>::dftWithWindow(const vector<T>& intensity) const {
  vector<T> res;
  return res;
}

#define _REVERSE_GEOMETRY_WAVE_
#endif

