#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>
#include "json.h"
#include "check_doubanfm.h"

START_TEST(check_to_user_info) {
  string *user_string = malloc(sizeof(string));
  user_string->ptr = "{\"user_id\":\"51619168\",\"err\":\"ok\",\"token\":\"edbee64aed\",\"expire\":\"1380162127\",\"r\":0,\"user_name\":\"LinQ\",\"email\":\"linq.box@qq.com\"}";
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
  user_info *user = to_user_info(NULL);
  fail_unless(user == NULL, "null string should return null");
  free(user);
  string *user_string = malloc(sizeof(string));
  user_string->len = 0;
  user_string->ptr = NULL;
  user = to_user_info(user_string);
  fail_unless(user == NULL, "should return null");
  free_user_info(user);
}
END_TEST

START_TEST(check_to_song_info) {
  string *song_string = malloc(sizeof(string));
  song_list songs = to_song_infos(song_string);
  ck_assert_int_eq(5, songs->length);
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
  suite_add_tcase(suite, tc_to_songs);

  return suite;
}
