#include <stdio.h>      /* printf */
#include <stdlib.h>


int convert_hex_char_to_int(char hc);
int convert_hex_string_to_byte_array(const char hex_string[], int num_chars, int byte_array[]);
void convert_int_to_hex_charstr(int hexdigit, char hcs[]);
