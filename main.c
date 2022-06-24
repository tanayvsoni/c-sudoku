#include <stdio.h>

#define RED       "\x1b[31m"
#define GREEN     "\x1b[32m"
#define YELLOW    "\x1b[33m"
#define BLUE      "\x1b[34m"
#define MAGENTA   "\x1b[35m"
#define CYAN      "\x1b[36m"
#define RESET     "\x1b[0m"


int main()
{

   int i, j;
   int my_array[9][9] = {};

   for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
         my_array[i][j] = 0;
      }
   }

   for (i = 0; i < 9; i++) {

      for (j = 0; j < 9; j++) {

         if(i<3 && j<3){
            printf(RED "%d" RESET, my_array[i][j]);
         }
         else{printf("%d", my_array[i][j]);}
         
      }
      printf("\n");
   }

   printf("Press enter to close\n");
   getchar();

   return 0;
}