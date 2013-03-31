#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cJSON.h"
#include "json.h"

user_info *to_user_info(string *json_string) {
  if (json_string == NULL || json_string->len == 0 || json_string->ptr == NULL)
    return NULL;

  user_info *user = malloc(sizeof(user_info));
  memset(user, '\0', sizeof(user_info));
  cJSON *json = cJSON_Parse(json_string->ptr);
  char *user_id = cJSON_GetObjectItem(json, "user_id")->valuestring;
  char *token = cJSON_GetObjectItem(json, "token")->valuestring;
  char *expire = cJSON_GetObjectItem(json, "expire")->valuestring;
  strcpy(user->user_id, user_id);
  strcpy(user->token, token);
  strcpy(user->expire, expire);
  cJSON_Delete(json);

  return user;
}

song_list *to_song_infos(string *json_string) {

  cJSON *array, *json;
  int i;
  song_list *result;
  song_info *songs;

  result = malloc(sizeof(song_list));
  if (json_string == NULL || json_string->len == 0 || json_string->ptr == NULL) {
    result->length = 0;
    result->songs = NULL;
    return result;
  }

  json = cJSON_Parse(json_string->ptr);
  array = cJSON_GetObjectItem(json, "song");
  int size = cJSON_GetArraySize(array);
  result->length = size;
  songs = malloc(size * sizeof(song_info));
  for (i = 0; i < size; i++) {
    json = cJSON_GetArrayItem(array, i);
    char *title = cJSON_GetObjectItem(json, "title")->valuestring;
    char *artist = cJSON_GetObjectItem(json, "artist")->valuestring;
    char *url = cJSON_GetObjectItem(json, "url")->valuestring;
    strcpy(songs[i].title, title);
    strcpy(songs[i].artist, artist);
    strcpy(songs[i].url, url);
  }
  result->songs = songs;

  cJSON_Delete(json);
  return result;
}

void free_user_info(user_info *user) {
  free(user);
}

void free_songs(song_list *songs) {
  free(songs->songs);
  free(songs);
}
