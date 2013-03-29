#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "http.h"
#include "json.h"

int request_user_info(user_info *info, char *username, char *passwd) {
  string result;
  char url[URL_LEN];
  sprintf(url, "http://www.douban.com/j/app/login?app_name=radio_desktop_win&version=100&email=%s&password=%s",
      username, passwd);
  request_url(url, POST);
  printf("result is %s: \n", result.ptr);
  to_user_info(&result);
  free(result.ptr);
  return 0;
}

int request_songs(user_info *info, song_info *songs) {
  string result;
  char url[URL_LEN];
  sprintf(url, "http://www.douban.com/j/app/radio/people?app_name=radio_desktop_win&version=100&user_id=%s&expire=%s&token=%s&type=n&channel=0",
      info->user_id, info->expire, info->token);
  request_url(url, GET);
  to_song_infos(&result);
  free(result.ptr);
  return 0;
}

int main(int argc, const char *argv[])
{
  user_info u_info;
  song_info *songs;
  request_user_info(&u_info, "linq.box@qq.com", "fancylinq");
  request_songs(&u_info, songs);
  printf("first one title: %s\n", songs->title);
  int i;
  int size = sizeof(songs) / sizeof(songs[0]);
  for (i = 0; i < size; i++) {
    printf("title: %s\n", (songs+i)->title);
    printf("artist: %s\n", (songs+i)->artist);
    printf("url: %s\n", (songs+i)->url);
  }
  return 0;
}
