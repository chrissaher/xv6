// sleep

#include "types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  if(argc < 2) {
    printf(2, "Missing one parameter ...\n");
    exit();
  }else if(argc < 2) {
    printf(2, "Too many parameters ...\n");
    exit();
  }
  int i, ticks;
  for(i = 0; i < strlen(argv[1]); ++i) {
    if(argv[1][i] < '0' || argv[1][i] > '9') {
      printf(2, "Paramenters must be a valid number ...\n");
      exit();
    }
  }
  ticks = atoi(argv[1]);
  if(sleep(ticks) == 0) {
    printf(2, "Woke up ...\n");
  } else {
    printf(2, "Unexpected error ... \n", argv[1]);
  }
  exit();
}
