#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  if(argc == 1){
    printf("Not enough arguments!");
    return 1;
  }

  for(int i = 1; i < argc; i++){
    if (mkdir(argv[i], 0755) != 0) {
        perror("Error creating directory");
        return 1;
    }
  }

  return 0;
}
