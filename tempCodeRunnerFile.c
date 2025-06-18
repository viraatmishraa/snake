 if(grid[head->yCor][head->xCor]=='#'||grid[head->yCor+1][head->xCor]=='O')
         {
         printf("\033[H");
         printMatrix();
         break;
       }