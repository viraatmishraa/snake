#include <stdio.h>  
#include <unistd.h>
#include <time.h>
#include <stdlib.h>  
int moveleft();
int moveright();
int moveup();
int movedown();
int createRandX();
int printMatrix();
int createRandY();
// int collosion();

typedef struct node
{
    struct node * previous;
    struct node * next;
    int xCor;
    int yCor;
} node;
//globally cant be declared as, function calls aint allowed here
// node * head = malloc(sizeof(node));
// node * tail = malloc(sizeof(node));

node * head=NULL;
node * tail=NULL;//declared globally so accessible everywhere

char grid[16][32]={"################################"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                              #"
    ,"#                             O#"
    ,"################################"};
    

int main()
{
    head =malloc(sizeof(node));//initiallized in main
    tail=malloc(sizeof(node));
    head->yCor=14;
    head->xCor=30;
    tail->xCor=30;
    tail->yCor=15;
    tail->previous=head;
    head->next=tail;
    printMatrix();
    while (1){
        // printf("%c",grid[14][30]);

    // printf("\033[H\033[J");
    
    char inp;
    inp=getchar ();
    // if(grid[head->yCor][head->xCor-1]=='Q')
    //     {
    //         collosion();
    //     }
    if(inp=='a'||inp=='A')
    {
        
        tail->xCor=tail->previous->xCor;
        tail->yCor=tail->previous->yCor;

        (head->xCor)--;

        if(grid[head->yCor][head->xCor]!='#'&&grid[head->yCor][head->xCor]!='O')
       { grid[head->yCor][head->xCor]='O';
         grid[tail->yCor][tail->xCor]=' ';
        printf("\033[H");  // Move cursor to top-left (don't clear screen)
        printMatrix();
        printf("w,%d,%d,'%c'",head->yCor,head->xCor,grid[head->yCor][head->xCor]);}
         
    }
    if(inp=='d'||inp=='D')
    {
        
        tail->xCor=tail->previous->xCor;
        tail->yCor=tail->previous->yCor;

        head->xCor++;
        if(grid[head->yCor][head->xCor]!='#'&&grid[head->yCor][head->xCor]!='O')
       { grid[head->yCor][head->xCor]='O';
        grid[tail->yCor][tail->xCor]=' ';

        printf("\033[H");  // Move cursor to top-left (don't clear screen)
        printMatrix();
        printf("s,%d,%d,'%c'",head->yCor,head->xCor,grid[head->yCor][head->xCor]);
       }

        // else exit(0);
    }
    if(inp=='w'||inp=='W')
    {
        
        tail->xCor=tail->previous->xCor;
        tail->yCor=tail->previous->yCor;

        head->yCor--;
        if(grid[head->yCor][head->xCor]!='#'&&grid[head->yCor][head->xCor]!='O')
        {grid[head->yCor][head->xCor]='O';
        grid[tail->yCor][tail->xCor]=' ';
        
        printf("\033[H");  // Move cursor to top-left (don't clear screen)
        printMatrix();
        printf("a,%d,%d,'%c'",head->yCor,head->xCor,grid[head->yCor][head->xCor]);
        }

        // else exit(0);
    }
    if(inp=='s'||inp=='S')
    {
        tail->xCor=tail->previous->xCor;
        tail->yCor=tail->previous->yCor;

        head->yCor++;
        if(grid[head->yCor][head->xCor]!='#'&&grid[head->yCor][head->xCor]!='O')
        {
         grid[tail->yCor][tail->xCor]=' ';
            
            grid[head->yCor][head->xCor]='O';
        printf("\033[H");  // Move cursor to top-left (don't clear screen)
        printMatrix();
        printf("d,%d,%d,'%c'",head->yCor,head->xCor,grid[head->yCor][head->xCor]);
        }

        // else exit(0); 
    }
    // printMatrix();
    
    }}


int createRandX()
{
    srand(time(NULL));//srand is basically feeding a seed value to the pseudo 
    //random function rand() on the basis of time
    int random=rand();
    random=(random%31)+1;
    return random;
}


 
int createRandY()
{
    srand(time(NULL));
    int random=(rand()%15)+1;
    return random;
}




int printMatrix()
{
    
for(int i=0;i<16;i++)
{
    for(int j=0;j<32;j++)
    {
        printf("%c",grid[i][j]);
    }        printf("\n");

}}
// 
// int collosion();
// {
//     node *new=node *(malloc(sizeOf(node)));
//     head->next=new->next;
//     new->previous=head->next
    
    
    
// }

//collosion function 

//swapped xCor with yCor
//