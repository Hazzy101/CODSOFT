#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberGuessingGame 
{
public:
    NumberGuessingGame() 
    {
        srand(static_cast<unsigned>(time(nullptr))); // Seed with the current time for randomness
        score = 0;
    }

    void play()
    {
        while (true) 
        {
            displayWelcomeMessage();
            int opt = getRangeOption();
            int number = generateRandomNumber(opt);
            playGame(number);
            char opt1;
            cout << "Would You Like To Go Again? y/n : ";
            cin >> opt1;

            if (opt1 != 'Y' && opt1 != 'y')
            {
                cout << "The End" << endl;
                cout << "Your Score is : " << score << endl;
                break;
            }
            system("cls"); // Clear the screen for the next game
        }
    }

private:
    int score;

    void displayWelcomeMessage() 
    {
        cout << "Welcome!\nGuess The Random Number\n";
        cout << "Choose The Range For Your Turn" << endl;
        cout << "1. 0 - 100\n2. 0 - 1000\n3. 0 - 10000\n4. -200 - 200\n";
    }

    int getRangeOption() 
    {
        int opt;
        cin >> opt;
        return opt;
    }

    int generateRandomNumber(int opt) 
    {
        switch (opt)
        {
        case 1:
            return rand() % 101;
        case 2:
            return rand() % 1001;
        case 3:
            return rand() % 10001;
        case 4:
            return (rand() % 401) - 200; // so we get number between the range
        default:
            return 0; // Handle invalid input
        }
    }

    void playGame(int number) 
    {
        int guess;
        system("cls");

        cout << "Guess The Random Number (-999 to exit) : ";
        while (true) 
        {
           
            cin >> guess;
            if (guess == number) 
            {
                cout << "Congratulations! You Won\nThe Number was " << number << endl;
                score++;
                break;
            }
            else if (guess == -999) // checking this case first for better flow
            {
                cout << "You Lost\nThe Number Was " << number << endl;
                break;
            }
            else if (guess < number) 
            {
                cout << "Guess Is Smaller than the Number" << endl;
            }
            else if (guess > number)
            {
                cout << "Guess Is Greater than the Number" << endl;
            }
        }
    }
};

int main() 
{
    NumberGuessingGame player1;
    player1.play();
    return 0;
}