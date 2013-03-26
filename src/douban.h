#ifndef HEADER_DOUBAN_H
#define HEADER_DOUBAN_H

#define URL_LEN 120

// 用户登录信息
struct user_info {
  char user_id[15];
  char token[15];
  char expire[15];
};

// 歌曲信息
struct song_info {
  char title[30];
  char artist[50];
  char url[URL_LEN];
};


#endif