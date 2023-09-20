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

void tileFlip(char board[26][26],int n){
    char colour,row,column;
    printf("Enter a move:\n");
    scanf("\n%c%c%c",&colour,&row,&column);
    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};
    int rowNum = row-'a';
    int colNum = column-'a';
    bool find = false;
    for (int k=0;k<8;k++){
        if (checkLegalInDirection(board,n,rowNum,colNum,colour,Row[k],Col[k])){
            Filp(board,n,rowNum,colNum,colour,Row[k],Col[k]);
            find=true;
        }
    }
    if(find){
        printf("Valid move.\n");
        boardArrange(board,n);
    }
    else{
        printf("Invalid move.\n");
        boardArrange(board,n);
    }
}

void boardArrange(char board[26][26], int n){
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

void printBoard(char board[26][26], int n){
    printf("Enter board configuration:");
    printf("\n");
    char colour,row,column;
    do{
        scanf("\n%c%c%c",&colour,&row,&column);
        board[row-'a'][column-'a']=colour;
    }
    while(colour!='!'&&row!='!'&&column!='!');
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

int main(void){
    int n;
    char board[26][26];
    printf("Enter the board dimension:");
    scanf("%d",&n);
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
    boardArrange(board,n);
    printBoard(board,n);
    boardArrange(board,n);

    int Row[] ={ 1, 1, 0, -1, -1, -1, 0, 1};
    int Col[] ={ 0, -1, -1, -1, 0, 1, 1, 1};

    printf("Available moves for W:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<8;k++){
                if(board[i][j]=='U'&& checkLegalInDirection(board,n,i,j,'W',Row[k],Col[k])){
                    printf("%c%c\n",i+97,j+97);
                }
            }
        }
    }

    printf("Available moves for B:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<8;k++){
                if(board[i][j]=='U'&& checkLegalInDirection(board,n,i,j,'B',Row[k],Col[k])){
                    printf("%c%c\n",i+97,j+97);
                }
            }
        }
    }
    tileFlip(board,n);
    
    return 0;
}
