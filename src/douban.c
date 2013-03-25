#include <stdio.h>
#include <string.h>
#include "http.h"

// 用户登录信息
struct user_info {
  char user_id[15];
  char token[15];
  char expire[15];
};

// 歌曲信息
struct song_info {
  char title[30];
  char artist[50];
  char url[100];
};

int request_user_info(struct user_info *info, char *username, char *passwd) {
  struct string result;
  char url[120];
  sprintf(url, "http://www.douban.com/j/app/login?app_name=radio_desktop_win&version=100&email=%s&password=%s",
      username, passwd);
  printf("url is %s: \n", url);
  doRequest(url, &result, POST);
  printf("result %s :\n", result.ptr);
  return 0;
}
int request_songs(struct song_info[], int size);

int main(int argc, const char *argv[])
{
  struct user_info u_info;
  request_user_info(&u_info, "linq.box@qq.com", "fancylinq");
  return 0;
}
