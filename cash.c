#include <cs50.h>
#include <stdio.h>
#include <math.h>

int n_coin_calc(int cash, int coin_value)
{
  int n = floor(cash / coin_value);
  printf("n: %i\n", n);
  float leftover_cash = cash - n * coin_value;
  printf("leftover_cash: %f\n", leftover_cash);
  return n;
}

int cash_reduce(int cash, int coin_value)
{
  int n = floor(cash / coin_value);
  printf("n: %i\n", n);
  float leftover_cash = cash - n * coin_value;
  printf("leftover_cash: %f\n", leftover_cash);
  return leftover_cash;
}

int main(void)
{
  float change = 0.0;
  while (change < 0.01) {
    change = get_float("Change owed: \n>  ");
    printf("\n");
  };

  // int dollars = (int)change;
  // int coins = round((change - dollars)*100);
  // // coins = (int)coins;
  // printf("dollars: %i\n", dollars);
  // printf("coins: %i\n", coins);

  int cash = round(change*100);
  printf("cash: %i\n", cash);

  int n_coins = 0;
  int coin_denominations = [25,10,5,1];


  int check25 = n_coin_calc(cash, 25);
  int check10 = n_coin_calc(cash, 10);
  int check5 = n_coin_calc(cash, 5);
  int check1 = n_coin_calc(cash, 1);

  // int n_quarters = floor(cash / 0.25);
  // printf("n_quarters: %i\n", n_quarters);
  // n_coins += n_quarters;
  // printf("n_coins: %i\n", n_coins);
  // float leftover_cash = cash - n_quarters * 0.25;
  // printf("leftover_cash: %f\n", leftover_cash);

  // int n_quarters = floor(cash / 0.25);
  // printf("n_quarters: %i\n", n_quarters);
  // n_coins += n_quarters;
  // printf("n_coins: %i\n", n_coins);
  // float leftover_cash = cash - n_quarters * 0.25;
  // printf("leftover_cash: %f\n", leftover_cash);

}
