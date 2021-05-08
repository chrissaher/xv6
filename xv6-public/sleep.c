#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  if(argc < 2) {
    printf(2, "Missing parameter ticks ...\n");
    exit();
  }
  int ticks;
  ticks = atoi(argv[1]);
  sleep(ticks);
  exit();
}
