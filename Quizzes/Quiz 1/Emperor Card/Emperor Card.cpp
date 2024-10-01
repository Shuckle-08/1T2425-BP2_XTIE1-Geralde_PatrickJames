#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int wager(int roundNum, int& mmLeft, int& moneyEarned) {
    int playerInput;

    cout << "Round: " << roundNum << endl;
    cout << "Money Earned: " << moneyEarned << endl;
    cout << "mmLeft: " << mmLeft << endl;

    cout << "How much mm would you like to wager? " << endl;
    cin >> playerInput;

    if (playerInput > mmLeft || playerInput < 1) {
        cout << "You can't wager more than what you have left or less than 1" << endl;
        system("pause");
        system("cls");
        return wager(roundNum, mmLeft, moneyEarned);
    }

    mmLeft -= playerInput;
    return playerInput;
}

void fillHand(vector<string>& playerHand, vector<string>& aiHand, int round, char& side) {
    playerHand.clear();
    aiHand.clear();

    if (round == 1 || round == 2 || round == 3 || round == 7 || round == 8 || round == 9) {
        side = 'e';
        playerHand.push_back("Emperor");
        aiHand.push_back("Slave");
    }
    else {
        side = 's';
        playerHand.push_back("Slave");
        aiHand.push_back("Emperor");
    }

    for (int x = 1; x < 5; x++) {
        playerHand.push_back("Civilian");
        aiHand.push_back("Civilian");
    }
}

string playerTurn(vector<string>& playerHand) {
    int playerInput;

    cout << "Which card would you like to use?  ";
    cin >> playerInput;

    if (playerInput < 1 || playerInput > playerHand.size()) {
        cout << "Invalid Selection. Please select a valid card." << endl;
        return playerTurn(playerHand); // No need to pass playerSelection
    }

    playerInput--; // Convert to zero-based index
    string playerCard = playerHand[playerInput];
    playerHand.erase(playerHand.begin() + playerInput);
    return playerCard;
}

string aiTurn(vector<string>& aiHand) {
    int aiSelection = rand() % aiHand.size();
    string aiCard = aiHand[aiSelection];
    aiHand.erase(aiHand.begin() + aiSelection);
    return aiCard;
}

void evaluate(string playerSelection, string aiSelection, char side, int& moneyEarned, int wagered, bool& inPlay) {
    int payout = (side == 'e') ? wagered * 100000 : wagered * 500000;

    cout << endl;
    cout << "You played " << playerSelection << " and the AI played " << aiSelection << endl;

    if (playerSelection == aiSelection) {
        cout << "~~~ DRAW ~~~" << endl << endl;
        return; // Continue the round
    }

    if ((playerSelection == "Emperor" && aiSelection == "Civilian") ||
        (playerSelection == "Slave" && aiSelection == "Emperor") ||
        (playerSelection == "Civilian" && aiSelection == "Slave")) {
        cout << "~~~~ YOU WON " << payout << " YEN ~~~" << endl << endl;
        moneyEarned += payout;
    }
    else {
        cout << "YOU LOST" << endl;
    }

    inPlay = false; // End round after win/loss
    system("pause");
    system("cls");
}

void playRound(vector<string> playerHand, vector<string> aiHand, int roundNum, int& moneyEarned, int& mmLeft, char side, int wagered) {
    string playerSelection, aiSelection;
    bool inPlay = true;

    cout << endl;

    while (inPlay) {
        // Display Hands
        cout << "Your Hand:" << setw(25) << "Enemy Hand:" << endl;
        for (int x = 0; x < playerHand.size(); x++) {
            cout << "Card " << x + 1 << " : " << playerHand[x] << setw(15) << "Card " << x + 1 << " : " << aiHand[x] << endl;
        }

        playerSelection = playerTurn(playerHand);
        aiSelection = aiTurn(aiHand);
        evaluate(playerSelection, aiSelection, side, moneyEarned, wagered, inPlay);
    }
}

int main() {
    srand(time(0));

    // Initialize 
    char side;
    int roundNum = 1;
    int mmLeft = 30;
    int moneyEarned = 0;

    vector<string> playerHand, aiHand;

    while (roundNum < 12 && mmLeft > 0) {
        fillHand(playerHand, aiHand, roundNum, side);
        int wagered = wager(roundNum, mmLeft, moneyEarned);
        playRound(playerHand, aiHand, roundNum, moneyEarned, mmLeft, side, wagered);
        roundNum++;
    }

    if (roundNum > 12 && mmLeft > 0 && moneyEarned >= 20000000) {
        cout << "YOU HAVE ACHIEVE BEST ENDING" << endl;
        system("pause");
        system("cls");
    }
    else if (roundNum > 12 && mmLeft > 0 && moneyEarned < 20000000) {
        cout << "YOU HAVE ACHIEVE THE MEH ENDING" << endl;
        system("pause");
        system("cls");
    }
    else if (roundNum <= 12 && mmLeft < 0) {
        cout << "YOU HAVE LOST YOUR EAR DRUM" << endl;
        system("pause");
        system("cls");
    }

    return 0;
}
