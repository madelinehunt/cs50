#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    while (height < 1 || height >= 9) {
      height = get_int("Height: ");
    };

    for (int i = 0; i < height; i++) {
      int spaces = height - (i+1);
      int hashes = i+1;

      // forwards
      for (int j = 0; j < spaces; j++) {
        printf(" ");
      };
      for (int a = 0; a < hashes; a++) {
        printf("#");
      };

      printf("  ");

      // backwards
      for (int a = 0; a < hashes; a++) {
        printf("#");
      };
      // for (int j = 0; j < spaces; j++) {
      //   printf(" ");
      // };

      printf("\n");
    };
};
