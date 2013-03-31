#include <stdio.h>
#include <stdlib.h>
#include "common.h"

char *read_file(char *path) {
  FILE *fp = fopen(path, "r");
  fseek(fp, 0, SEEK_END);
  int len = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *s = malloc(len * sizeof(char));
  int ch;
  int i = 0;
  while ((ch = getc(fp)) != EOF) {
    s[i] = ch;
    i++;
  }
  fclose(fp);

  return s;
}

