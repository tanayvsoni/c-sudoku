#include <stdio.h>

int main()
{

   int i, j;
   int my_array[9][9] = {};

   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         my_array[i][j] = 0;
      }
   }

   int row = sizeof(my_array)/sizeof(my_array[0]);
   int col = sizeof(my_array[0])/sizeof(my_array[0][0]); 

   for (i = 0; i < row; i++) {

      for (j = 0; j < col; j++) {
         printf("%d ", my_array[i][j]);
      }

      printf("\n");
   }

   printf("Hello World");

   return 0;
}