#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>
#include "hexlib.h"


// I don't know whether a 'single character' means a single 'byte' or an actual readable English
// character so I'll go for the 255 option.


int score_char_against_bytes(int i, int[] byte_arr, int num_bytes) {

  return 1;
}

int main(void) {
  char hexstring[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

  int num_chars = strlen(hexstring);
  int num_bytes = num_chars/2;
  int byte_arr[num_bytes];
  int result[num_bytes];
  char result_string[num_chars];

  int max_score = -1;
  int cur_score = -1;
  char best_char = 0;

  for (int i = 0; i < 256; i++) {
    convert_hex_string_to_byte_array(hexstring, num_chars, byte_arr);
    
    cur_score = score_char_against_bytes(i, byte_arr, num_bytes);

    if( cur_score > max_score) {
      max_score = cur_score;
      best_char = (char) i;
    }
    
  }

  if (num_bytes != convert_hex_string_to_byte_array(hexstring, num_chars, byte_arr)) {
  	return -1;
  }


  for (int i = 0; i < num_bytes; i++) {
  	result[i] = byte_arr1[i] ^ byte_arr2[i];
  }

  // need to deal with strcat here I think.
  char hexcharstr[3] = "";
  for (int i = 0; i < num_bytes; i++) {

    convert_int_to_hex_charstr(result[i],hexcharstr);
    strcat(result_string,hexcharstr);
  }

  printf("num_chars = %d, num_bytes = %d , result = %s\n", num_chars, num_bytes, result_string);

}
