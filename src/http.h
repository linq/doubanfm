#ifndef HEADER_HTTP_H
#define HEADER_HTTP_H
#include <curl/curl.h>

typedef struct string String;

struct string {
  char *ptr;
  size_t len;
};

enum httpMethod {
  GET, POST
};

// 执行http请求
string *request_url(char *url, enum httpMethod method);
#endif
