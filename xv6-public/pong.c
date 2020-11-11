
// pong.c: “ping-pong” a byte between two processes

#include "types.h"
#include "user.h"
#include "fcntl.h"


int
main(void)
{
  int n, pid;
  int fds[2];
  char buf[100];

  // create a pipe, with two FDs in fds[0], fds[1].
  pipe(fds);

  pid = fork();
  if (pid == 0) {
    write(fds[1], "this is pipe2\n", 14);
  } else {
    n = read(fds[0], buf, sizeof(buf));
    write(1, buf, n);
  }
  exit();
}
