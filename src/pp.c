#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
  char *string = "nice?good&bucuo";
  char *sub = strstr(string, "?");
  printf("%s\n", sub+1);
  return 0;
}
