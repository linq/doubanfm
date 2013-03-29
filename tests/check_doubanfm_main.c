#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "check_doubanfm.h"

int main(int argc, const char *argv[])
{
  int number_failed = 0;
  Suite *suite = http_suite();
  SRunner *runner = srunner_create(suite);
  srunner_add_suite(runner, json_suite());
  srunner_run_all(runner, CK_VERBOSE);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
