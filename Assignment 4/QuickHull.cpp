#include <bits/stdc++.h>
using namespace std;

int n;

typedef double T;
const T EPS = 1e-7;
struct PT
 { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};
 
T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); 
}


void ConvexHull(vector<PT> &pts) {

  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0)
            up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0)
          dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
 
  for (int i = (int) up.size() - 2; i >= 1; i--) 
    pts.push_back(up[i]);
  
#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);

  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }

  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  
  pts = dn;
#endif
}
 
 
 
int main()
{
  
  cin >> n;
 
  std::vector<PT> v;
  v.resize(n);
 
  for(int i=0;i<n;i++)
  {
    cin >> v[i].x >> v[i].y;
  }
 
  ConvexHull(v);
 
  T ans = 0;
  n = v.size();
  for(int i=0;i<n;i++)
  {
    cout << v[i].x << " " << v[i].y << endl;
  }
  return 0;
}
Input :
6    
1 1    
2 5    
3 3    
5 3    
3 2    
2 2
Output :
1 1
5 3
2 5
