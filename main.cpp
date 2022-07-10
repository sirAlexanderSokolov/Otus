#include "includes.h"
#include "lib/lib_hello/lib_hello.h"
#include "version.h"

int main(int argc, char *argv[]) {
#ifdef PROJECT_VERSION
  printf("Hello World xD v. %d.%d.%d\n", PROJECT_VERSION_MAJOR,
         PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
#endif
  lib_hello hey("Hello world!");
  return 0;
}