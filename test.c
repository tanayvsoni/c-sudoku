#include <stdio.h>

int main()
{

   int i, j;
   int my_array[3][5] = {
      {1,2,3,4,5},
      {1,2,3,4,5},
      {1,2,3,4,5},
   };

   int row = sizeof(my_array)/sizeof(my_array[0]);
   int col = sizeof(my_array[0])/sizeof(my_array[0][0]); 

   for (i = 0; i < row; i++) {

      for (j = 0; j < col; j++) {
         printf("%d ", my_array[i][j]);
      }

      printf("\n");
   }

   int age;
   scanf("%d",age);

   printf("Hello World");
   
   return 0;
}