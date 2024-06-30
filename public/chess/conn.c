/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 * SPDX-License-Identifier: curl
 *
 ***************************************************************************/
/* <DESC>
 * Very simple HTTP POST
 * </DESC>
 */
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>

void set_bs_FEN(char *FEN) {
  CURL *curl;
  CURLcode res;
  
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://chess-client-c87dfc7085d0.herokuapp.com/bs/set?bs=rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    /* Perform the request, res gets the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
}

const char *get_bs_FEN() {
  CURL *curl;
  CURLcode res;
  
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://chess-client-c87dfc7085d0.herokuapp.com/bs/get");
    /* Perform the request, res gets the return code */
    res = curl_easy_perform(curl);
    
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    /* always cleanup */
    curl_easy_cleanup(curl);
    
    return curl_easy_strerror(res);
  }
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  
  while (1) {
    printf("%s\n", get_bs_FEN());
    sleep(5);
  }
  
  // curl = curl_easy_init();
  // if(curl) {
  //   curl_easy_setopt(curl, CURLOPT_URL, "https://chess-client-c87dfc7085d0.herokuapp.com/bs/set?bs=rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
  //   /* Perform the request, res gets the return code */
  //   res = curl_easy_perform(curl);
  //   /* Check for errors */
  //   if(res != CURLE_OK)
  //     fprintf(stderr, "curl_easy_perform() failed: %s\n",
  //             curl_easy_strerror(res));
 
  //   /* always cleanup */
  //   curl_easy_cleanup(curl);
  // }
  return 0;
}