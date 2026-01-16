#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2 || argc > 2) {
    printf("Usage %s <filepath>\n", argv[0]);
    exit(1);
  }

  FILE *input = fopen(argv[1], "rb");
  if (!input) {
    perror("fopen() failed: no such file");
    exit(1);
  }

  fseek(input, 0, SEEK_END);
  int file_size = ftell(input);
  rewind(input);

  unsigned char bytes[2];
  int count = fread(bytes, 1, file_size, input);
  fclose(input);

  for (int i = 0; i < count; i++) {
    printf("Byte %d: %b\n", i + 1, bytes[i]);
  }

  printf("Program complete!\n");
  exit(0);
}
