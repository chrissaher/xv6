
// pong.c: “ping-pong” a byte between two processes

#include "types.h"
#include "user.h"
#include "fcntl.h"


int
main(void)
{
  write(1, "hello world\n", 12);
  exit();
}
