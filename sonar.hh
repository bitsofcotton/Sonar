#if !defined(_SONAR_)

template <typename T> inline T diversity3(const pair<SimpleVector<T>, T>& p0, const pair<SimpleVector<T>, T>& p1, const pair<SimpleVector<T>, T>& p2, const SimpleVector<T>& g) {
  T result(0);
  return result;
}

template <typename T> vector<vector<vector<T> > > volumes(vector<pair<SimpleVector<T>, T> >& in, const int& density = 20) {
  assert(5 <= in.size());
  // get edges:
  SimpleVector<T> M(3);
  assert(in[0].first.size() == 3);
  for(int i = 0; i < M.size(); i ++)
    M[i] = in[0].first[i];
  auto m(M);
  for(int i = 1; i < in.size(); i ++) {
    assert(in[i].first.size() == 3);
    for(int j = 0; j < in[i].first.size(); j ++) {
      M[j] = max(M[j], in[i].first[j]);
      m[j] = min(m[j], in[i].first[j]);
    }
  }
  const auto g((M + m) / T(2));
        T    MM(0);
  for(int i = 0; i < M.size(); i ++)
    MM = max(MM, max(M[i] - g[i], g[i] - m[i]));
  for(int i = 0; i < in.size(); i ++)
    in[i].first -= g;
  // calculate surface.
  const auto Pi(atan(T(1)) * T(4));
  for(int i = 0; i < density; i ++) {
    const auto theta(T(i) * Pi * T(2) / T(density));
    for(int j = 0; j < density; j ++) {
      const auto psi(T(j) * Pi * T(2) / T(density));
      SimpleVector<T> gg(3);
      gg[0] = MM * cos(theta) * cos(psi);
      gg[1] = MM * sin(theta) * cos(psi);
      gg[2] = MM *              sin(psi);
      T   avg(0);
      int cnt(0);
      for(int ii = 0; ii < in.size(); ii ++)
        for(int jj = ii + 1; jj < in.size(); jj ++)
          for(int kk = jj + 1; kk < in.size(); kk ++) {
            avg += diversity3<T>(in[ii], in[jj], in[kk], gg);
            cnt ++;
          }
      avg /= T(cnt);
    }
  }
  // inverse field:
  vector<vector<vector<T> > > result;
  return result;
}

#define _SONAR_
#endif

