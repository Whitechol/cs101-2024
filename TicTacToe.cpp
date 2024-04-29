#include <iostream>

using namespace std;

class TicTacToe {
    private:
        char state[9];
        int input;
        bool round_player1;
        bool game_over;
        
        void Initialize() {
            char tmp = '1';
            for (int i = 0; i < 9; i++) 
                state[i] = tmp++;
            game_over = 0;
            round_player1 = 0;
            PrintState();
            CheckStatus();
        }
        
        void PrintState() {
            for (int i = 0; i < 9; i++) {
                cout << " " << state[i] << " ";
                (i == 8) ? cout << endl : (i == 2 || i == 5) ? cout << "\n---+---+---\n" : cout << "|";
            }
        }
        
        void CheckStatus() {
            char tmp;
            bool draw = 0;
            (round_player1) ? tmp = 'X' : tmp = 'O';
            for (int i = 1; i <= 4; i++) {
                if (state[4-i] == tmp && state[4] == tmp && state[4+i] == tmp || (i == 1 || i == 4) && state[i*2-2] == tmp && state[i*2-1] == tmp && state[i*2] == tmp || (i == 2 || i == 3) && state[i*2-4] == tmp && state[i*2-1] == tmp && state[i*2+2] == tmp) {
                    game_over = 1;
                    break;
                }
            }
            for (int i = 0; i < 9; i++) {
                if (state[i] >= '1' && state[i] <= '9')
                    break;
                if (i == 8)
                    draw = 1;
            }
            if (game_over && !draw) {
                if (round_player1)
                    cout << "==> Player 1 wins!\n";
                else
                    cout << "==> Player 2 wins!\n";
            }
            else if (draw) {
                cout << "==> Game draw\n";
                game_over = 1;
            }
            else {
                (round_player1) ? round_player1 = 0 : round_player1 = 1;
                if (round_player1)
                    cout << "==> Player 1 (X), enter a number:";
                else
                    cout << "==> Player 2 (O), enter a number:";
            }
        }
        
        
    public:
        void run() {
            cout << "-- Tic Tac Toe -- CSIE@CGU\nPlayer 1 (X) - Player 2 (O)\n";
            Initialize();
            while (!game_over) {
               cin >> input;
               while (input < 1 || input > 9 || state[input-1] == 'O' || state[input-1] == 'X') {
                    if (cin.fail()) {
                       cin.clear();
                       cin.ignore();
                    }
                    cout << "==> Invalid value, please enter again\n";
                    (round_player1) ? cout << "==> Player 1 (X), enter a number:" : cout << "==> Player 2 (O), enter a number:";
                    cin >> input;
                }
                (round_player1) ? state[input-1] = 'X' : state[input-1] = 'O';
                PrintState();
                CheckStatus();
            }
        }
        
};

int main()
{
    TicTacToe game;
    game.run();
    return 0;
}
