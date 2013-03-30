#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "http.h"

string *init_string() {
  string *s = malloc(sizeof(string));
  if (s == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->len = 0;
  s->ptr = NULL;

  return s;
}

static size_t writefunc(void *ptr, size_t size, size_t nmemb, string *s)
{
  size_t new_len = s->len + size*nmemb;
  s->ptr = realloc(s->ptr, new_len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr+s->len, ptr, size*nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}

string *request_url(char *url, enum httpMethod method) {
  CURL *curl;
  CURLcode res;
  string *result;

  curl = curl_easy_init();
  if(curl) {
    result = init_string();

    curl_easy_setopt(curl, CURLOPT_URL, url);
    if (method == POST) {
      char *postfield = strstr(url, "?") + 1;
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postfield);
    }
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, result);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "doget error: %s\n", curl_easy_strerror(res));
      return result;
    }

    /* always cleanup */
    curl_easy_cleanup(curl);
  }

  return result;
}

/*
int main(int argc, const char *argv[])
{
  char *url = "www.baidu.com";
  string *result = request_url(url, GET);
  printf("result is %s\n", result->ptr);
  return 0;
}
*/
