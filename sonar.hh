#if !defined(_SONAR_)

template <typename T> class Sonar {
public:
  typedef SimpleVector<T> Vec;
  typedef SimpleMatrix<T> Mat;
  typedef struct {
    Vec<T> g;
    T i;
  } sensors_t;

  inline Sonar();
  inline Sonar(const int& density);
  inline ~Sonar();
  vector<vector<vector<T> > > volumes(const vector<sensors_t>& in) const;

private:
  inline T diversity2(const sensors_t& p0, const sensors_t& p1, const Vec& g) const;
  int density;
};

template <typename T> inline Sonar<T>::Sonar() {
  density = 20;
}

template <typename T> inline Sonar<T>::Sonar(const int& density) {
  assert(0 < density);
  this->density = density;
}

template <typename T> inline Sonar<T>::~Sonar() {
  ;
}

template <typename T> vector<vector<vector<T> > > Sonar<T>::volumes(vector<sensors_t> in) const {
  assert(5 <= in.size());
  // get edges:
  vector<T> M;
  M.reserve(3);
  assert(in[0].g.size() == 3);
  M.emplace_back(in[0].g[0]);
  M.emplace_back(in[0].g[1]);
  M.emplace_back(in[0].g[2]);
  auto m(M);
  for(int i = 1; i < in.size(); i ++) {
    assert(in[i].g.size() == 3);
    for(int j = 0; j < in[i].g.size(); j ++) {
      M[j] = max(M[j], in[i].g[j]);
      m[j] = min(m[j], in[i].g[j]);
    }
  }
  auto g((M + m) / T(2));
  auto MM(0);
  for(int i = 0; i < M.size(); i ++)
    MM = max(MM, max(M[i] - g[i], g[i] - m[i]));
  for(int i = 0; i < in.size(); i ++)
    in[i].g -= g;
  // calculate surface.
  const auto Pi(atan(T(1)) * T(4));
  for(int i = 0; i < density; i ++) {
    const auto theta(T(i) * Pi * T(2) / T(density));
    for(int j = 0; j < density; j ++) {
      const auto psi(T(j) * Pi * T(2) / T(density));
      Vec gg(3);
      gg[0] = MM * cos(theta) * cos(psi);
      gg[1] = MM * sin(theta) * cos(psi);
      gg[2] = MM *              sin(psi);
      T   avg(0);
      int cnt(0);
      for(int ii = 0; ii < in.size(); ii ++)
        for(int jj = ii + 1; jj < in.size(); jj ++) {
          avg += diversity2(in[i], in[j], gg);
          cnt ++;
        }
      avg /= T(cnt);
    }
  }
  // radon:
  vector<vector<vector<T> > > result;
  return result;
}

template <typename T> inline T Sonar<T>::diversity2(const sensors_t& p0, const sensors_t& p1, const Vec& g) const {
  
  return result;
}

#define _SONAR_
#endif

