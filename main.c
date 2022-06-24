#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool not_inCol(int num, int arr[9][9], int col){
   for(int i = 0; i < 9; i++){
      if(arr[i][col] == num){return false;}
   }
   return true;
}

bool not_inRow(int num, int arr[9][9], int row){
   for(int j = 0; j < 9; j++){
      if(arr[row][j] == num){return false;}
   }
   return true;
}

void createPuzzle(){
   int my_array[9][9] = {};
   int num = 0;
   int i,j;
   bool condiation = true;

   for(i = 0; i < 9; i++){
      for(j = 0; j < 9; j++){
         while(condiation){
            if(not_inCol(num, my_array, j) && not_inRow(num,my_array,i)){
               condiation = false;
            }
            num = rand() % 10;
         }
         my_array[i][j] = num;
      }
   }

   display_screen(my_array);
}

int main(void) {

   createPuzzle();

   //printf("Press enter to close\n");
   //getchar();

   return 0;
}