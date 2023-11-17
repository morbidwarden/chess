#include <iostream>
#include <vector>
int startX, startY;
    int endX, endY;
// Define constants for the chess pieces
const std::string EMPTY = " *";
const std::string PAWN = " P";
const std::string ROOK = " R";
const std::string KNIGHT = " N";
const std::string BISHOP = " B";
const std::string QUEEN = " Q";
const std::string KING = " K";

const std::string WHITEEMPTY = " *";
const std::string WHITEPAWN = "WP";
const std::string WHITEROOK = "WR";
const std::string WHITEKNIGHT = "WN";
const std::string WHITEBISHOP = "WB";
const std::string WHITEQUEEN = "WQ";
const std::string WHITEKING = "WK";

// Define a struct to represent a chess piece
struct ChessPiece {
    std::string symbol;
    // You can add more information like color if needed
};

// Define a 2D array to represent the chessboard
const int BOARD_SIZE = 8;
std::vector<std::vector<ChessPiece>> chessboard(BOARD_SIZE, std::vector<ChessPiece>(BOARD_SIZE));

// Function to initialize the chessboard with starting positions
void initializeChessboard() {
    // Initialize the board with empty squares
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            chessboard[i][j].symbol = EMPTY;
        }
    }

    // Set up the initial positions of white pieces
    chessboard[0][0].symbol = ROOK;
    chessboard[0][1].symbol = KNIGHT;
    chessboard[0][2].symbol = BISHOP;
    chessboard[0][3].symbol = QUEEN;
    chessboard[0][4].symbol = KING;
    chessboard[0][5].symbol = BISHOP;
    chessboard[0][6].symbol = KNIGHT;
    chessboard[0][7].symbol = ROOK;

    for (int i = 0; i < BOARD_SIZE; i++) {
        chessboard[1][i].symbol = PAWN;
    }

    // Set up the initial positions of black pieces
    chessboard[7][0].symbol = WHITEROOK;
    chessboard[7][1].symbol = WHITEKNIGHT;
    chessboard[7][2].symbol = WHITEBISHOP;
    chessboard[7][3].symbol = WHITEQUEEN;
    chessboard[7][4].symbol = WHITEKING;
    chessboard[7][5].symbol = WHITEBISHOP;
    chessboard[7][6].symbol = WHITEKNIGHT;
    chessboard[7][7].symbol = WHITEROOK;

    for (int i = 0; i < BOARD_SIZE; i++) {
        chessboard[6][i].symbol = WHITEPAWN;
    }
}

// Function to display the chessboard
void displayChessboard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << chessboard[i][j].symbol << ' ';
        }
        std::cout << std::endl;
    }
}
void makemove(int startX,int startY,int endX,int endY){
    chessboard[endX][endY].symbol=chessboard[startX][startY].symbol;
    chessboard[startX][startY].symbol = EMPTY;
    
}
bool isValidKnightMove(int startX, int startY, int endX, int endY) {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // A valid knight move consists of moving 2 squares in one direction
    // and 1 square in the other direction, either horizontally or vertically.
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}
bool isValidBishopMove(int startX, int startY, int endX, int endY) {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // A valid bishop move is diagonal (dx == dy) and not a zero-length move.
    return dx == dy && dx > 0;
}

bool isValidRookMove(int startX, int startY, int endX, int endY) {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // A valid rook move is either horizontal (dx > 0 and dy == 0) or vertical (dx == 0 and dy > 0).
    return (dx > 0 && dy == 0) || (dx == 0 && dy > 0);
}
bool isValidQueenMove(int startX, int startY, int endX, int endY) {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // A valid queen move is either horizontal (dx > 0 and dy == 0), vertical (dx == 0 and dy > 0),
    // or diagonal (dx == dy) and not a zero-length move.
    return (dx > 0 && dy == 0) || (dx == 0 && dy > 0) || (dx == dy && dx > 0);
}
//white move
void whitemove(){
    std::cout<<"White turns"<<std::endl;
    std::cout<<"position of the piece you want to move "<<std::endl;
    std::cin >> startX >> startY;
    std::cout<<"position you want the piece to move to "<<std::endl;
    std::cin >> endX >> endY;
}
//black move
void blackmove(){
    std::cout<<"White turns"<<std::endl;
    std::cout<<"position of the piece you want to move "<<std::endl;
    std::cin >> startX >> startY;
    std::cout<<"position you want the piece to move to "<<std::endl;
    std::cin >> endX >> endY;
}

int main() {
    initializeChessboard();
    displayChessboard();
    
    while(startX!=10){
    whitemove();
    //VALIDATION CONDITION FOR ROOKS
    if(chessboard[startX][startY].symbol==ROOK || chessboard[startX][startY].symbol==WHITEROOK){
        if(isValidRookMove(startX,startY,endX,endY)){
            std::cout<<"validroookmove"<<std::endl;
            makemove(startX,startY,endX,endY);
        }
        else{
            whitemove();
        }
    }
    // VALIDATION CONDITION FOR BISHOP
    else if(chessboard[startX][startY].symbol==BISHOP || chessboard[startX][startY].symbol==WHITEBISHOP){
        if(isValidBishopMove(startX,startY,endX,endY)){
            makemove(startX,startY,endX,endY);
        }
        else{
            whitemove();
        }
    }
    // VALIDATION CONDITION FOR KNIGHT
    else if(chessboard[startX][startY].symbol==KNIGHT || chessboard[startX][startY].symbol==WHITEKNIGHT){
        if(isValidKnightMove(startX,startY,endX,endY)){
            std::cout<<"validroookmove"<<std::endl;
            makemove(startX,startY,endX,endY);
        }
        else{
            whitemove();
        }
    }
    // VALIDATION CONDITION FOR QUEEN
    else if(chessboard[startX][startY].symbol==QUEEN || chessboard[startX][startY].symbol==WHITEQUEEN){
        if(isValidQueenMove(startX,startY,endX,endY)){
            makemove(startX,startY,endX,endY);
        }
        else{
            whitemove();
        }
    }
    
    displayChessboard();
   blackmove();
   if(chessboard[endX][endY].symbol==ROOK || chessboard[endX][endY].symbol==WHITEROOK){
        if(isValidRookMove(startX,startY,endX,endY)){
            makemove(startX,startY,endX,endY);
        }
        else{
            blackmove();
        }
   }
   //validation codnition for BISHOP
   else if(chessboard[startX][startY].symbol==BISHOP || chessboard[startX][startY].symbol==WHITEBISHOP){
        if(isValidBishopMove(startX,startY,endX,endY)){
            makemove(startX,startY,endX,endY);
        }
        else{
            blackmove();
        }
    }
    // validation condition for Knight
    else if(chessboard[startX][startY].symbol==KNIGHT || chessboard[startX][startY].symbol==WHITEKNIGHT){
        if(isValidKnightMove(startX,startY,endX,endY)){
            std::cout<<"validroookmove"<<std::endl;
            makemove(startX,startY,endX,endY);
        }
        else{
            std::cout<<"invalid move"<<std::endl;
            blackmove();
        }
    }
    else if(chessboard[startX][startY].symbol==QUEEN || chessboard[startX][startY].symbol==WHITEQUEEN){
        if(isValidQueenMove(startX,startY,endX,endY)){
            makemove(startX,startY,endX,endY);
        }
        else{
            blackmove();
        }
    }
   
    displayChessboard();
    
    
    }
}