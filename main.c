#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void display_screen(int **puzzle){

   char divider[35] = "+---------+---------+---------+";

   printf("%s\n", divider);
   for (int i = 0; i < 9; i++) {

      for (int j = 0; j < 9; j++) {

         if(j == 0 || j % 3 == 0){printf("|");}
         printf(" %d ", puzzle[i][j]);
         if((j+1) == 9){printf("|");}
      }
      printf("\n");
      if((i+1) % 3 == 0){printf("%s\n", divider);}
   }
}

int **createBasePuzzle(){
   int **puzzle;
   puzzle = malloc(sizeof(int*)*9);

   int my_array[9][9] = {0};
   int i,j;

   for(i = 0; i < 9; i++){
      puzzle[i] = malloc(sizeof(int)*9);
      for(j = 0; j < 9; j++){
         puzzle[i][j] = my_array[i][j];
      }
   }
    
   return puzzle;
}

int **generateSudoku(int **puzzle){
   
   srand(time(NULL));
   int i,j;
   int choices[9] = {1,2,3,4,5,6,7,8,9};
   int init_row[9] = {};
   int length_choices = sizeof(choices)/sizeof(int);

   /*Get random row to use to make sudoku*/
   for(i = 0; i < 9; i++){
      int random_index = rand() % length_choices;
      init_row[i] = choices[random_index];

      for(j = random_index; j < length_choices-1; j++){
         choices[j] = choices[j+1];
      }

      length_choices -= 1;

      printf(" %d ", init_row[i]);
   }



   return puzzle;
}

int main(void) {

   int **puzzle = createBasePuzzle();

   puzzle = generateSudoku(puzzle);

   display_screen(puzzle);

   return 0;
}