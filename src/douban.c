#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "douban.h"
#include "http.h"
#include "json.h"

static char *user_url = "http://www.douban.com/j/app/login?app_name=radio_desktop_win&version=100&email=%s&password=%s";
static char *song_url = "http://www.douban.com/j/app/radio/people?app_name=radio_desktop_win&version=100&user_id=%s&expire=%s&token=%s&type=n&channel=0";

user_info *request_user_info(char *username, char *passwd) {
  char url[URL_LEN];
  sprintf(url, user_url, username, passwd);
  string *json_string = request_url(url, POST);
  user_info *result = to_user_info(json_string);
  free_string(json_string);
  return result;
}

song_list *request_songs(user_info *info) {
  char url[URL_LEN];
  sprintf(url, song_url, info->user_id, info->expire, info->token);
  string *json_string = request_url(url, GET);
  song_list *result = to_song_infos(json_string);
  free_string(json_string);
  return result;
}
