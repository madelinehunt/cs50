#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    while (height < 1 || height >= 9) {
      height = get_int("Please enter the height of the Mario pyramid, between 1 and 8: \n>  ");
      printf("\n");
    };

    for (int i = 0; i < height; i++) {
      int spaces = height - (i+1);
      int hashes = i+1;
      for (int j = 0; j < spaces; j++) {
        printf(" ");
      };
      for (int a = 0; a < hashes; a++) {
        printf("#");
      };
      printf("\n");
    };
    printf("\n\n");
};
