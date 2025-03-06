#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

enum Player { EMPTY, PLAYER_1, PLAYER_2 };
enum GameStatus { ONGOING, PLAYER_1_WINS, PLAYER_2_WINS, DRAW };

vector<vector<Player>> board(ROWS, vector<Player>(COLS, EMPTY));

void printRules() {
    cout << "Welcome to Connect Four!" << endl;
    cout << "Players take turns dropping discs into one of the 7 columns." << endl;
    cout << "The first player to connect four pieces in a row (vertically, horizontally, or diagonally) wins!" << endl;
    cout << "If the board fills up and no one has four in a row, it's a draw." << endl;
}

void makeBoard() {
    board.assign(ROWS, vector<Player>(COLS, EMPTY));
}

void displayBoard() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == PLAYER_1) cout << " X ";
            else if (board[row][col] == PLAYER_2) cout << " O ";
            else cout << " . ";
        }
        cout << endl;
    }
    cout << " 1  2  3  4  5  6  7 " << endl;
}

bool isValidMove(int column) {
    return column >= 0 && column < COLS && board[0][column] == EMPTY;
}

bool play(int column, Player player) {
    if (!isValidMove(column)) return false;
    
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][column] == EMPTY) {
            board[row][column] = player;
            return true;
        }
    }
    return false;
}

GameStatus gameStatus() {
    // Check horizontal, vertical, and diagonal wins
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == EMPTY) continue;
            Player curr = board[row][col];
            
            // Check horizontal
            if (col + 3 < COLS && board[row][col + 1] == curr && board[row][col + 2] == curr && board[row][col + 3] == curr)
                return (curr == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            
            // Check vertical
            if (row + 3 < ROWS && board[row + 1][col] == curr && board[row + 2][col] == curr && board[row + 3][col] == curr)
                return (curr == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            
            // Check diagonal (bottom-left to top-right)
            if (row - 3 >= 0 && col + 3 < COLS && board[row - 1][col + 1] == curr && board[row - 2][col + 2] == curr && board[row - 3][col + 3] == curr)
                return (curr == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
            
            // Check diagonal (top-left to bottom-right)
            if (row + 3 < ROWS && col + 3 < COLS && board[row + 1][col + 1] == curr && board[row + 2][col + 2] == curr && board[row + 3][col + 3] == curr)
                return (curr == PLAYER_1) ? PLAYER_1_WINS : PLAYER_2_WINS;
        }
    }
    
    // Check for draw
    for (int col = 0; col < COLS; col++) {
        if (board[0][col] == EMPTY) return ONGOING;
    }
    return DRAW;
}

void startGame() {
    printRules();
    makeBoard();
    Player currentPlayer = PLAYER_1;
    GameStatus status = ONGOING;
    
    while (status == ONGOING) {
        displayBoard();
        int column;
        cout << "Player " << (currentPlayer == PLAYER_1 ? "X" : "O") << "'s turn. Choose a column (1-7): ";
        cin >> column;
        column--;
        
        if (!isValidMove(column)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        
        play(column, currentPlayer);
        status = gameStatus();
        currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
    }
    
    displayBoard();
    if (status == PLAYER_1_WINS) cout << "Player X wins!" << endl;
    else if (status == PLAYER_2_WINS) cout << "Player O wins!" << endl;
    else cout << "It's a draw!" << endl;
    
    char choice;
    cout << "Play again? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') startGame();
}

int main() {
    startGame();
    return 0;
}
