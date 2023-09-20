//part1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Eight direction need to use a function to print.
//use 0,-1,1 to represent the row and column. 
//0 is does not change
//-1 is column go left and row go up
//1 is column go right and row go down.
void printFoundLocation(int rowDir, int colDir){
    if(rowDir==1&&colDir==0){
        printf("south direction.");
    }else if(rowDir==1&&colDir==-1){
        printf("southwest direction.");
    }else if(rowDir==1&&colDir==1){
        printf("southeast direction.");
    }else if(rowDir==0&&colDir==1){
        printf("east direction.");
    }else if(rowDir==0&&colDir==-1){
        printf("west direction.");
    }else if(rowDir==-1&&colDir==0){
        printf("north direction.");
    }else if(rowDir==-1&&colDir==1){
        printf("northeast direction.");
    }else if(rowDir==-1&&colDir==-1){
        printf("northwest direction.");
    }
}    

//use function to find the word
//for loop means only when the letter in the grid match the word we want to find, the length will add.
bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size], int row, int col, int rowDir, int colDir) {
    int rd=row+rowDir;
    int cd=col+colDir;
    int length=1;
    bool findWord=true;
    bool finalWord;
    for(int i=1;i<wordSize&&findWord;i++){
        if(grid[rd][cd]==word[i]&&rd>=0&&rd<Size&&cd>=0&&cd<Size){
            length++;
            rd = row+rowDir*(i+1);
            cd = col+colDir*(i+1);
            findWord=true;
        }else{
            findWord=false;
        }
//only the length of the word we found match the word it gives, the function return true.        
    if(length==wordSize){
        finalWord=true;
    }else{
        finalWord=false;
        }
    }
    return finalWord;    
}

void search2D(char word[], int wordSize, const int Size, char grid[Size][Size]) {
    int finalRow,finalColumn;
    int finalRowDir;
    int finalColDir;
    bool firstFound=false;
//use two array to store eight directions and put them in for loop.
    int rowDir[] = { 1, 1, 0, -1, -1, 1, 0, 1};
    int colDir[] = { 0, -1, -1, -1, 0, 1, 1, 1};
    for(int i=0;i<Size;i++){
        for(int j=0;j<Size;j++){
            if(word[0]==grid[i][j]&&!firstFound){
                for(int k=0;k<8&&!firstFound;k++){
                    if(search1D(word,wordSize, Size,grid,i,j,rowDir[k],colDir[k])){
                        finalRow=i;
                        finalColumn=j;
                        finalRowDir=rowDir[k];
                        finalColDir=colDir[k];
                        firstFound=true;

                    }else{
                        firstFound=false;
                    }
                }
            }
        }
    }
    // if the function return false, that means no word is found.
    if(firstFound=false){
        printf("Word not found.");
    }
    printf("Word found at row %d and column %d in the ",finalRow,finalColumn);
    printFoundLocation(finalRowDir,finalColDir);
}

//part2
#include <stdio.h>
#include <stdbool.h>

// check row function. For every column in a row, if there is a number exist in the row, return true, otherwise it is false.
bool checkRowNumber(int row, int column, const int Size, int number, int sudoko[Size][Size]){
    bool findNumber=false;
    for(column=0;column<Size;column++){
        if(sudoko[row][column]==number){
            findNumber=true;
        }
    }
    return findNumber;
}
// check column function.For every row in the column, if there is a number exist in the column, return true, otherwise it is false.
bool checkColumnNumber(int row, int column, const int Size, int number, int sukodo[Size][Size]){
    bool findNumber=false;
    for(row=0;row<Size;row++){
        if(sukodo[row][column]==number){
            findNumber=true;
        }
    }
    return findNumber;
}
// main function goes to write the number in the sudoko.
void fillSudoko(const int Size, int sudoko [Size][Size]){
    int row,column;
    int missingNumber;
    bool numberFound;
    for(row=0;row<Size;row++){
        for(column=0;column<Size;column++){
            if(sudoko[row][column]==0){
                for(int i=1;i<=4&&!numberFound;i++){
                // it is or not and, since any number appear in the row or column will not fill in the zero position.
                    if(checkRowNumber(row,column,Size,i,sudoko)||checkColumnNumber(row,column,Size,i,sudoko)){
                        numberFound=false;
                    }else{
                        missingNumber=i;
                        numberFound=true;
                    }
                }
                //stored the number we miss and write in the sudoko.
                sudoko[row][column]=missingNumber;
            }
            numberFound=false;
        }
    }
}
