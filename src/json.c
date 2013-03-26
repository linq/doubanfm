#include <stdio.h>
#include <string.h>
#include "http.h"
#include "douban.h"
#include "cJSON.h"

int to_user_info(struct string *json_string, struct user_info *user) {
  cJSON *json;
  json = cJSON_Parse(json_string->ptr);
  printf("json string: %s\n", json_string->ptr);
  char *user_id = cJSON_GetObjectItem(json, "user_id")->valuestring;
  char *token = cJSON_GetObjectItem(json, "token")->valuestring;
  char *expire = cJSON_GetObjectItem(json, "expire")->valuestring;
  printf("id: %s\n", user_id);
  printf("token: %s\n", token);
  printf("expire: %s\n", expire);
  strcpy(user->user_id, user_id);
  strcpy(user->token, token);
  strcpy(user->expire, expire);
  cJSON_Delete(json);

  return 0;
}
