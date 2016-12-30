#include <cstdio>

#define MAXL 20000

using namespace std;

char dir[6];

int main() {
  int n; scanf("%d\n", &n);

  int lat = 0; bool valid = true;
  for(int i = 0; i < n; i++) {
    int v; scanf("%d %s\n", &v, dir);

    switch(dir[0]) {
      case 'N': lat -= v; break;
      case 'S': lat += v; break;
      default: if(lat == 0 || lat == MAXL) lat = -1;
    }
    if(lat < 0 || lat > MAXL) {
      valid = false;
      break;
    }
  }
  printf("%s\n", valid && lat == 0 ? "YES" : "NO");
  return 0;
}
