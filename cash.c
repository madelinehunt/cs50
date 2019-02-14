#include <cs50.h>
#include <stdio.h>
#include <math.h>

int n_coin_calc(int cash, int coin_value)
{
  int n = floor(cash / coin_value);
  return n;
}

int rmdr_reduce(int cash, int coin_value)
{
  int n = floor(cash / coin_value);
  int leftover_cash = cash - n * coin_value;
  return leftover_cash;
}

int main(void)
{
  float change = 0.0;
  while (change < 0.01 || change > 99999.0) {
    change = get_float("Change owed:  ");
  };

  int cash = round(change*100);
  int n_coins = 0;
  int rmdr = cash;
  int coin_denominations[4] = {25,10,5,1};

  for (int i = 0; i < sizeof(coin_denominations); i++) {
    if (rmdr > 0) {
      int cur_coin = coin_denominations[i];
      n_coins += n_coin_calc(rmdr, cur_coin);
      rmdr = rmdr_reduce(rmdr, cur_coin);
    };
  };
  printf("%i\n", n_coins);
}
