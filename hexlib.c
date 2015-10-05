#include "hexlib.h"

int convert_hex_charpair_to_int(char hcs[]) {

  int hexval = 0;

  hexval = strtol(hcs, NULL, 16);

  return hexval;
}

/* the memory for the string must be passed in */
void convert_int_to_hex_charstr(int hexdigit, char hcs[]) {

  sprintf(hcs, "%02X", hexdigit);

}

/* takes in a string of characters to be interpreted as hex digits and converts pairs
// of them to a byte array. Returns the number of bytes in the byte array. 
// Also takes in a byte array that must be the exactly 1/2 the number of characters in size. */
int convert_hex_string_to_byte_array(const char hex_string[], int num_chars, int byte_array[]) {

  // hex digit string must be even length
  if (num_chars % 2 != 0) {
  	return -1;
  }

  char hexpair[3] = "";
  int char_idx = 0, byte_count = 0;


  // convert the pairs.
  for (char_idx = 0, byte_count = 0; char_idx < num_chars; char_idx+=2, byte_count++) {
    hexpair[0] = hex_string[char_idx];
    hexpair[1] = hex_string[char_idx + 1];
    hexpair[2] = '\0';

    byte_array[byte_count] = convert_hex_charpair_to_int(hexpair);

  }

  for (int i = 0; i <  byte_count; i++) {

    if(byte_array[i]) 
      printf("%x", byte_array[i]);
  }

  
  printf("\n");

  byte_array[byte_count] = '\0';
  return byte_count;
}
