#ifndef HEADER_HTTP_H
#define HEADER_HTTP_H
#include <curl/curl.h>

struct string {
  char *ptr;
  size_t len;
};

enum httpMethod {
  GET, POST
};

// 执行http请求
int doRequest(char *url, struct string *result, enum httpMethod method);
#endif
