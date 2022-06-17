#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("pass an input file (no other arguments)\n");
        return 1;
    }

    char* input_file = argv[1];
    FILE * fp = fopen(input_file, "r");
    int c;

    if (fp){
        while((c = getc(fp)) != EOF) {
            putchar(c);
        }
    } else {
        printf("Failed to read file\n");
        return 1;
    }

    return fclose(fp);
}