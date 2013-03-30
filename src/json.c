#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "http.h"
#include "douban.h"
#include "cJSON.h"

int to_user_info(string *json_string, user_info *user) {
  cJSON *json;
  json = cJSON_Parse(json_string->ptr);
  char *user_id = cJSON_GetObjectItem(json, "user_id")->valuestring;
  char *token = cJSON_GetObjectItem(json, "token")->valuestring;
  char *expire = cJSON_GetObjectItem(json, "expire")->valuestring;
  strcpy(user->user_id, user_id);
  strcpy(user->token, token);
  strcpy(user->expire, expire);
  cJSON_Delete(json);

  return 0;
}

int to_song_infos(string *json_string, song_info *songs) {
  int i;
  cJSON *array, *json;
  json = cJSON_Parse(json_string->ptr);
  array = cJSON_GetObjectItem(json, "song");
  int size = cJSON_GetArraySize(array);
  songs = (song_info *)malloc(size * sizeof(song_info));
  for (i = 0; i < size; i++) {
    json = cJSON_GetArrayItem(array, i);
    char *title = cJSON_GetObjectItem(json, "title")->valuestring;
    char *artist = cJSON_GetObjectItem(json, "artist")->valuestring;
    char *url = cJSON_GetObjectItem(json, "url")->valuestring;
    strcpy(songs[i].title, title);
    strcpy(songs[i].artist, artist);
    strcpy(songs[i].url, url);
  }

  printf("in jsonc, size is: %u\n", sizeof(songs)/sizeof(songs[0]));
  cJSON_Delete(json);
  return 0;
}
