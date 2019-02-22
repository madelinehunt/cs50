#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool validate_args(int argc, string argv[]);
int shift(char c);
string encrypt(string msg, string offset_phrase);

// defines the bounds of ASCII uppercase and lowercase
const int u_min = 65;
const int u_max = 90;
const int l_min = 97;
const int l_max = 122;

int main(int argc, string argv[])
{
  if (validate_args(argc, argv)) {
    string msg = get_string("plaintext:  ");
    printf("ciphertext:  ");
    string crypt = encrypt(msg, argv[1]);
    printf("%s\n", crypt);
  } else {
    printf("Usage: ./vigenere key\n"); // fail message
    return 1;
  }
}

bool validate_args(int argc, string argv[])
{
  /* validates the command-line arguments to ensure that only two are passed
  (including program name), and that the second arg is all chars */

  if (argc == 2) {
    string input = argv[1];
    int non_matches = 0;
    for (int i = 0; i < strlen(input); i++) {
      if (!isalpha(input[i])) {
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

int shift(char c)
{
  int numberized = (int) c;
  if (numberized >= u_min && numberized <= u_max) { // if char was uppercase
    numberized -= u_min;
  } else if (numberized >= l_min && numberized <= l_max) { // if char was lowercase
    numberized -= l_min;
  }
  return numberized;
}

string encrypt(string msg, string offset_phrase)
{
  /* this function encrypts the message using the
  offset phrase that was passed in as an arg */

  int offset_len = strlen(offset_phrase);

  /* iterates both over the chars in the string, and over
  the chars in the offset phrase */
  for (int i = 0, j = 0; i < strlen(msg); i++) {
    int current_offset_ix = j % offset_len; // wraparound the offset phrase
    int offset_n = shift(offset_phrase[current_offset_ix]); // convert [A-Z] and [a-z] to [0-25]
    int mod_offset = offset_n % 26;

    int numberized = (int) msg[i]; // casts char to int

    if (numberized >= u_min && numberized <= u_max) { // if char was uppercase
      numberized += mod_offset;
      if (numberized > u_max) { // if numberized overflows, wraparound
        numberized -= 26;
      }
      j++; // only increment the offset index if the char in [A-z]
    } else if (numberized >= l_min && numberized <= l_max) { // if char was lowercase
      numberized += mod_offset;
      if (numberized > l_max) { // if numberized overflows, wraparound
        numberized -= 26;
      }
      j++; // only increment the offset index if the char in [A-z]
    }
    /* implicitly, if the char that is iterated over is not in [A-z],
    it's left alone. This will preserve punctuation, etc. */

    msg[i] = (char) numberized; // converts back to char
  }
  return msg;
}
