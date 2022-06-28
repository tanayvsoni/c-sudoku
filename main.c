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

bool in_Row_col(int arr[9][9],int num, int row,int col){
   int i,j;


   //Checks if number is present in row
   for(j = 0; j < 9; j++){
      if(arr[row][j] == num){return true;}
   }

   //Checks if number is present in col
   for(i = 0; i < 9; i++){
      if(arr[i][col] == num){return true;}
   }

   return false;
}

void createPuzzle(){
   int my_array[9][9] = {};
   int num = 0;
   int i,j;

   for(i = 0; i < 9; i++){
      for(j = 0; j < 9; j++){
         num = rand() % 10;
         while(in_Row_col(my_array,num,i,j)){
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