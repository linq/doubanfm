#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "json.h"
#include "check_doubanfm.h"

START_TEST(check_to_user_info) {
  string *user_string = malloc(sizeof(string));
  user_string->ptr = read_file("user.json");
  user_string->len = strlen(user_string->ptr);
  user_info *user = to_user_info(user_string);
  fail_unless(user->user_id != NULL, "to user info failed");
  ck_assert_str_eq("51619168", user->user_id);
  ck_assert_str_eq("edbee64aed", user->token);
  ck_assert_str_eq("1380162127", user->expire);
  free_user_info(user);
}
END_TEST

START_TEST(check_to_user_info_null) {
  char *msg = "null string should return null";
  user_info *user = to_user_info(NULL);
  fail_unless(user == NULL, msg);
  free(user);
  string *user_string = malloc(sizeof(string));
  user_string->len = 0;
  user_string->ptr = NULL;
  user = to_user_info(user_string);
  fail_unless(user == NULL, msg);
  free_user_info(user);
}
END_TEST

START_TEST(check_to_song_info) {
  char *json = read_file("songs.json");
  string *song_string = malloc(sizeof(string));
  song_string->len = strlen(json);
  song_string->ptr = json;
  song_list *songs = to_song_infos(song_string);
  song_info first_song = songs->songs[0];
  ck_assert_int_eq(5, songs->length);
  ck_assert_str_eq("Daniel Powter", first_song.artist);
  ck_assert_str_eq("http://mr3.douban.com/201303301916/28b0ac2e5570fa0372eb8e330bb68ec1/view/song/small/p280187.mp3", first_song.url);
  free_songs(songs);
}
END_TEST

START_TEST(check_to_song_info_null) {
  char *msg = "null parameter should return a zero length song list";
  song_list *songs = to_song_infos(NULL);
  fail_unless(songs->length == 0, msg);
  free(songs);
  string *json_str = malloc(sizeof(string));
  json_str->len = 0;
  json_str->ptr = NULL;
  songs = to_song_infos(json_str);
  fail_unless(songs->length == 0, msg);
  free(songs);
}
END_TEST


Suite *json_suite() {
  Suite *suite = suite_create("Json");

  /* to_user_info测试用例 */
  TCase *tc_to_user = tcase_create("to_user");
  tcase_add_test(tc_to_user, check_to_user_info);
  tcase_add_test(tc_to_user, check_to_user_info_null);
  suite_add_tcase(suite, tc_to_user);

  /* to_song_info测试用例 */
  TCase *tc_to_songs = tcase_create("to_songs");
  tcase_add_test(tc_to_songs, check_to_song_info);
  tcase_add_test(tc_to_songs, check_to_song_info_null);
  suite_add_tcase(suite, tc_to_songs);

  return suite;
}
