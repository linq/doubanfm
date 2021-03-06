#ifndef HEADER_HTTP_H
#define HEADER_HTTP_H
#include <curl/curl.h>

typedef struct string string;

struct string {
  char *ptr;
  size_t len;
};

enum httpMethod {
  GET, POST
};

// 执行http请求
string *request_url(char *url, enum httpMethod method);
void free_string(string *str);
#endif
