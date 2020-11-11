
// pong.c: “ping-pong” a byte between two processes

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<time.h>

int
main()
{
  char buff[100];

  int p1[2], p2[2];
  pipe(p1); pipe(p2);

  clock_t start, end, i;
  double rtt;

  const int MAXITER = 100000;
  write(p2[1], "*", 1);
  if(fork() == 0) {
    close(p1[1]);
    close(p2[0]);
    start = clock();
    for(i = 0; i < MAXITER; ++i) {
      if(read(p1[0], buff, sizeof(buff)) > 0) {
        write(p2[1], buff, sizeof(buff));
      }
    }
    end = clock();
    close(p1[0]);
    close(p2[1]);
  } else {
    close(p1[0]);
    close(p2[1]);
    start = clock();
    for(i = 0; i < MAXITER; ++i) {
      if(read(p2[0], buff, sizeof(buff)) > 0) {
        write(p1[1], buff, sizeof(buff));
      }
    }
    end = clock();
    close(p2[0]);
    close(p1[1]);
    wait(0);
  }
  rtt = (((double)(end - start)) / CLOCKS_PER_SEC) / MAXITER;
  printf("average RTT: %f ms\n", (rtt * 1000));
  rtt = 1.0 / rtt;
  printf("RTT: %.05lf\n", rtt);
  exit(0);
}
