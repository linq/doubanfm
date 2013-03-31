#ifndef HEADER_JSON_H
#define HEADER_JSON_H

#include "http.h"
#include "common.h"

user_info *to_user_info(string *json_string);
song_list *to_song_infos(string *json_string);

void free_user_info(user_info *user);
void free_songs(song_list *songs);

#endif
