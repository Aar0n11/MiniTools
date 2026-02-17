#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if(argc == 1){
    printf("Not enough arguments!");
    return 1;
  }

  for(int i = 1; i < argc; i++){
    if (rmdir(argv[i]) != 0) {
        perror("Error removing directory");
        return 1;
    }
  }

  return 0;
}
