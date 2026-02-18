#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
  char path[PATH_MAX];

  if(getcwd(path, sizeof(path)) != NULL){
    printf("%s\n", path);
  } else {
    perror("Error");
    return 1;
  }

  return 0;
}
