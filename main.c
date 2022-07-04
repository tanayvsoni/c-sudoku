#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void rotate_arr(int *arr, int rotate_amount){
   int length_arr = 9;

   for(int i = 0; i < rotate_amount; i++){
      int j,last;

      last = arr[length_arr-1];

      for(j = length_arr-1; j > 0; j--){
         arr[j] = arr[j-1];
      }

      arr[0] = last;
   }

}

void swap_col(int **puzzle){
   int swap[2] = {0};

   // Swap Cols
   for(int k = 0; k < 3; k++){
      for(int swaps = 0; swaps < 3; swaps++){
         while(swap[0] == swap[1]){
            swap[0] = (rand() % 3) + k*3;
            swap[1] = (rand() % 3) + k*3;
         }

         for(int i = 0; i < 9; i++){
            int temp = puzzle[i][swap[0]];
            puzzle[i][swap[0]] = puzzle[i][swap[1]];;
            puzzle[i][swap[1]] = temp;
         }
         memset(swap,0,sizeof(swap)); 
      }  
   }
}

void swap_rows(int **puzzle){
   int swap[2] = {0};

   // Swap Rows
   for(int k = 0; k < 3; k++){
      for(int swaps = 0; swaps < 3; swaps++){

         while(swap[0] == swap[1]){
            swap[0] = (rand() % 3) + k*3;
            swap[1] = (rand() % 3) + k*3;
         }

         int *temp = puzzle[swap[0]];
         puzzle[swap[0]] = puzzle[swap[1]];
         puzzle[swap[1]] = temp;

         memset(swap,0,sizeof(swap)); 
      }
   }
}

void swap_rowBlocks(int **puzzle){
   int swap[2] = {0};

   // Swap Row Blocks
   while(swap[0] == swap[1]){
         swap[0] = rand() % 3;
         swap[1] = rand() % 3;
   }

   int **temp = malloc(sizeof(int*)*3);

   int swap0_i = swap[0]*3;
   int swap1_i = swap[1]*3;

   for(int i = 0; i < 3; i++){
      temp[i] = malloc(sizeof(int)*9);
      for(int j = 0; j < 9; j++){
         temp[i][j] = puzzle[swap0_i][j];
         puzzle[swap0_i][j] = puzzle[swap1_i][j];
         puzzle[swap1_i][j] = temp[i][j];
      }
      swap0_i++;
      swap1_i++;
   }
}

void swap_colBlocks(int **puzzle){
   
}

void generateSudoku(int **puzzle){

   int *arr = malloc(sizeof(int)*9);

   int choices[9] = {1,2,3,4,5,6,7,8,9};
   int length_choices = sizeof(choices)/sizeof(int);

   // Get a array with random ints to use to make sudoku
   for(int i = 0; i < 9; i++){
      int random_index = rand() % length_choices;
      arr[i] = choices[random_index];

      for(int j = random_index; j < length_choices-1; j++){
         choices[j] = choices[j+1];
      }
      length_choices -= 1;
   }

   int *last_arr = arr;

   // Fill puzzle with rotated values of array
   for(int k = 0; k < 3; k++){  
      for(int i = k*3; i < (k*3+3); i++){
         for(int j = 0; j < 9; j++){
            puzzle[i][j] = arr[j];
         }
         rotate_arr(arr, 3);
      }
      rotate_arr(last_arr,1);
   }
   
   swap_rows(puzzle);
   swap_col(puzzle);
   swap_rowBlocks(puzzle);
   
   // Clear numbers to create the puzzle
   /*for(int amount_num = 81; amount_num > 30; amount_num--){
      int rand_row = rand() % 9;
      int rand_col = rand() % 9;

      puzzle[rand_row][rand_col] = 0;
   }*/

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

int main(void) {
   srand(time(NULL));

   int **puzzle = createBasePuzzle();

   generateSudoku(puzzle);

   display_screen(puzzle);

   return 0;
}