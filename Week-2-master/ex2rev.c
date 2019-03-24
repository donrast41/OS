#include <stdio.h>

int main()
{
   char arr1[100], arr2[100];
   int start, end, counter = 0;

   printf("Input a string\n");
   gets(arr1);

   while (arr1[counter] != '\0')
      counter++;

   end = counter - 1;

   for (start = 0; start < counter; start++) {
      arr2[start] = arr1[end];
      end--;
   }

   arr2[start] = '\0';

   printf("%s\n", arr2);

   return 0;
}
