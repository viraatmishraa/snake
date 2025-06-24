#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <unistd.h>
//
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
int move();
int printMatrix();
int createRand(int);
int createRandApple();
void printsolutation();
char function();
void enableRawMode();
void disableRawMode();

int n = 0;

struct termios orig_termios;
  void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
  }
void enableRawMode(){

            tcgetattr(STDIN_FILENO, &orig_termios);
            atexit(disableRawMode);
                    struct termios raw=orig_termios;
                raw.c_lflag &= ~(ECHO | ICANON);//
                        tcsetattr(STDIN_FILENO,TCSAFLUSH,&raw);
}


//

typedef struct node {
  struct node *previous;
  struct node *next;
  int xCor;
  int yCor;
} node;
// globally cant be declared as, function calls aint allowed here
//  node * head = malloc(sizeof(node));
//  node * tail = malloc(sizeof(node));
int len = 1, game_mode_flag = 0;
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
 "#                              #",
 "#                              #",
 "#                              #",
 "#                              #",
 "#                              #",
 "#                              #",
 "#                              #",
 "################################"},first_c='\0',newInp,lastInp='w';
  
 
 //select block ends
 
 int main() {

  //fcntl block -- library needed<fnctl.h>
  int flags =fcntl(STDIN_FILENO,F_GETFL);
  fcntl(STDIN_FILENO, F_SETFL,flags| O_NONBLOCK);
  int readReturnFlag=0;
  //fcntl block ends
  
  
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
  printf("\n\n*******press w to start: normal mode *********");
  printf("\n\n*******press a to start: speedrun mode *******");
  
  //select block necessary declarations
  fd_set readfds;         // ✅ Declare this
  struct timeval timeout;
  // modification of timeval for fractional time
  
  char buf[100];
  //select block ends
  
  
  // enableRawMode();
  //
  while (1) {


    fflush(stdout);
    game_mode_flag++;
    
    if (applesOnScreen == 0) {
      createRandApple();
      applesOnScreen++;
    }
    enableRawMode();
    


    //select block  -- library needed- <sys/select.h>


    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    
    timeout.tv_sec = 0;
    timeout.tv_usec = 500000;

    int ready = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    //select block ends
    
       
    
     if (ready > 0 && FD_ISSET(STDIN_FILENO, &readfds)) {
        readReturnFlag = read(STDIN_FILENO, buf, sizeof(buf));}//input

      
      
      if (game_mode_flag == 1)
        first_c = newInp;
      
      //
      // int ch;
      // while ((ch = getchar()) != '\n' && ch != EOF); // flushing output;
      // if(len==1)
      // {first_c=inp;}
      
      // if(first_c!='\0'){}
      // else
      // lastInp=newInp;
      
      
      
      
      if(readReturnFlag>0)
      { newInp=buf[0];
        lastInp=newInp;
      readReturnFlag=-12;


     if (newInp == 'w' || newInp == 'W') {
      int cont = move(&applesOnScreen, -1, 0);
      if (cont == 0)
        break;
      if (cont == 2)
        continue;
    }

    if (newInp == 'a' || newInp == 'A') {
      int cont = move(&applesOnScreen, 0, -1);
      if (cont == 0)
        break;
      if (cont == 2)
        continue;
    }

    if (newInp == 's' || newInp == 'S') {
      int cont = move(&applesOnScreen, 1, 0);
      if (cont == 0)
        break;
      if (cont == 2)
        continue;
    }

    if (newInp == 'd' || newInp == 'D') {
      int cont = move(&applesOnScreen, 0, 1);
      if (cont == 0)
        break;
      if (cont == 2)
        continue;
    }
    printf("\033[H");

    printMatrix();
  }

  else if(readReturnFlag==-12)
  {
    newInp=lastInp;

     if (newInp == 'w' || newInp == 'W') {
      int cont = move(&applesOnScreen, -1, 0);
      if (cont == 0)
        break;
      if (cont == 2)
        continue;
    }

    if (newInp == 'a' || newInp == 'A') {
      int cont = move(&applesOnScreen, 0, -1);
      if (cont == 0)
        break;
      if (cont == 2)
        continue;
    }

    if (newInp == 's' || newInp == 'S') {
      int cont = move(&applesOnScreen, 1, 0);
      if (cont == 0)
        break;
      if (cont == 2)
        continue;
    }

    if (newInp == 'd' || newInp == 'D') {
      int cont = move(&applesOnScreen, 0, 1);
      if (cont == 0)
        break;
      if (cont == 2)
        continue;

    }
    printf("\033[H");

    printMatrix();

  }
}
}


int createRandApple() {
  node *backup = head;
mark1:
  int x = createRand(30);
  int y = createRand(14);
  int valid;
  if (x != 31 && x != 0 && y != 0 && y != 15) {
    valid = 1;
    while (backup->next != NULL) {
      if (!(backup->xCor == x && backup->yCor == y)) {
        backup = backup->next;
        continue;
      } else {
        valid = 0;
        break;
      }
    }
  } else
    valid = 0;

  if (valid == 1)

    grid[y][x] = 'Q';
  else {
    backup = head;
    goto mark1;
  }
  if (!(len == 1)) {
    printf("\033[H");
    printMatrix();
  }
}




int createRand(int num) {
  int random;
  if (first_c == 'w') {
    srand(time(NULL));

    random = rand();
    random = (random % num) + 1;
  } // srand is basically feeding a seed value to the pseudo
  // // random function rand() on the basis of time
  else if (first_c == 'a') {
    n++;
    srand(len + n);
  }
  //   ///this line makes this version of snake , speedrunable, as its
  //   predictable with exactlty same pattern everytime

  random = rand();
  random = (random % num) + 1;

  return random;
}

int printMatrix() {
    // usleep(1000000);

  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 32; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
  printf("          ****your current score=%d*****", len);
}

int move(int *applesOnScreen, int updationY, int updationX) {
  if ((head->yCor + updationY) == (head->next->yCor) &&
      (head->xCor + updationX) == (head->next->xCor)) {
    return 2;
  }
  if (grid[head->yCor + updationY][head->xCor + updationX] == '#' ||
      grid[head->yCor + updationY][head->xCor + updationX] == 'O') {
    printf("\033[H");
    printMatrix();
    printsolutation();
    return 0;
  }
  node *tempo = head;

  int backupHeadyCor = head->yCor;
  int backupHeadxCor = head->xCor;
  if (grid[head->yCor + updationY][head->xCor + updationX] == ' ') {
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
    head->yCor = backupHeadyCor;
    head->xCor = backupHeadxCor;
    node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    tempo->next = NULL;
    tail = tempo;

    head->yCor += +updationY;
    head->xCor += +updationX;
    grid[head->yCor][head->xCor] = 'O';
    grid[tail->yCor][tail->xCor] = ' ';

    printf("\033[H"); // Move cursor to top-left (don't clear screen)
    printMatrix();

  }

  else if (grid[head->yCor + updationY][head->xCor + updationX] == 'Q') {
    *applesOnScreen = 0;
    len++;
    int X = head->xCor, Y = head->yCor;
    int swapper;
    node *newNode = malloc(sizeof(node));
    newNode->next = head;
    head->previous = newNode;
    newNode->previous = NULL;
    newNode->xCor = head->xCor;
    newNode->yCor = head->yCor;
    head = newNode;
    grid[head->yCor + updationY][head->xCor + updationX] = 'O';
    head->yCor += +updationY;
    head->xCor += +updationX;
    grid[head->yCor][head->xCor] = 'O';
    grid[tail->yCor][tail->xCor] = ' ';
    printf("\033[H");
    printMatrix();
  }
}

void printsolutation() {
  printf("\n\n\n"
         "  ____       _     __    __ __________ \n"
         " / ___|     / \\    | \\  / | |  ______|\n"
         "| |  _     / _ \\   | |\\/| | | |_____\n"
         "| |_| |   / ___ \\  | |  | | | | ____| \n"
         " \\____|  /_/   \\_\\ |_|  |_| |________| \n"
         "\n"
         "  ____   __      __ ______  __ ___ \n"
         " / __ \\  \\ \\    / /|  ____| |  __ \\\n"
         "| |  | |  \\ \\  / / | |__    | |__) |\n"
         "| |  | |   \\ \\/ /  |  __|   |  _  / \n"
         "| |__| |    \\  /   | |____  | | \\ \\ \n"
         " \\____/      \\/    |______| |_|  \\_\\\n");
}

/*
1.generating snake and apple without adding into the default grid
done
2. apple generation shouldnt be on border and on the snake
done
3. no reverse self collission
done
4. (ops)graphical terminal protocol - kitty
dicey
5. remove randx and randy func
done

*/
//

