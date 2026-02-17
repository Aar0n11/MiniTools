#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Not enough arguments!\n");
        return 1;
    }

    char *input = argv[argc - 1];
    FILE *stream;

    if (strcmp(input, "-") == 0) {
        stream = stdin;
    } else {
        stream = fopen(input, "r");
        if (!stream) {
            perror("Error");
            return 1;
        }
    }

    char *line = NULL;
    size_t len = 0;
    int line_count = 1;

    while (getline(&line, &len, stream) != -1) {
        printf("%s", line);
    }

    free(line);

    if (stream != stdin) {
        fclose(stream);
    }

    return 0;
}
