#include <stdio.h>
#include <check.h>
#include <stdlib.h>
#include "http.h"
#include "check_doubanfm.h"

START_TEST(request_url_test) {
  char *url = "www.cnbeta.com";
  string *result = request_url(url, GET);
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
