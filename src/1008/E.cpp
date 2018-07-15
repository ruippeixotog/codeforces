#include <cstdio>

typedef long long ll;
typedef long double ld;

int main() {
  ll n; scanf("%lld", &n);

  ll minA = 1, hardMaxA = n, softMaxA = n;
  ll minB = 1, hardMaxB = n, softMaxB = n;
  while(true) {
    ll currA = (minA + softMaxA) / 2, currB = (minB + softMaxB) / 2;

    ld s00 = ld(softMaxA - minA) * ld(softMaxB - minB);
    ld s10 = ld(hardMaxA - softMaxA) * ld(softMaxB - minB);
    ld s01 = ld(softMaxA - minA) * ld(hardMaxB - softMaxB);
    if (s10 > s00 + s01) currA = softMaxA;
    if (s01 > s00 + s10) currB = softMaxB;

    printf("%lld %lld\n", currA, currB);
    fflush(stdout);

    int ans; scanf("%d", &ans);
    if(ans == 0) return 0;
    if(ans == 1) minA = currA + 1;
    else if(ans == 2) minB = currB + 1;
    else if(ans == 3) { softMaxA = currA - 1; softMaxB = currB - 1; }

    if(minA > softMaxA) { hardMaxB = softMaxB; softMaxA = hardMaxA; }
    if(minB > softMaxB) { hardMaxA = softMaxA; softMaxB = hardMaxB; }
  }
}
