#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int p1[2], p2[2];
  int pid, n;
  char buf[512];

  pipe(p1);
  pipe(p2);

  if(fork() == 0) {
    pid = getpid();
    close(p1[1]);
    close(p2[0]);
    n = read(p1[0], buf, sizeof buf); // Read over pipe1
    close(p1[0]); // Close pipe1
    printf(0, "%d: received ping\n", pid);
    write(p2[1], buf, n); // write over pipe2
    close(p2[1]); // Close pipe2
    exit();
  } else {
    pid = getpid();
    close(p1[0]); // Close read of pipe1
    close(p2[1]); // Close write of pipe2
    write(p1[1], "byte", 4); // Send over pipe1 write
    close(p1[1]); // Close  pipe1
    n = read(p2[0], buf, sizeof(buf)); // Read over pipe2
    printf(0, "%d: received pong\n", pid);
    close(p2[0]); // Close pipe2
    wait();
  }
  exit();
}
