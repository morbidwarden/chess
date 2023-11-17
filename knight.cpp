#include <iostream>
#include <cmath>

const int BOARD_SIZE = 8;

// Function to check if a move is a valid knight move.
bool isValidKnightMove(int startX, int startY, int endX, int endY) {
    int dx = std::abs(endX - startX);
    int dy = std::abs(endY - startY);

    // A valid knight move consists of moving 2 squares in one direction
    // and 1 square in the other direction, either horizontally or vertically.
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

int main() {
    int startX, startY, endX, endY;

    std::cout << "Enter the starting position of the knight (x y): ";
    std::cin >> startX >> startY;

    std::cout << "Enter the ending position (x y) to check if it's a valid knight move: ";
    std::cin >> endX >> endY;

    if (isValidKnightMove(startX, startY, endX, endY)) {
        std::cout << "The move is a valid knight move." << std::endl;
    } else {
        std::cout << "The move is not a valid knight move." << std::endl;
    }

    return 0;
}
