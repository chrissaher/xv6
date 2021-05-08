#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"


int main(int argc, char *argv[]) {

  char tmp;
  char buf[512];
  int i = 0;
  while(read(0, &tmp, sizeof(tmp))) {
    if(tmp == '\n') {
      if(fork() == 0) {
        static char *cmdargs[MAXARG];
        int j, it = 0;
        for(j = 1; j < argc; ++j) {
          cmdargs[it++] = argv[j];
        }
        cmdargs[it] = buf;
        exec(argv[1], cmdargs);

        exit();
      } else {
        wait();
      }

      memset(buf, 0, i);
      i = 0;
      continue;
    }
    buf[i++] = tmp;
    if(i >= 512) {
      printf(2, "Line longer than max. allowed");
      exit();
    }
  }
  exit();
}
