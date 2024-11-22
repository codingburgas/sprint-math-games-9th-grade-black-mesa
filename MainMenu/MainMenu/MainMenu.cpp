#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

void setColor(int color) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);

}



void displayMenu(int Chosen) {
    
    


    const string options[] = {
        "Play the Game",
        "Instructions",
        "Quit"
    };

    system("cls");

    cout << "__          ______  _____  _____  _  __     __" << endl;
    cout << "\\ \\        / / __  \\| __ \\|  __ \\| | \\ \\   / /" << endl;
    cout << " \\ \\  /\\  / / |  | | |__) | |  | | |  \\ \\_/ / " << endl;
    cout << "  \\ \\/  \\/ /| |  | |  _  /| |  | | |   \\   /  " << endl;
    cout << "   \\  /\\  / | |__| | | \\ \\| |__| | |____| |   " << endl;
    cout << "    \\/  \\/   \\____/|_|  \\_\\_____/|______|_|   " << endl;

    for (int i = 0; i < 3; i++) {

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

        
        displayMenu(Chosen);


        while (true) {

            if (GetAsyncKeyState(VK_UP) & 0x8000) {

                Chosen = (Chosen - 1 + OptionsCount) % OptionsCount;
                break;

            }

            if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                Chosen = (Chosen + 1) % OptionsCount;
                break;
            }

            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {

                system("cls");

                switch (Chosen) {

                case 0:
                    cout << "Game"; //тук се слага кода за самата игра
                    break;
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

