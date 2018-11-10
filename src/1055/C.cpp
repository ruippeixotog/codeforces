#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 200000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int a[MAXN];

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  ll la, ra, ta; scanf("%lld %lld %lld\n", &la, &ra, &ta);
  ll lb, rb, tb; scanf("%lld %lld %lld\n", &lb, &rb, &tb);

//  ll lcm = ta * tb / gcd(ta, tb);
  if(ta > tb) {
    swap(la, lb); swap(ra, rb); swap(ta, tb);
  }

  ll g = gcd(ta, tb);

  ll ka = (lb - la + g - 1) / g;
  ll lka = la + ka * g;
  ll rka = ra + ka * g;
//    cerr << "ka: " << ka << ", lka: " << lka << ", rka: " << rka << endl;
  ll best = max(0LL, min(rka, rb) - max(lka, lb) + 1);

  ka--;
  lka = la + ka * g;
  rka = ra + ka * g;
//      cerr << "ka: " << ka << ", lka: " << lka << ", rka: " << rka << endl;
  best = max(best, min(rka, rb) - max(lka, lb) + 1);

////  cerr << "ta: " << ta << ", tb: " << tb << endl;
//
//  ll best = 0;
//  for(int kb = 0; kb * tb < lcm; kb++) {
//    ll lkb = lb + kb * tb;
//    ll rkb = rb + kb * tb;
////    cerr << "kb: " << kb << ", lkb: " << lkb << ", rkb: " << rkb << endl;
//
//    ll ka = (lkb - la + ta - 1) / ta;
//    ll lka = la + ka * ta;
//    ll rka = ra + ka * ta;
////    cerr << "ka: " << ka << ", lka: " << lka << ", rka: " << rka << endl;
//    best = max(best, min(rka, rkb) - max(lka, lkb) + 1);
//
//    if(ka > 0) {
//      ka--;
//      lka = la + ka * ta;
//      rka = ra + ka * ta;
////      cerr << "ka: " << ka << ", lka: " << lka << ", rka: " << rka << endl;
//      best = max(best, min(rka, rkb) - max(lka, lkb) + 1);
//    }
//  }
  printf("%lld\n", best);
  return 0;
}
