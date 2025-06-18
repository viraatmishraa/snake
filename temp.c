#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int moveleft();
int moveright();
int moveup();
int movedown();
int printMatrix();
int createRandX();
int createRandY();
int createRandApple();
int noCollosion();

int collosion();
struct node *fetchTail();
// int collosion();

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
    "#                              #",
    "#                              #",
    "#                              #",
    "#Q                             #",
    "#                              #",
    "#                              #",
    "#                              #",
    "#                              #",
    "#                              #",
    "#                             O#",
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

    // printf("\033[H\033[J");
    if (applesOnScreen == 0) {
      createRandApple();
      applesOnScreen++;
    }
    char inp;
    inp = getchar();
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
      ; // flushing output;
    // if(grid[head->yCor][head->xCor-1]=='Q')
    //     {
    //         collosion();
    //     }
    if (inp == 'w' || inp == 'W') {
      node *tempo = head;

      int backupHeadyCor = head->yCor;
      printf("'%c'-next", grid[(head->yCor - 1)][head->xCor]);
      if (grid[head->yCor - 1][head->xCor] == ' ') {
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
        node *temp = head;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        while (temp->next != NULL) {
          printf("[%d,%d]-->", temp->xCor, temp->yCor);
          temp = temp->next;
        }
        tempo->next = NULL;
        tail = tempo;

        //

        grid[--head->yCor][head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';

        printf("\033[H"); // Move cursor to top-left (don't clear screen)
        printMatrix();

      }

      else if (grid[head->yCor - 1][head->xCor] == 'Q') {
        applesOnScreen=0;

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
        grid[head->yCor - 1][head->xCor] = 'O';
        head->yCor--;
        grid[head->yCor][head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';
        printf("\033[H");
        printMatrix();
      }

      if (grid[head->yCor-1][head->xCor] == '#' ||
          grid[head->yCor - 1][head->xCor] == 'O') {
        printf("\033[H");
        printMatrix();
        break;
      }

      // else exit(0);
    }

    /*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

    if (inp == 'a' || inp == 'A') {
      node *tempo = head;

      int backupHeadxCor = head->xCor;
      printf("'%c'-next", grid[(head->yCor - 1)][head->xCor]);
      if (grid[head->yCor][head->xCor - 1] == ' ') {
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
        head->xCor = backupHeadxCor;
        node *temp = head;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        while (temp->next != NULL) {
          printf("[%d,%d]-->", temp->xCor, temp->yCor);
          temp = temp->next;
        }
        tempo->next = NULL;
        tail = tempo;

        //

        grid[head->yCor][--head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';

        printf("\033[H"); // Move cursor to top-left (don't clear screen)
        printMatrix();

      }

      else if (grid[head->yCor][head->xCor - 1] == 'Q') {
        applesOnScreen=0;

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
        grid[head->yCor][head->xCor - 1] = 'O';
        head->xCor--;
        grid[head->yCor][head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';
        printf("\033[H");
        printMatrix();
      }

      if (grid[head->yCor][head->xCor-1] == '#' ||
          grid[head->yCor][head->xCor - 1] == 'O') {
        printf("\033[H");
        printMatrix();
        break;
      }
    }
    // if(inp=='a'||inp=='A')
    // {
    //     tail=fetchTail();
    //     tail->xCor=tail->previous->xCor;
    //     tail->yCor=tail->previous->yCor;

    //     (head->xCor)--;

    //     if(grid[head->yCor][head->xCor]==' ')
    //    { grid[head->yCor][head->xCor]='O';
    //      grid[tail->yCor][tail->xCor]=' ';
    //     printf("\033[H");  // Move cursor to top-left (don't clear screen)
    //     printMatrix();
    //     printf("w,%d,%d,'%c'",head->yCor,head->xCor,grid[head->yCor][head->xCor]);}

    // }
    /*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

    // else exit(0);

    /*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/

    if (inp == 's' || inp == 'S') {
      node *tempo = head;

      int backupHeadyCor = head->yCor;
      printf("'%c'-next", grid[(head->yCor + 1)][head->xCor]);
      if (grid[head->yCor + 1][head->xCor] == ' ') {
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
        node *temp = head;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        while (temp->next != NULL) {
          printf("[%d,%d]-->", temp->xCor, temp->yCor);
          temp = temp->next;
        }
        tempo->next = NULL;
        tail = tempo;

        //

        grid[++head->yCor][head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';

        printf("\033[H"); // Move cursor to top-left (don't clear screen)
        printMatrix();

      }

      else if (grid[head->yCor + 1][head->xCor] == 'Q') {
        applesOnScreen=0;
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
        grid[head->yCor + 1][head->xCor] = 'O';
        head->yCor++;
        grid[head->yCor][head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';
        printf("\033[H");
        printMatrix();
      }

      if (grid[head->yCor+1][head->xCor] == '#' ||
          grid[head->yCor + 1][head->xCor] == 'O') {
        printf("\033[H");
        printMatrix();
        break;
      }
    }

    // else exit(0);

    if (inp == 'd' || inp == 'D') {
      node *tempo = head;

      int backupHeadxCor = head->xCor;
      printf("'%c'-next", grid[(head->yCor - 1)][head->xCor]);
      if (grid[head->yCor][head->xCor + 1] == ' ') {
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
        head->xCor = backupHeadxCor;
        node *temp = head;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        while (temp->next != NULL) {
          printf("[%d,%d]-->", temp->xCor, temp->yCor);
          temp = temp->next;
        }
        tempo->next = NULL;
        tail = tempo;

        //

        grid[head->yCor][++head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';

        printf("\033[H"); // Move cursor to top-left (don't clear screen)
        printMatrix();

      }

      else if (grid[head->yCor][head->xCor + 1] == 'Q') {
        applesOnScreen=0;

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
        grid[head->yCor][head->xCor + 1] = 'O';
        head->xCor++;
        grid[head->yCor][head->xCor] = 'O';
        grid[tail->yCor][tail->xCor] = ' ';
        printf("\033[H");
        printMatrix();
      }

      if (grid[head->yCor][head->xCor+1] == '#' ||
          grid[head->yCor][head->xCor + 1] == 'O') {
        printf("\033[H");
        printMatrix();
        break;
      }
    }

    // printMatrix();
  }
}

int createRandApple() {
  node *backup = head;
mark1:
  int x = createRandX();
  int y = createRandY();
  int valid = 1;
  while (backup->next != NULL) {
    if ((backup->xCor != x || backup->yCor != y) && backup->xCor!=31 && backup->xCor!=0 &&backup->yCor!=0&& backup->yCor!=15)
      backup = backup->next;
    else
      valid = 0;
  }
  if (valid = 1) {
    grid[y][x] = 'Q';
  } else {
    backup = head;
    goto mark1;
  }
}

int createRandX() {
  srand(time(NULL)); // srand is basically feeding a seed value to the pseudo
  // random function rand() on the basis of time
  int random = rand();
  random = (random % 31) + 1;
  return random;
}

int createRandY() {
  srand(time(NULL));
  int random = (rand() % 15) + 1;
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

struct node *fetchTail() {
  node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  return temp;
}

int collosion() {
  node *newNode = (malloc(sizeof(node)));
  node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
}

// collosion function

// swapped xCor with yCor
//