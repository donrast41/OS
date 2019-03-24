#include <stdio.h>

int main()
{
  int row, count, n, x;

  printf("Enter n\n");
  scanf("%d", &n);

  x = n;
    for (row = 1; row <= n; row++)  // Loop to print rows
  {
    for (count = 1; count < x; count++)  // Loop to print spaces in a row
      printf(" ");
    x--;

    for (count = 1; count <= 2*row - 1; count++) // Loop to print stars in a row
      printf("*");

    printf("\n");
  }

  return 0;
}
