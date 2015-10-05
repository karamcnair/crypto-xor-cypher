#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>
#include "hexlib.h"


// I don't know whether a 'single character' means a single 'byte' or an actual readable English
// character so I'll go for the 255 option.


float score_char_against_bytes(int test_char, int byte_arr[], int num_bytes) {

  // rather than doing a FULL analysis of english chars, I'll pick the top 5 & see how this scores.
  // going to use the raw %s in this as score: http://scottbryce.com/cryptograms/stats.htm although I'm suspicious 
  // that would be too strong.

  // brute forcing to start.
  float score = 0;

  // printable ascii is between 32 and 126. Let's give that 1 pt.
  // unprintable chars (outside that) should get a -1.

  for (int i = 0; i < num_bytes; i++) {

    char decoded_char = (char) (test_char ^ byte_arr[i]);

    // printable characters better than unprintable
    if (decoded_char >= 32 && decoded_char <= 126)
      score += .1;
    else
      score -= .1;

    // english letters better than special chars
    if ((decoded_char >= 'a' && decoded_char <= 'z') || (decoded_char >= 'A' && decoded_char <= 'Z') || decoded_char == ' ')
      score += .1;
    else
      score -= .1;

    switch (decoded_char) {
      case 'e':
      case 'E':
        score += 1.2;
        break;
      case 'T':
      case 't':
        score += .9;
        break;
      case 'a':
      case 'A':
        score += .8;
        break;
      case 'o':
      case 'O':
      case 'i':
      case 'I':
      case 'n':
      case 'N':
        score += .7;
        break;
      default:
        score += .1;
    }
  }
  return score;
}

int main(void) {
  char hexstring[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

  int num_chars = strlen(hexstring);
  int num_bytes = num_chars/2;
  int byte_arr[num_bytes];

  float max_score = -1;
  float cur_score = -1;
  char best_char = 0;

  for (int i = 0; i < 255; i++) {
   convert_hex_string_to_byte_array(hexstring, num_chars, byte_arr);
    
   cur_score = score_char_against_bytes(i, byte_arr, num_bytes);

    if( cur_score > max_score) {
      max_score = cur_score;
      best_char = (char) i;
    }

    printf("score: %f testing %2x : ", cur_score, i);

    for(int j = 0; j < num_bytes; j++) {
      printf("%c",(char) byte_arr[j]^i);
    }
    printf("\n");

  }
  
  printf("best char = %2x, max score = %f \n", best_char, max_score);

  for(int j = 0; j < num_bytes; j++) {
      printf("%c",(char) byte_arr[j]^best_char);
    }
    printf("\n");
  // if (num_bytes != convert_hex_string_to_byte_array(hexstring, num_chars, byte_arr)) {
  // 	return -1;
  // }
  return 0;
  

}
