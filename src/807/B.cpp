#include <cstdio>

int winners[475];

bool winsWith(int i0, int p) {
  int i = i0;
  for(int j = 0; j < 25; j++) {
    i = (i * 96 + 42) % 475;
    if(26 + i == p) return true;
  }
  return false;
}

int main() {
  int p, x, y; scanf("%d %d %d\n", &p, &x, &y);

  for(int i = 0; i < 475; i++) {
    winners[i] = winsWith(i, p);
  }

  int res = 0; bool found = false;
  for(int currX = x; currX >= y; currX -= 50) {
    if(winners[currX / 50 % 475]) { found = true; break; }
  }
  while(!found) {
    x += 100; res++;
    if(winners[x / 50 % 475]) found = true;
    if(winners[(x - 50) / 50 % 475]) found = true;
  }
  printf("%d\n", res);
  return 0;
}
