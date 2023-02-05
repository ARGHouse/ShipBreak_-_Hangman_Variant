/*                              ShipBreaker - A Hangman variant
*
*                                          By ARGHouse
    1. Give player a choice whether to play or quite
    2. Give player a choice of various difficulties
    3. Create a group of words
    4. Pick a random word from the group to act as the secret word
    5. While - The player has not made too many incorrect guesses AND hasn't guessed the secret word:
        1. Tell player how many incorrect guesses they has left
        2. Show players the letters they have guessed
    6. Show players how much of the secret word they have guessed.
    7. Get Player's next guess
    8. While - player has entered a secret letter that they have have already guessed
        1. Get Player's guess
    9. Add the new guess to the group of used letters
    10. If the guess is in the secret word:
        1. Tell the Player that the guess is correct
        2. Update the word guessed so far with the new letter
    11. Otherwise
        1. Tell the Player that the guess is incorrect
        2. Increment the number of incorrect guesses the player has made
    12. If the player has made too many incorrect guesses:
        1. Tell the player that their ship has been Broken.
    13. Otherwise
        1. Congratulate the player on guessing the secret word and saving their ship from near destruction

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cctype>

using namespace std;

int main() {

    const enum difficulties { HARMLESS, MOSTLY_HARMLESS, NOVICE, COMPETENT, EXPERT, MASTER, DANGEROUS, DEADLY, ELITE, NUM_DIFFICULTIES };

    int MAX_WRONG;

    vector<string> words;
    words.push_back("SHIP");
    words.push_back("WARP");
    words.push_back("CORE");
    words.push_back("DRIVE");
    words.push_back("REACTOR");
    words.push_back("THRUSTER");
    words.push_back("LIFESUPPORT");
    words.push_back("SHIELD");
    words.push_back("COCKPIT");
    words.push_back("BRIDGE");
    words.push_back("ENGINEERING");
    words.push_back("COMPUTER");
    words.push_back("HULL");
    words.push_back("BULKHEAD");
    words.push_back("RADIATOR");
    words.push_back("JUMP");
    words.push_back("GENERATOR");
    words.push_back("CARGOHOLD");
    words.push_back("LANDINGGEAR");
    words.push_back("POWERDISTRIBUTOR");
    words.push_back("AFMU");
    words.push_back("SENSOR");
    words.push_back("COMMS");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];           //word to guess
    int wrong = 0;                              //number of incorrect guesses
    string soFar(THE_WORD.size(), '-');         //word guessed so far
    string used = "";                           //letters already guessed

    cout << " Welcome to ShipBreak. Good Luck! \n";

    int playChoice;

    cout << "[1] - Play/Again\n[2] - Quit\n"; cin >> playChoice;
    while ((playChoice > 0) && (playChoice < 2))
    {
        switch (playChoice)
        {

        case 1:            cout << "Ready to play";

            cout << " The are " << NUM_DIFFICULTIES << " difficulty levels.\n";

            cout << "\n These are the levels of difficulty, input number to chose\n";

            cout << "[1] - HARMLESS\n[2] - MOSTLY HARMLESS\n[3] - NOVICE\n[4] - COMPETENT\n[5] - EXPERT\n[6] - MASTER\n[7] - DANGEROUS\n[8] - DEADLY\n[9] - ELITE\n";

            int choice;
            cout << " Choice: "; cin >> choice;

            while ((choice > 0) && (choice < 10))
            {
                switch (choice)
                {

                case 1:
                    cout << "You are HARMLESS.\n";
                    MAX_WRONG = 9;
                    break;
                case 2:                    cout << "You are MOSTLY HARMLESS.\n";
                    MAX_WRONG = 8;                    break;                case 3:                    cout << "You are NOVICE.\n";                    MAX_WRONG = 7;
                    break;
                case 4:                    cout << "You are COMPETENT.\n";
                    MAX_WRONG = 6;                    break;                case 5:                    cout << "You are an EXPERT.\n";                    MAX_WRONG = 5;                    break;                case 6:                    cout << "You are a MASTER.\n";                    MAX_WRONG = 4;                    break;                case 7:                    cout << "You are DANGEROUS.\n";                    MAX_WRONG = 3;                    break;                case 8:                    cout << "You are DEADLY.\n";
                    MAX_WRONG = 2;                    break;                case 9:                    cout << "You are ELITE!\n";                    MAX_WRONG = 1;                    break;
                default:                    cout << "WRONG INPUT!\n";
                }

                //main loop

                while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
                {
                    cout << "\n\nYou have " << (MAX_WRONG - wrong);
                    cout << " incorrect guesses left. \n";
                    cout << "\nYou've used the following letters: \n" << used << endl;
                    cout << "\nSo far, the word is: \n" << soFar << endl;

                    char guess;
                    cout << "\n\nEnter your guess: ";
                    cin >> guess;
                    guess = toupper(guess); //make uppercase
                    while (used.find(guess) != string::npos)
                    {

                        cout << "\nYou've already guessed " << guess << endl;                        cout << " Enter your guess: ";                        cin >> guess;                        guess = toupper(guess);
                    }

                    used += guess;
                    if (THE_WORD.find(guess) != string::npos)
                    {

                        cout << "That's right!" << guess << " is in the word.\n";
                        //update soFar to include newly guessed word
                        for (int i = 0; i < THE_WORD.length(); ++i)
                        {

                            if (THE_WORD[i] == guess)
                            {
                                soFar[i] = guess;
                            }

                        }

                    }
                    else {
                        cout << "\nSorry, " << guess << " isn't in the word.\n";
                        ++wrong;
                    }
                }

                //shut down

                if (wrong == MAX_WRONG)
                {
                    cout << "\nYou're ship has been torn apart!\n";

                    cout << "[1] - Play/Again\n[2] - Quit\n"; cin >> playChoice;

                }
                else
                {
                    cout << "\nYou got it right, your ship is spared its fate!\n";

                    cout << "\nThe word was " << THE_WORD << "\n";                    cout << "[1] - Play/Again\n[2] - Quit\n"; cin >> playChoice;
                }

                

            }
        break;

        case 2:
            cout << "\nEnding program.\n";

            break;

        default:
            cout << "\nWRONG INPUT!\n";

            cout << "[1] - Play/Again\n[2] - Quit\n"; cin >> playChoice;

        }

    }

    return 0;
    system("PAUSE");

}

/*

Current bugs:
    1. Play Again option menu at the end not working

*////////////////////////////////