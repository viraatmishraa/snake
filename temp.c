if(grid[head->yCor-1][head->xCor]=='Q')
{
    int X=head->xCor,Y=head->yCor;
    int swapper;
    node * newNode=malloc(sizeof(node));
    newNode->next=head;
    head->previous=newNode;
    newNode->NULL;
    newNode=head;



    // while(tempo->next!=NULL)
    // {
    //     swapper=tempo->xCor;
    //     tempo->xCor=X;
    //     X=swapper;
        
    //     swapper=tempo->yCor;
    //     tempo->yCor=Y;
    //     Y=swapper;
        
    //     swapper=tempo->next->xCor;
    //     tempo->next->xCor=X;
    //     X=swapper;
        
    //     swapper=tempo->next->xCor;
    //     tempo->next->xCor=X;
    //     X=swapper;
        
        
    //     tempo=tempo->next;// very mehnat wala part, head ka info aage push karke , head update kardia
    // }
    // //collusion me neeche wale part ka kuch toh hoga
    head->yCor=backupHeadyCor;
    
    tempo->next=NULL;
    tail=tempo;
    //
    
    printf("\n\n\n\n\n\n\n\n\n\n'%c'grid[head->yCor-1][head->xCor]\n head->xCor->%d\n head->yCor->%d \ntail->xCor->%d \ntail->yCor->%d\n",grid[head->yCor-1][head->xCor],head->xCor,head->yCor,tail->xCor,tail->yCor);

    grid[--head->yCor][head->xCor]='O';
    grid[--tail->yCor][tail->xCor]='o';
    
    
    printf("\033[H");  // Move cursor to top-left (don't clear screen)
    printMatrix();

}