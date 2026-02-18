#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>

int remove_recursive(const char *path) {
  struct stat statbuf;

  if (strcmp(path, "/") == 0) {
    fprintf(stderr, "Refusing to remove root directory\n");
    return -1;
  }


  if (lstat(path, &statbuf) == -1) {
    perror("lstat");
    return -1;
  }

  if (S_ISDIR(statbuf.st_mode)) {
    DIR *dir = opendir(path);
    if (!dir) {
      perror("opendir");
      return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
      if (strcmp(entry->d_name, ".") == 0 ||
        strcmp(entry->d_name, "..") == 0)
        continue;

      char fullpath[PATH_MAX];
      snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

      if (remove_recursive(fullpath) == -1) {
        closedir(dir);
        return -1;
      }
    }

    closedir(dir);

    if (rmdir(path) == -1) {
      perror("rmdir");
      return -1;
    }
  } else {
    if (unlink(path) == -1) {
      perror("unlink");
      return -1;
    }
  }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc ==1) {
        fprintf(stderr, "Wrong input!");
        return 1;
    }

  if(strcmp(argv[1], "-r") == 0){
    if (remove_recursive(argv[2]) == -1) {
        return 1;
    }
  } else {
    if(remove(argv[1]) != 0) {
      fprintf(stderr, "Could not remove file");
      return 1;
    }
  }

    return 0;
}