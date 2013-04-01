#include <stdio.h>
#include "common.h"
#include "douban.h"

int main(int argc, const char *argv[])
{
  user_info *user = request_user_info("linq.box@qq.com", "fancylinq");
  printf("%s\n", user->user_id);
  return 0;
}
