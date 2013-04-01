#ifndef HEADER_DOUBAN_H
#define HEADER_DOUBAN_H

/**
 * 请求用户信息
 * @param username 用户email地址
 * @param passwd 密码
 * @return 用户信息
 */
user_info *request_user_info(char *username, char *passwd);

/**
 * 请求歌曲列表
 * @param info 用户信息
 * @return 歌曲信息列表
 */
song_list *request_songs(user_info *info);

#endif
