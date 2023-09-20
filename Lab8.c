//part1
#include <stdbool.h>;
#include <stdio.h>;

void Filp(char board[][26],int n,int row, int column, char colour, int deltaRow, int deltaCol){
    int newRow=row+deltaRow;
    int newCol=column+deltaCol;
    while(positionInBounds(n,newRow,newCol)&&board[newRow][newCol]!=colour&&board[newRow][newCol]!='U'){
        board[newRow][newCol]=colour;
        newRow+=deltaRow;
        newCol+=deltaCol;
    }
    board[row][column]=colour;
}

void tileFlip(char board[26][26],int n,char colour,char row, char column){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    int rowNum = row-'a';
    int colNum = column-'a';
    for (int k=0;k<8;k++){
        if (checkLegalInDirection(board,n,rowNum,colNum,colour,Row[k],Col[k])){
            Filp(board,n,rowNum,colNum,colour,Row[k],Col[k]);
        }
    }
}

bool validmove(char board[26][26],int n,char colour,char row, char column){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    int rowNum = row-'a';
    int colNum = column-'a';
    bool find = false;
    for (int k=0;k<8;k++){
        if (checkLegalInDirection(board,n,rowNum,colNum,colour,Row[k],Col[k])){
            find=true;
        }
    }
    return find;
}

void printBoard(char board[26][26], int n){
    printf("  ");
    for(int i=0;i<n;i++){
        printf("%c",97+i);
    }
    for(int i=0;i<n;i++){
        printf("\n%c ",97+i);
        for(int j=0;j<n;j++){
            printf("%c",board[i][j]);
        }
    }printf("\n");
}

bool positionInBounds(int n, int row, int col){
    bool inBounds;
    if(row>=0&&row<n&&col>=0&&col<n){
        inBounds=true;
    }
    else{
        inBounds=false;
    }
    return inBounds;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
    bool legalsituation=false;
    int newRow;
    int newColumn;
    newRow=row+deltaRow;
    newColumn=col+deltaCol;
    if(!positionInBounds(n,newRow,newColumn)){
        legalsituation=false;
    }
    else if(positionInBounds(n,newRow,newColumn)&&board[newRow][newColumn]==colour){
        legalsituation=false;
    }
    else{
        while(positionInBounds(n,newRow,newColumn)&&board[newRow][newColumn]!=colour&&board[newRow][newColumn]!='U'){
            newRow+=deltaRow;
            newColumn+=deltaCol;
        }
        if(positionInBounds(n,newRow,newColumn)&&board[newRow][newColumn]==colour){
            legalsituation=true;
        }
        else{
            legalsituation=false;
        }
    }
    return legalsituation;
}

void user(char board[26][26],int n, char colour, char row,char col){
    tileFlip(board,n,colour,row,col);
    printBoard(board,n);
}

int score(char board[26][26],int n, char colour,char row,char col){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    int newRow,newCol;
    int score=0;
    for(int i=0;i<8;i++){
        newRow=row+Row[i];
        newCol=col+Col[i];
        if(checkLegalInDirection(board,n,row-'a',col-'a',colour,Row[i],Col[i])){
            if(board[newRow][newCol]!=colour&&board[newRow][newCol]!='U'){
                score++;
                newRow+=Row[i];
                newCol+=Col[i];
            }
        }
    }
    return score;
}

void computer(char board[26][26],int n,char colour){
    int row,col;
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    int currentScore;
    int largestScore=0;
    int finalRow;
    int finalCol;
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
            if(board[row][col]=='U'){
                for(int i=0;i<8;i++){
                    if(checkLegalInDirection(board,n,row,col,colour,Row[i],Col[i]));
                    currentScore=score(board,n,colour,row+'a',col+'a');
                    if(currentScore>largestScore){
                        largestScore=currentScore;
                        finalRow=row;
                        finalCol=col;
                        currentScore=0;
                    }
                }
            }
        }
    }
    printf("Computer places %c at %c%c.\n", colour,finalRow+'a',finalCol+'a');
    tileFlip(board,n,colour,finalRow+'a',finalCol+'a');
    printBoard(board,n);
}

bool availmove(char board[26][26],int n,char colour){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    bool done=false;
    bool available=false;
    int row;
    int col;
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
            if(board[row][col]=='U'){
                for(int i=0;i<8&&!done;i++){
                    if(checkLegalInDirection(board,n,row,col,colour,Row[i],Col[i])&&!done){
                        done=true;
                        available=true;
                    }
                }
            }
            done=false;
        }
    }
    return available;
}

void larger(char board[26][26],int n){
    int numofBlack=0;
    int numofWhite=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='B'){
                numofBlack++;
            }else if(board[i][j]=='W'){
                numofWhite++;
            }
        }
    }
    if(numofBlack>numofWhite){
        printf("B player wins.");
    }
    else if(numofBlack<numofWhite){
        printf("W player wins.");
    }
    else if(numofBlack==numofWhite){
        printf("Draw!");
    }
}

int main(void){
    printf("Enter the board dimension: ");
    int n;
    scanf("%d",&n);
    printf("Computer plays (B/W):");
    char colour;
    scanf("\n%c",&colour);
    char board[26][26];
    printf(" ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]='U';
        }
    }
    board[n/2][n/2]='W';
    board[(n/2)-1][(n/2)-1]='W';
    board[(n/2)-1][n/2]='B';
    board[n/2][(n/2)-1]='B';
    printBoard(board,n);

    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};

    bool done=false;
    bool legal=false;
    char row;
    char col;
    int situationnum;
    while(!done){
        if(colour=='W'){
            if(availmove(board,n,'B')){
                printf("Enter move for colour B (RowCol): ");
                scanf("\n%c%c",&row,&col);
                if(validmove(board,n,'B',row,col)){
                    legal=true;
                    user(board,n,'B',row,col);
                }
                else{
                    legal=false;
                    situationnum=2;
                }
            }
            if(availmove(board,n,'W')){
                computer(board,n,'W');
            }else{
                situationnum=1;
            }    
        }
        if(colour=='B'){
            if(availmove(board,n,'B')){
                computer(board,n,'B');
            }else{
                situationnum=2;
            }
            if(availmove(board,n,'W')){
                printf("Enter move for colour W (RowCol): ");
                scanf("\n%c%c",&row,&col);
                if(validmove(board,n,'W',row,col)){
                    legal=true;
                    user(board,n,'W',row,col);
                }else{
                    legal=false;
                    situationnum=1;
                }
            }
        }
        if(!legal){
            done=true;
            printf("Invalid move.\n");
            printf("%c player wins.", colour);
        }
        else if((!availmove(board,n,'W')&&!availmove(board,n,'B'))){
            done=true;
            larger(board,n);
        }
        if(situationnum==1&&!done){
            printf("W player has no valid move.\n");
        }
        else if(situationnum==2&&!done){
            printf("B player has no valid move.\n");
        }
    }
    return 0;
}

//part2
#include <stdbool.h>;
#include <stdio.h>;

void Filp(char board[][26],int n,int row, int column, char colour, int deltaRow, int deltaCol){
    int newRow=row+deltaRow;
    int newCol=column+deltaCol;
    while(positionInBounds(n,newRow,newCol)&&board[newRow][newCol]!=colour&&board[newRow][newCol]!='U'){
        board[newRow][newCol]=colour;
        newRow+=deltaRow;
        newCol+=deltaCol;
    }
    board[row][column]=colour;
}

void tileFlip(char board[26][26],int n,char colour,char row, char column){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    int rowNum = row-'a';
    int colNum = column-'a';
    for (int k=0;k<8;k++){
        if (checkLegalInDirection(board,n,rowNum,colNum,colour,Row[k],Col[k])){
            Filp(board,n,rowNum,colNum,colour,Row[k],Col[k]);
        }
    }
}

void printBoard(char board[26][26], int n){
    printf("  ");
    for(int i=0;i<n;i++){
        printf("%c",97+i);
    }
    for(int i=0;i<n;i++){
        printf("\n%c ",97+i);
        for(int j=0;j<n;j++){
            printf("%c",board[i][j]);
        }
    }printf("\n");
}

bool positionInBounds(int n, int row, int col){
    bool inBounds;
    if(row>=0&&row<n&&col>=0&&col<n){
        inBounds=true;
    }
    else{
        inBounds=false;
    }
    return inBounds;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
    bool legalsituation=false;
    int newRow;
    int newColumn;
    newRow=row+deltaRow;
    newColumn=col+deltaCol;
    if(!positionInBounds(n,newRow,newColumn)){
        legalsituation=false;
    }
    else if(positionInBounds(n,newRow,newColumn)&&board[newRow][newColumn]==colour){
        legalsituation=false;
    }
    else{
        while(positionInBounds(n,newRow,newColumn)&&board[newRow][newColumn]!=colour&&board[newRow][newColumn]!='U'){
            newRow+=deltaRow;
            newColumn+=deltaCol;
        }
        if(positionInBounds(n,newRow,newColumn)&&board[newRow][newColumn]==colour){
            legalsituation=true;
        }
        else{
            legalsituation=false;
        }
    }
    return legalsituation;
}

bool availmove(char board[26][26],int n,char colour){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    bool done=false;
    bool available=false;
    int row;
    int col;
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
            if(board[row][col]=='U'){
                for(int i=0;i<8&&!done;i++){
                    if(checkLegalInDirection(board,n,row,col,colour,Row[i],Col[i])&&!done){
                        done=true;
                        available=true;
                    }
                }
            }
            done=false;
        }
    }
    return available;
}

int score(char board[26][26],int n, char colour,char row,char col){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    int newRow,newCol;
    int score=0;
    for(int i=0;i<8;i++){
        newRow=row+Row[i];
        newCol=col+Col[i];
        if(checkLegalInDirection(board,n,row-'a',col-'a',colour,Row[i],Col[i])){
            if(board[newRow][newCol]!=colour&&board[newRow][newCol]!='U'){
                score++;
                newRow+=Row[i];
                newCol+=Col[i];
            }
        }
    }
    return score;
}

int playInCenter(char board[][26],int n,char colour,int row,int col){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    char temp[26][26];
    for(int i=0;row<n;row++){
        for(int j=0;col<n;col++){
            temp[i][j]=board[i][j];
        }
    }
    bool done=false;

    int numofTile=0;
    tileFlip(temp,n,colour,row,col);
    for(int l=-1;l<=0;l++){
        for(int m=-1;m<=0;m++){
            if(temp[n/2+l][n/2+m]==colour){
                numofTile++;
                done=true;
            }
        }
    }
    return numofTile;
}

int playerAvailableMove(char board[][26],int n, char colour,int row,int col){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    char temp[26][26];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=board[i][j];
        }
    }

    bool done=false;

    int numofPosition=0;

    tileFlip(temp,n,colour,row,col);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(temp[i][j]=='U'){
                for(int k=0;k<8&&!done;k++){
                    if(availmove(temp,n,colour)){
                        numofPosition++;
                        done=true;
                    }     
                }
                done=false;
            }
        }
    }
    return numofPosition;
}

int oppoAvilableMove(char board[][26],int n,char colour,int row, int col){
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    char temp[26][26];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=board[i][j];
        }
    }
    
    bool done=false;
    int numoppoMove=0;
    tileFlip(temp,n,colour,row,col);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(temp[i][j]=='U'){
                for(int k=0;k<8&&!done;k++){
                    if(colour=='B'){
                        if(availmove(temp,n,'W')){
                            numoppoMove++;
                        }
                    }
                    else if(colour=='W'){
                        if(availmove(temp,n,'B')){
                            numoppoMove++;
                        }
                    }
                }
            }
        }
    }
    return numoppoMove;
}

int playerCorner(char board[][26],int n,char colour, int row, int col){
    int number;
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    for(int i=0;i<8;i++){
        if((row==0&&col==n-1)||(row==0&&col==0)||(row==n-1&&col==0)||(row==n-1&&col==n-1)){
            if((board[row][col]=='U')&&checkLegalInDirection(board,n,row,col,colour,Row[i],Col[i])){
                number=1;
            }
        }
    }
    return number;
}

int makeMove(const char board[][26], int n, char turn, int *row, int *col) {
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    int mark=0;
    int largestmark=0;
    int currentscore=0;
    int finalRow,finalCol;
    int least=50;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='U'){
                for(int k=0;k<8;k++){
                    if(checkLegalInDirection(board,n,i,j,turn,Row[k],Col[k])){
                        if(playerAvailableMove(board,n,turn,i,j)>0){
                            mark+=2;
                        }
                        if(playerCorner(board,n,turn,i,j)==1){
                            mark+=4;
                        }
                        if(score(board,n,turn,i+'a',j+'a')>currentscore){
                            currentscore=score(board,n,turn,i+'a',j+'a');
                            mark+=1;
                        }
                        if(oppoAvilableMove(board,n,turn,i,j)<least){
                            least=oppoAvilableMove(board,n,turn,i,j);
                            mark+=2;
                        }
                        int currentmark=mark;
                        if(currentmark>largestmark){
                            largestmark=currentmark;
                            finalRow=i;
                            finalCol=j;
                            mark=0;
                            
                        }
                        else{
                            mark=0;
                        }
                    }

                }
            }
        }
    }
    *row=finalRow;
    *col=finalCol;
    return 0;
}
