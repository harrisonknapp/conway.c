#include <stdio.h> //Duh
#include <time.h> //To randomize seed
#include <stdlib.h> //To randomize
#include <string.h> //Needed as long as I prompt for repeat with string

int gameBoard[10][10];
int nextgameBoard[10][10];
int iterationsCompleted  = 0;

void iterate() {
   //First we update the board
   for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
         int neighbors = 0;
         if (0) {}//Come back here to work with first neighbor
      }
   }

}

int repeatPrompt(int iterationNum) {
   char repeatResponse[50];
   /*
   The array above should not have to take as much memory as it does. However, it's what I've got for now. I don't want the user to have to repeat their input if it's not simply a character  (as it should be simple to quit) but for now I'll have to work with a string as that's what I know that will provide some sort of input freedom.
   Limitations suck, and this one is on my knowledge lol
   */
   printf("Iteration %d: ", iterationNum);
   scanf("%s", repeatResponse);

   if (strcmp("q", repeatResponse) == 0) return 1;
   else return 0;
}

int generateBoard(void) {

   int startNum = 0;
   printf("Begin with how many squares? ");

   scanf("%d", &startNum);
   while (startNum < 1) {
      printf("That is not a valid input. Must be positive integer: ");
      scanf("%d", &startNum);
      //FIXME: Need a fix here so other types of input don't hang up
   }
   
   for (int i = 0; i < 10; ++i) { //Clear the board
      for (int j = 0; j < startNum; ++j) {
         gameBoard[i][j] = 0;
      }
   }

   for (int i = 0; i < startNum;) {
      int iVal = rand() % 10, jVal = rand() % 10;
      switch (gameBoard[iVal][jVal]) {
         case 0:
            gameBoard[iVal][jVal] = 1;
            ++i;
            break;
         case 1:     //This should make it so if a square selected is already generated alive, another square will be generated alive. There should be startNum unique squares that begin alive.
            break; 
      }
   }
   return 0;
}

int main() {

   srand(time(NULL));

   printf("Once the simulation begins, insert anything other than \"q\" to continue.\n");
   generateBoard();
   
   int cont = 0;
   while (!cont) {
      iterate();
      cont = repeatPrompt(iterationsCompleted);
   }
   return 0;
}