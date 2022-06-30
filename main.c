#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void swap(int **puzzle){
   srand(time(NULL));
   int swap[2] = {0};
   
   for(int i = 0; i < 3; i++){
      int upper = (i*3+3);
      int lower = i*3;

      while(swap[0] == swap[1]){
         swap[0] = (rand() % (upper - lower + 1)) + lower;
         swap[1] = (rand() % (upper - lower + 1)) + lower;
      }

      int *temp = puzzle[swap[0]];
      puzzle[swap[0]] = puzzle[swap[1]];
      puzzle[swap[1]] = temp;

      memset(swap,0,sizeof(swap));
   }
}

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

void generateSudoku(int **puzzle){
   srand(time(NULL));

   int *arr = malloc(sizeof(int)*9);

   int choices[9] = {1,2,3,4,5,6,7,8,9};
   int length_choices = sizeof(choices)/sizeof(int);

   /*Get a array with random ints to use to make sudoku*/
   for(int i = 0; i < 9; i++){
      int random_index = rand() % length_choices;
      arr[i] = choices[random_index];

      for(int j = random_index; j < length_choices-1; j++){
         choices[j] = choices[j+1];
      }

      length_choices -= 1;
   }

   /* Fill puzzle with rotated values of array*/
   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         puzzle[i][j] = arr[j];
      }
      rotate_arr(arr, 3);
   }

   swap(puzzle);


}

int main(void) {

   int **puzzle = createBasePuzzle();

   generateSudoku(puzzle);

   display_screen(puzzle);

   return 0;
}