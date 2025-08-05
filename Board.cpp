/* Murat Doruk Güneş – 2453272, Turab Erkin Akdeniz – 2452936
We read and accept the submission rules and the extra rules specified
in each question. This is our own work that is done by us only */

#include "Board.h"
char alpha[50]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};

Board::Board(int len, int wid) {
    width = wid;
    length = len;
    board = new char *[len];
    for(int i=0;i<len;++i)
        board[i] = new char [wid];  // allocate memory for 2d array.

    //initializeBoard();
}



void Board::initializeBoard() {
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){
            board[i][j]='.';
        }
    }
}

void Board::printBoard() {
    for(int i=0;i<length;i++) {
        if(i==0){
            cout<<"  ";
            for(int l=0;l<width;l++)
                cout<<alpha[l]<<" ";
        cout<<endl;
        }

        for (int j = 0; j < width; j++) {
            if(j==0)
                cout<<i+1<<" ";
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void Board::hitBoard(int a,int b) {
    if(board[a][b]!='.')
        board[a][b]='*';
}


void Board::placeShip(char a,int a1,char b,int b1,char c,int c1,char d,int d1,char e,int e1) {
    board[a1-1][getCharVal(a)] = '5';
    board[b1-1][getCharVal(b)] = '5';
    board[c1-1][getCharVal(c)] = '5';
    board[d1-1][getCharVal(d)] = '5';
    board[e1-1][getCharVal(e)] = '5';
}

void Board::placeShip(char a,int a1,char b,int b1,char c,int c1,char d,int d1) {
    board[a1-1][getCharVal(a)] = '4';
    board[b1-1][getCharVal(b)] = '4';
    board[c1-1][getCharVal(c)] = '4';
    board[d1-1][getCharVal(d)] = '4';
}

void Board::placeShip(char a,int a1,char b,int b1,char c,int c1) {
    board[a1-1][getCharVal(a)] = '3';
    board[b1-1][getCharVal(b)] = '3';
    board[c1-1][getCharVal(c)] = '3';
}


void Board::placeShip(char a, int a1) {
    board[a1-1][getCharVal(a)]='1';
}

int Board::getCharVal(char c) {
    if(c=='a')
        return 0;
    else if(c=='b')
        return 1;
    else if(c=='c')
        return 2;
    else if(c=='d')
        return 3;
    else if(c=='e')
        return 4;
    else if(c=='f')
        return 5;
    else if(c=='g')
        return 6;
    else if(c=='h')
        return 7;
    else if(c=='i')
        return 8;
    else if(c=='j')
        return 9;
    else if(c=='k')
        return 10;
    else if(c=='l')
        return 11;

    return 0;
}


int Board::getLen() {
    return length;
}

int Board::hit_or_miss(int a, int b) {
    if(board[a][b]!='.')
        return board[a][b]; // hit

    else
        return 0; // miss
}

void Board::setBoardWithIndex(int a, int b, char val) {
    board[a][b]=val;
}
