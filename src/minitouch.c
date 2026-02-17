#include <stdio.h>

int main(int argc, char *argv[]){
  if(argc == 1) {
    printf("Not enough arguments!");
    return 1;
  }

  for(int i = 1; i < argc; i++){
    FILE *fp;
    fp = fopen(argv[i], "w");

    if (!fp) {
      printf("Error creating file: %s", argv[i]);
      return 1;
    }

    fclose(fp);
  }

  return 0;
}
