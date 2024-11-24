#include <iostream>

#include <windows.h>

#include <iomanip>

#include <cstdlib> // For random number generation (rand and srand)

#include <cstring> // For string manipulation

using namespace std;

// Function to set the console text color

void setColor(int color) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get console handle

    SetConsoleTextAttribute(hConsole, color); // Set text color

}

// Function to display the main menu

void displayMenu(int Chosen)

{

    const string options[] = // Array of menu options

    {

        "                            Play the Game",

        "                            Instructions",

        "                            Quit"

    };

    system("cls"); // Clear the screen

    cout << "                            __          ______  _____  _____  _  __     __" << endl;

    cout << "                            \\ \\        / / __  \\| __ \\|  __ \\| | \\ \\   / /" << endl;

    cout << "                             \\ \\  /\\  / / |  | | |__) | |  | | |  \\ \\_/ / " << endl;

    cout << "                              \\ \\/  \\/ /| |  | |  _  /| |  | | |   \\   /  " << endl;

    cout << "                               \\  /\\  / | |__| | | \\ \\| |__| | |____| |   " << endl;

    cout << "                                \\/  \\/   \\____/|_|  \\_\\_____/|______|_|   " << endl;

    // loop through and display the menu options

    for (int i = 0; i < 3; i++) {

        if (i == Chosen) { // highlight the currently selected option

            setColor(2); // green for the current selected option

            cout << " --------->  " << options[i] << endl;

        }

        else {

            setColor(7); // white for other options

            cout << options[i] << endl;

        }

    }

}

int main()

{

    int Chosen = 0; // tracks the currently selected menu option

    const int OptionsCount = 3; // total number of menu options

    while (true)

    {

        displayMenu(Chosen);

        while (true)

        {

            // checks if the "up" arrow key is pressed

            if (GetAsyncKeyState(VK_UP) & 0x8000)

            {

                Chosen = (Chosen - 1 + OptionsCount) % OptionsCount; // Move selection up

                break;

            }

            // checks if the "down" arrow key is pressed

            if (GetAsyncKeyState(VK_DOWN) & 0x8000)

            {

                Chosen = (Chosen + 1) % OptionsCount; // Move selection down

                break;

            }

            // checks if the "enter" key is pressed

            if (GetAsyncKeyState(VK_RETURN) & 0x8000)

            {

                system("cls"); // Clear the screen

                switch (Chosen)

                {

                case 0:

                { // Play the game

                    string Word[1000];

                    int index_Word; // tracks the index of the current guess

                    bool Symbol = false; // flag to check for invalid symbols

                    int attempts = 6; // number of attempts allowed

                    string arrWords[16] = { "radio", "where", "pupil", "games", "fifth", "labor", "hurry", "tower", "class", "sleep", "drive", "quick", "human", "story", "rough", "might" }; // word list

                    srand(time(0)); // seed for random number generation

                    int randomWordNumber = rand() % 16; // choose a random word

                    string randomWord = arrWords[randomWordNumber]; // randomly chosen word

                    for (int i = 0; i < attempts; i++) {

                        cin >> Word[i]; // take input for the guessed word

                        index_Word = i;

                        // check if the word has 5 letters

                        if (int(Word[i].length()) == 5) {

                            for (int index_num = 0; index_num < 5; index_num++) {

                                // check for invalid symbols in the word

                                if (int(Word[index_Word][index_num]) < 65 || int((Word[index_Word][index_num]) > 90 && (int(Word[index_Word][index_num]) < 97) || int(Word[index_Word][index_num]) > 122)) {

                                    Symbol = true;

                                }

                            }

                            if (Symbol == true)

                            {

                                cout << "Please don't type any symbols!" << endl;

                                ++attempts; // restore user's attempt for invalid input

                                Symbol = false; // reset symbol flag

                            }

                            else

                            {

                                for (int index_num = 0; index_num < 5; index_num++)

                                {

                                    for (int y = 0; y < 5; y++) {

                                        if (int(Word[index_Word][y]) >= 65 && int(Word[index_Word][y]) <= 90)

                                        {

                                            Word[index_Word][y] = char(int(Word[index_Word][y]) + 32); //convert uppercase to lowercase

                                        }

                                    }

                                    // Check if the letter is in the correct position

                                    if (Word[index_Word][index_num] == randomWord[index_num])

                                    {

                                        setColor(2); // Green for correct position

                                        cout << "[" << Word[index_Word][index_num] << "]";

                                    }

                                    else {

                                        bool DiffPosition = false;

                                        // check if the letter exists in the word but in a different position

                                        for (int k = 0; k < 5; k++)

                                        {

                                            if (Word[index_Word][index_num] == randomWord[k])

                                            {

                                                setColor(6); // Yellow for correct letter but wrong position

                                                cout << "[" << Word[index_Word][index_num] << "]";

                                                DiffPosition = true;

                                                break;

                                            }

                                        }

                                        if (!DiffPosition)

                                        {

                                            setColor(9); // blue for incorrect letter

                                            cout << "[" << Word[index_Word][index_num] << "]";

                                        }

                                    }

                                    setColor(7); //reset text color to white

                                }

                                //check if the word matches the random word

                                if (Word[index_Word] == randomWord) {

                                    cout << endl << "Congratulations you won!";

                                    break;

                                }

                                cout << endl;

                            }

                        }

                        else

                        {

                            cout << "Please type only words with 5 letters!" << endl;

                            ++attempts; //restore attempt for invalid input

                        }

                    }

                    break;

                }

                case 1: // instructions

                    cout << "You have 6 attempts. To win you must guess the word. If the letter is in the correct place it will light up in ";

                    setColor(2);

                    cout << "green";

                    setColor(7);

                    cout << ". If the letter is in the word, but not in the correct spot it will light up in ";

                    setColor(6);

                    cout << "yellow";

                    setColor(7);

                    cout << ". If it's not there it will light up in ";

                    setColor(3);

                    cout << "blue.";

                    setColor(7);

                    if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // wait for Enter to return to the menu

                        Sleep(6500);

                        system("cls");

                        return main(); // return to main menu

                    }

                    break;

                case 2: // quit the game

                    cout << "Exiting, ...";

                    return 0;

                }

                setColor(7); // Reset text color

                cin.ignore(); // ignore leftover input

                cin.get(); // wait for user input

                return 0;

            }

        }

        Sleep(150);

    }

}

