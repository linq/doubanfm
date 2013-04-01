#include "common.h"
#include "douban.h"
#include "check_doubanfm.h"

START_TEST(check_request_user_info) {
  user_info *user = request_user_info("linq.box@qq.com", "fancylinq");

  fail_unless(user->user_id != NULL, "request user info failed");
  ck_assert_str_eq("51619168", user->user_id);
  free_user_info(user);
}
END_TEST

Suite *douban_suite() {
  Suite *suite = suite_create("Douban");

  TCase *tc_request_user = tcase_create("request_user_info");
  tcase_add_test(tc_request_user, check_request_user_info);

  suite_add_tcase(suite, tc_request_user);

  return suite;
}
