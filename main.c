#include <stdio.h>

void display_screen(int arr[9][9]){

   char divider[35] = "+---------+---------+---------+";

   printf("%s\n", divider);
   for (int i = 0; i < 9; i++) {

      for (int j = 0; j < 9; j++) {

         if(j == 0 || j % 3 == 0){printf("|");}
         printf(" %d ", arr[i][j]);
         if((j+1) == 9){printf("|");}
      }
      printf("\n");
      if((i+1) % 3 == 0){printf("%s\n", divider);}
   }
}

int **createPuzzle(){

}

int main(void) {

   // Initialize empty Array
   int my_array[9][9] = {};

   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         my_array[i][j] = 0;
      }
   }

   display_screen(my_array);

   //printf("Press enter to close\n");
   //getchar();

   return 0;
}