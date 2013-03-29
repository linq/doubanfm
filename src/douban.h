#ifndef HEADER_DOUBAN_H
#define HEADER_DOUBAN_H

#define URL_LEN 150
#define COMMON_LEN 15
#define TITLE_LEN 30
#define ARTIST_LEN 50

typedef struct user_info user_info;
typedef struct song_info song_info;
typedef struct song_list song_list;

// 用户登录信息
struct user_info {
  char user_id[COMMON_LEN];
  char token[COMMON_LEN];
  char expire[COMMON_LEN];
};

// 歌曲信息
struct song_info {
  char title[TITLE_LEN];
  char artist[ARTIST_LEN];
  char url[URL_LEN];
};

struct song_list {
  struct song_info *songs;
  int length;
};

#endif
