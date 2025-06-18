
//     if (inp == 'a' || inp == 'A') {
            
//       if (grid[head->yCor][head->xCor] == '#' ||
//           grid[head->yCor][head->xCor-1] == 'O') {
//         printf("\033[H");
//         printMatrix();
//         break;
//       }
//         node *tempo = head;

//       int backupHeadxCor = head->xCor;
//       if (grid[head->yCor][head->xCor - 1] == ' ') {
//         int X = head->xCor;
//         int Y = head->yCor;

//         tempo = head;

//         while (tempo->next != NULL) {

//           int tempX = tempo->next->xCor;
//           int tempY = tempo->next->yCor;

//           tempo->next->xCor = X;
//           tempo->next->yCor = Y;

//           X = tempX;
//           Y = tempY;

//           tempo = tempo->next;
//         }
//         // collusion me neeche wale part ka kuch toh hoga
//         head->xCor = backupHeadxCor;
//         node *temp = head;
//         printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
//         while (temp->next != NULL) {
//           printf("[%d,%d]-->", temp->xCor, temp->yCor);
//           temp = temp->next;
//         }
//         tempo->next = NULL;
//         tail = tempo;

//         //

//         grid[head->yCor][--head->xCor] = 'O';
//         grid[tail->yCor][tail->xCor] = ' ';

//         printf("\033[H"); // Move cursor to top-left (don't clear screen)
//         printMatrix();

//       }

//       else if (grid[head->yCor][head->xCor - 1] == 'Q') {
//         applesOnScreen=0;

//         int X = head->xCor, Y = head->yCor;
//         int swapper;
//         node *newNode = malloc(sizeof(node));
//         newNode->next = head;
//         head->previous = newNode;
//         newNode->previous = NULL;
//         newNode->xCor = head->xCor;
//         newNode->yCor = head->yCor;
//         head = newNode;

//         // newNode=head;
//         // head=newNode->next;
//         grid[head->yCor][head->xCor - 1] = 'O';
//         head->xCor--;
//         grid[head->yCor][head->xCor] = 'O';
//         grid[tail->yCor][tail->xCor] = ' ';
//         printf("\033[H");
//         printMatrix();
//       }

//     }

//     if (inp == 's' || inp == 'S') {
//       node *tempo = head;

//       int backupHeadyCor = head->yCor;
//       printf("'%c'-next", grid[(head->yCor + 1)][head->xCor]);
//       if (grid[head->yCor + 1][head->xCor] == ' ') {
//         int X = head->xCor;
//         int Y = head->yCor;

//         tempo = head;

//         while (tempo->next != NULL) {

//           int tempX = tempo->next->xCor;
//           int tempY = tempo->next->yCor;

//           tempo->next->xCor = X;
//           tempo->next->yCor = Y;

//           X = tempX;
//           Y = tempY;

//           tempo = tempo->next;
//         }
//         // collusion me neeche wale part ka kuch toh hoga
//         head->yCor = backupHeadyCor;
//         node *temp = head;
//         // printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
//         while (temp->next != NULL) {
//           printf("[%d,%d]-->", temp->xCor, temp->yCor);
//           temp = temp->next;
//         }
//         tempo->next = NULL;
//         tail = tempo;

//         //

//         grid[++head->yCor][head->xCor] = 'O';
//         grid[tail->yCor][tail->xCor] = ' ';

//         printf("\033[H"); // Move cursor to top-left (don't clear screen)
//         printMatrix();

//       }

//       else if (grid[head->yCor + 1][head->xCor] == 'Q') {
//         applesOnScreen=0;
//         int X = head->xCor, Y = head->yCor;
//         int swapper;
//         node *newNode = malloc(sizeof(node));
//         newNode->next = head;
//         head->previous = newNode;
//         newNode->previous = NULL;
//         newNode->xCor = head->xCor;
//         newNode->yCor = head->yCor;
//         head = newNode;

//         // newNode=head;
//         // head=newNode->next;
//         grid[head->yCor + 1][head->xCor] = 'O';
//         head->yCor++;
//         grid[head->yCor][head->xCor] = 'O';
//         grid[tail->yCor][tail->xCor] = ' ';
//         printf("\033[H");
//         printMatrix();
//       }

//       if (grid[head->yCor][head->xCor] == '#' ||
//           grid[head->yCor+1][head->xCor+1] == 'O') {
//         printf("\033[H");
//         printMatrix();
//         break;
//       }
//     }

//     // else exit(0);

//     if (inp == 'd' || inp == 'D') {
//       node *tempo = head;

//       int backupHeadxCor = head->xCor;
//       printf("'%c'-next", grid[(head->yCor - 1)][head->xCor]);
//       if (grid[head->yCor][head->xCor + 1] == ' ') {
//         int X = head->xCor;
//         int Y = head->yCor;

//         tempo = head;

//         while (tempo->next != NULL) {

//           int tempX = tempo->next->xCor;
//           int tempY = tempo->next->yCor;

//           tempo->next->xCor = X;
//           tempo->next->yCor = Y;

//           X = tempX;
//           Y = tempY;

//           tempo = tempo->next;
//         }
//         // collusion me neeche wale part ka kuch toh hoga
//         head->xCor = backupHeadxCor;
//         node *temp = head;
//         printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
//         while (temp->next != NULL) {
//           printf("[%d,%d]-->", temp->xCor, temp->yCor);
//           temp = temp->next;
//         }
//         tempo->next = NULL;
//         tail = tempo;

//         //

//         grid[head->yCor][++head->xCor] = 'O';
//         grid[tail->yCor][tail->xCor] = ' ';

//         printf("\033[H"); // Move cursor to top-left (don't clear screen)
//         printMatrix();

//       }

//       else if (grid[head->yCor][head->xCor + 1] == 'Q') {
//         applesOnScreen=0;

//         int X = head->xCor, Y = head->yCor;
//         int swapper;
//         node *newNode = malloc(sizeof(node));
//         newNode->next = head;
//         head->previous = newNode;
//         newNode->previous = NULL;
//         newNode->xCor = head->xCor;
//         newNode->yCor = head->yCor;
//         head = newNode;

//         // newNode=head;
//         // head=newNode->next;
//         grid[head->yCor][head->xCor + 1] = 'O';
//         head->xCor++;
//         grid[head->yCor][head->xCor] = 'O';
//         grid[tail->yCor][tail->xCor] = ' ';
//         printf("\033[H");
//         printMatrix();
//       }

//       if (grid[head->yCor][head->xCor] == '#' ||
//           grid[head->yCor][head->xCor+1] == 'O') {
//         printf("\033[H");
//         printMatrix();
//         break;
//       }
//     }

//     // printMatrix();
//   }
// }
