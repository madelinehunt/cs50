#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_args(int argc, string argv[]);
string encrypt(string msg, int offset);

int main(int argc, string argv[])
{
  if (validate_args(argc, argv)) {
    int n = atoi(argv[1]);
    string msg = get_string("plaintext:  ");
    printf("ciphertext:  ");
    string crypt = encrypt(msg, n);
    printf("%s\n", crypt);
  } else {
    printf("Usage: ./caesar key\n"); // fail message
    return 1;
  }
}

bool validate_args(int argc, string argv[])
{
  /* validates the command-line arguments to ensure that only two are passed
  (including program name), and that the second arg can be cast to int */

  if (argc == 2) {
    string input = argv[1];
    int non_matches = 0;
    for (int i = 0; i < strlen(input); i++) {
      if (!isdigit(input[i])) {
        non_matches++;
      }
    }
    if (non_matches == 0) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

string encrypt(string msg, int offset)
{
  /* this function encrypts the message using the
  offset that was passed in as an arg */

  // defines the bounds of ASCII uppercase and lowercase
  int u_min = 65;
  int u_max = 90;
  int l_min = 97;
  int l_max = 122;

  int mod_offset = offset % 26;

  // iterates over the chars in the string
  for (int i = 0; i < strlen(msg); i++) {
    int numberized = (int) msg[i]; // casts char to int

    if (numberized >= u_min && numberized <= u_max) { // if char was uppercase
      numberized += mod_offset;
      if (numberized > u_max) { // if numberized overflows, wraparound
        numberized -= 26;
      }
    } else if (numberized >= l_min && numberized <= l_max) { // if char was lowercase
      numberized += mod_offset;
      if (numberized > l_max) { // if numberized overflows, wraparound
        numberized -= 26;
      }
    }
    /* implicitly, if the char that is iterated over is not in [A-z],
    it's left alone. This will preserve punctuation, etc. */

    msg[i] = (char) numberized; // converts back to char
  }
  return msg;
}
