#include "types.h"
#include "stat.h"
#include "user.h"

void f(int p1[2]) {
  close(p1[1]);
  int tmp, n, p;
  n = read(p1[0], &tmp, sizeof(tmp));
  if(n == 0) return;
  p = tmp;
  printf(1, "prime %d\n", p);
  int p2[2];
  pipe(p2);
  if(fork() == 0) {
    f(p2);
  } else {
    close(1);
    close(p2[0]);
    while(read(p1[0], &tmp, sizeof(tmp))) {
      if(tmp % p == 0) continue;
      write(p2[1], &tmp, sizeof(tmp));
    }
    close(p1[0]);
    close(p2[1]);
    wait();
  }
}

int main(int argc, char *argv[])
{
  int p1[2];
  int i;
  pipe(p1);
  close(0);

  if(fork() == 0) {
    f(p1);
  } else {
    close(1);
    close(p1[0]);
    for(i = 2; i < 35; ++i) {
      write(p1[1], &i, sizeof(i));
    }
    close(p1[1]); // Close pipe2
    wait();
  }
  exit();
}
