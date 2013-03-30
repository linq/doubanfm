#include <stdio.h>
#include <check.h>
#include <stdlib.h>
#include "http.h"

START_TEST(request_url_test) {
  char *url = "www.baidu.com";
  String *result = request_url(url, GET);
  fail_unless(result->len != 0, "do request failed");
}
END_TEST

Suite *http_suite(void) {
  Suite *suite = suite_create("Http");

  TCase *tc_request_url = tcase_create("Request");
  tcase_add_test(tc_request_url, request_url_test);
  suite_add_tcase(suite, tc_request_url);

  return suite;
}

int main(void)
{
  
  int number_failed = 0;
  Suite *suite = http_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
