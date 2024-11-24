#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <cstring>

using namespace std;

void setColor(int color) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color); //allows me to change the color of text in the console

}



void displayMenu(int Chosen) { //creates a menu




    const string options[] = { //defines what the menu options are
        "Play the Game",
        "Instructions",
        "Quit"
    };

    system("cls"); //clears the screen

    cout << "__          ______  _____  _____  _  __     __" << endl;
    cout << "\\ \\        / / __  \\| __ \\|  __ \\| | \\ \\   / /" << endl;
    cout << " \\ \\  /\\  / / |  | | |__) | |  | | |  \\ \\_/ / " << endl;
    cout << "  \\ \\/  \\/ /| |  | |  _  /| |  | | |   \\   /  " << endl;
    cout << "   \\  /\\  / | |__| | | \\ \\| |__| | |____| |   " << endl;
    cout << "    \\/  \\/   \\____/|_|  \\_\\_____/|______|_|   " << endl; //title

    for (int i = 0; i < 3; i++) { //the cycle is what makes you aware of the option you've chosen

        if (i == Chosen) {

            setColor(2);
            cout << "->  " << options[i] << endl;

        }
        else {

            setColor(7);
            cout << options[i] << endl;

        }

    }


}

int main()
{

    int Chosen = 0;
    const int OptionsCount = 3;



    while (true) {


        displayMenu(Chosen); //displays the menu


        while (true) {

            if (GetAsyncKeyState(VK_UP) & 0x8000) { //it's used for identifying the arrow key

                Chosen = (Chosen - 1 + OptionsCount) % OptionsCount;
                break;

            }

            if (GetAsyncKeyState(VK_DOWN) & 0x8000) { //it's used for identifying the arrow key
                Chosen = (Chosen + 1) % OptionsCount;
                break;
            }

            if (GetAsyncKeyState(VK_RETURN) & 0x8000) { //same thing as the other 2 comments, except this is for the enter/return key

                system("cls"); //clears the screen so that new information is displayed

                switch (Chosen) {

                case 0: {

                    string arr2[100];
                    int index_arr2;
                    bool Symbol = false;
                    int attempts = 6;
                    string arrWords[5] = { "radio", "where", "pupil", "games", "fifth" };

                    srand(time(0));
                    int randomWordNumber = rand() % 5; //izbira random duma
                    string randomWord = arrWords[randomWordNumber];  //tuk sum proverqval

                    for (int i = 0; i < attempts; i++)
                    {
                        cin >> arr2[i];
                        if (int(arr2[i].length()) == 5)
                        {
                            cout << "OK!" << endl;
                        }
                        else
                        {
                            cout << "Please type only words with 5 letters! (+1 attempt)" << endl;
                            ++attempts;
                        }
                        index_arr2 = i;
                        if (int(arr2[index_arr2][i]) < 65 || int((arr2[index_arr2][i]) > 90 && int(arr2[index_arr2][i]) < 97) || int(arr2[index_arr2][i]) > 122)
                        {

                            Symbol = true;
                            cout << "Work!!!" << endl;


                        }
                        else
                        {


                            for (int i = 0; i < 5; i++)
                            {

                                for (int y = 0; y < 5; y++)
                                {

                                    if (int(arr2[index_arr2][y]) >= 65 && int(arr2[index_arr2][y]) <= 90)
                                    {

                                        arr2[index_arr2][y] = char(int(arr2[index_arr2][y]) + 32); //if the letter is capital it turns it into lowercase

                                    }
                                    else
                                    {
                                        arr2[index_arr2][y] = arr2[index_arr2][y];
                                    }

                                }
                                if (arr2[index_arr2][i] == randomWord[i])
                                {
                                    setColor(2);
                                    cout << arr2[i]; //checks if the letter is in the correct place

                                }
                                else
                                {

                                    bool DiffPosition = false;

                                    for (int k = 0; k < 5; k++) { //checks if the letter is in any other place in the word
                                        if (arr2[index_arr2][i] == randomWord[k]) {
                                            setColor(6);
                                            cout << arr2[index_arr2][i];
                                            DiffPosition = true;
                                            break;
                                        }
                                    }


                                    if (!DiffPosition) { //if it's not there it will color blue
                                        setColor(9);
                                        cout << arr2[index_arr2][i];

                                    }
                                }



                                setColor(7);//brings back the default color of the text


                            }
                        }
                    }

                    break;


                }

                case 1:

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

                    if (GetAsyncKeyState(VK_RETURN) & 0x8000) {

                        Sleep(6500);

                        system("cls");

                        return main();

                    }

                    break;



                case 2:

                    cout << "Exiting, ...";
                    return 0;

                }

                setColor(7);
                cin.ignore();
                cin.get();

                return 0;

            }


        }

        Sleep(150);

    }


}
