#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int move();
int printMatrix();
int createRand(int);
int createRandApple();


typedef struct node {
  struct node *previous;
  struct node *next;
  int xCor;
  int yCor;
} node;
// globally cant be declared as, function calls aint allowed here
//  node * head = malloc(sizeof(node));
//  node * tail = malloc(sizeof(node));
int len = 1;
node *head = NULL;
node *tail = NULL; // declared globally so accessible everywhere

char grid[16][32] = {
    "################################",
    "#                              #",
    "#                              #",
    "#                              #",
    "#                              #",
    "#                             Q#",
    "#                             Q#",
    "#                             Q#",
    "#                             Q#",
    "#                             Q#",
    "#                             Q#",
    "#                             Q#",
    "#                             Q#",
    "#                              #",
    "#                              #",
    "################################"};

int main() {
  int applesOnScreen = 0;
  head = malloc(sizeof(node)); // initiallized in main
  tail = malloc(sizeof(node));
  head->previous = NULL;
  tail->next = NULL;
  head->xCor = 30;
  head->yCor = 13;
  tail->xCor = 30;
  tail->yCor = 14;
  tail->previous = head;
  head->next = tail;

  while (1) {
    if (applesOnScreen == 0) {
      createRandApple();
      applesOnScreen++;
    }
    char inp,prohibitted;
    inp = getchar();
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); // flushing output;
    if(prohibitted==inp){prohibitted='0';continue;}

    if (inp == 'w' || inp == 'W') {
       int cont=move(&applesOnScreen,-1,0);
       if(cont==0)break;   prohibitted='s'; }

    if (inp == 'a' || inp == 'A') {
       int cont=move(&applesOnScreen,0,-1);
       if(cont==0)break;   prohibitted='d'; }

    if (inp == 's' || inp == 'S') {
       int cont=move(&applesOnScreen,1,0);
       if(cont==0)break;  prohibitted='w';  }

    if (inp == 'd' || inp == 'D') {
       int cont=move(&applesOnScreen,0,1);
       if(cont==0)break;  prohibitted='a';  }
    }}// these brackets were not written while upgrading(making code smaller by using functions) which cause "main not found error"
    

int createRandApple() {
  node *backup = head;
  int x = createRand(30);
  int y = createRandY(14);
  int valid;
  mark1:
  
    valid = 1;
    while (backup->next != NULL) 
    {
      if (backup->xCor != x && backup->yCor != y) 
        backup = backup->next;

      else
        valid = 0;
        break;
    }
  
  
  if (valid == 1) 
  
    grid[y][x] = 'Q';
   else 
  {
    backup = head;
    goto mark1;
  }
}

int createRand(int To)
 {
  srand(time(NULL)); // srand is basically feeding a seed value to the pseudo
  // random function rand() on the basis of time
  int random = rand();
  random = (random % To) + 1;
  return random;
}

int printMatrix() {

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 32; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

int move(int* applesOnScreen,int updationY,int updationX)
{
     if (grid[head->yCor+updationY][head->xCor+updationX] == '#' ||
            grid[head->yCor+updationY][head->xCor+updationX] == 'O') {
          printf("\033[H");
          printMatrix();
          return 0;
        }
        node *tempo = head;
        
        int backupHeadyCor = head->yCor;
        int backupHeadxCor = head->xCor;
        // printf("'%c'-next", grid[(head->yCor )][head->xCor]);
      if (grid[head->yCor +updationY][head->xCor+updationX] == ' ') {
        int X = head->xCor;
        int Y = head->yCor;

        tempo = head;

        while (tempo->next != NULL) {

          int tempX = tempo->next->xCor;
          int tempY = tempo->next->yCor;

          tempo->next->xCor = X;
          tempo->next->yCor = Y;

          X = tempX;
          Y = tempY;

          tempo = tempo->next;
        }
        // collusion me neeche wale part ka kuch toh hoga
        head->yCor = backupHeadyCor;
        head->xCor = backupHeadxCor;
        node *temp = head;
        while (temp->next != NULL) {
          temp = temp->next;
        }
        tempo->next = NULL;
        tail = tempo;

        //
        head->yCor+=+updationY;
        head->xCor+=+updationX;
        grid[head->yCor][head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';

        printf("\033[H"); // Move cursor to top-left (don't clear screen)
        printMatrix();

      }

      else if (grid[head->yCor +updationY][head->xCor+updationX] == 'Q') {
        *applesOnScreen=0;

        int X = head->xCor, Y = head->yCor;
        int swapper;
        node *newNode = malloc(sizeof(node));
        newNode->next = head;
        head->previous = newNode;
        newNode->previous = NULL;
        newNode->xCor = head->xCor;
        newNode->yCor = head->yCor;
        head = newNode;

        // newNode=head;
        // head=newNode->next;
        grid[head->yCor +updationY][head->xCor+updationX] = 'O';
          
        head->yCor+=+updationY;
        head->xCor+=+updationX;
        
        grid[head->yCor][head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';
        printf("\033[H");
        printMatrix();
      }
}



/* 
1.generating snake and apple without adding into the default grid
2. apple generation shouldnt be on border and on the snake  
3. no reverse self collission
4. (ops)graphical terminal protocol - kitty
5. remove randx and randy func
*/
//