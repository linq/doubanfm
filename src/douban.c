#include <stdio.h>
#include <string.h>
#include "http.h"
#include "json.h"

int request_user_info(struct user_info *info, char *username, char *passwd) {
  struct string result;
  char url[URL_LEN];
  sprintf(url, "http://www.douban.com/j/app/login?app_name=radio_desktop_win&version=100&email=%s&password=%s",
      username, passwd);
  printf("url is %s: \n", url);
  doRequest(url, &result, POST);
  printf("result %s :\n", result.ptr);
  to_user_info(&result, info);
  printf("user_id: \n", info->user_id);
  printf("token: \n", info->token);
  printf("expire: \n", info->expire);
  return 0;
}
int request_songs(struct user_info *info, struct song_info song_infos[], int size) {
  struct string result;
  char url[URL_LEN];
  sprintf(url, "http://www.douban.com/j/app/radio/people?app_name=radio_desktop_win&version=100&user_id=%s&expire=%s&token=%s&type=n",
      info->user_id, info->expire, info->token);
  printf("url is %s: \n", url);
  doRequest(url, &result, GET);
  printf("result %s: \n", result.ptr);
  return 0;

}

int main(int argc, const char *argv[])
{
  struct user_info u_info;
  request_user_info(&u_info, "linq.box@qq.com", "fancylinq");
  request_songs(&u_info, NULL, 0);
  return 0;
}
