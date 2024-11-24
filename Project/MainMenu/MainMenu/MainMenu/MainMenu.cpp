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
            setColor(2); // Highlight the selected option
            cout << "->  " << options[i] << endl;
        }
        else {
            setColor(7); // Default color for unselected options
            cout << "    " << options[i] << endl;
        }
    }
    setColor(7); // Reset color after the menu


}


void gameCode(){
    bool Symbol = false;
    string Word[100];
    int index_Word;
    int attempts = 6; //v wordle ima 6 attempta
    string arrWords[5] = { "radio", "where", "pupil", "games", "fifth" };

    srand(time(0));
    int randomWordNumber = rand() % 5; //izbira random num
    string randomWord = arrWords[randomWordNumber];  //izbira eandom duma ot string i rand num

    for (int i = 0; i < attempts; i++)
    {
        cin >> Word[i]; //vuvejda se dumata
        index_Word = i;

        for (int index_num = 0; index_num < 5; index_num++)
        {
            if (int(Word[index_Word][index_num]) < 65 && int((Word[index_Word][index_num]) > 90 || (int(Word[index_Word][index_num]) < 97) && int(Word[index_Word][index_num]) > 122)) //proverqva dali v dumata ima simvoli
            {
                Symbol = true;
            }
        }
        if (Symbol == true)
        {
            cout << "Please don't type any symbols!" << endl;
            ++attempts;
            Symbol = false;
        }
        else
        {
            if (int(Word[i].length()) == 5) //proverqva dali dumata  e ot 5 bukvi
            {
                for (int index_num = 0; index_num < 5; index_num++)
                {

                    for (int y = 0; y < 5; y++)
                    {

                        if (int(Word[index_Word][y]) >= 65 && int(Word[index_Word][y]) <= 90)
                        {

                            Word[index_Word][y] = char(int(Word[index_Word][y]) + 32); //prevrushta glavni bukvi v malki

                        }
                        else
                        {
                            Word[index_Word][y] = Word[index_Word][y];
                        }

                    }
                    if (Word[index_Word][index_num] == randomWord[index_num])
                    {
                        setColor(2);
                        cout << Word[index_Word][index_num]; //proverqva dali bukvata e na pravilnoto mqsto

                    }
                    else
                    {

                        bool DiffPosition = false;

                        for (int k = 0; k < 5; k++)//proverqva dali edna ot buvite na tursenata dume a na rzlichno mqsto i q ocvetqva v julto
                        {
                            if (Word[index_Word][index_num] == randomWord[k])
                            {
                                setColor(6);
                                cout << Word[index_Word][index_num];
                                DiffPosition = true;
                                break;
                            }
                        }


                        if (!DiffPosition) //ako bukvata q nqma v tursenata  duma tq se ocvetqva v sinqo
                        {
                            setColor(9);
                            cout << Word[index_Word][index_num];
                        }
                    }



                    setColor(7);//vrushta osnovniq cvqt na bukvite

                }
            }
            else
            {
                cout << "Please type only words with 5 letters!" << endl;
                ++attempts; //uvelichava attempts za da  uvelichi opitite
            }
            if (Word[index_Word] == randomWord)
            {
                cout << endl << "Congratulations you won!";
                break;
            }
            cout << endl;
        }
    }
}



int main()
{

    int Chosen = 0;
    const int OptionsCount = 3;



    while (true) {


        displayMenu(Chosen);


        while (true)
        {

            if (GetAsyncKeyState(VK_UP) & 0x8000)
            {

                Chosen = (Chosen - 1 + OptionsCount) % OptionsCount;
                break;

            }

            if (GetAsyncKeyState(VK_DOWN) & 0x8000)
            {
                Chosen = (Chosen + 1) % OptionsCount;
                break;
            }

            if (GetAsyncKeyState(VK_RETURN) & 0x8000)
            {

                if (GetAsyncKeyState(VK_RETURN) & 0x8000)
                {
                    Sleep(1000);
                    system("cls"); //Clear screen when selecting an option

                    switch (Chosen) 
                    {
                    case 0:
                        gameCode(); // Start game [Updated]
                        break;

                    case 1: // Show instructions
                        system("cls"); //Clears menu for instructions
                        cout << "You have 6 attempts. To win, guess the word." << endl;
                        cout << "If the letter is in the correct position, it will light up in ";
                        setColor(2);
                        cout << "green";
                        setColor(7);
                        cout << "." << endl;

                        cout << "If the letter is in the word but in the wrong position, it will light up in ";
                        setColor(6);
                        cout << "yellow";
                        setColor(7);
                        cout << "." << endl;

                        cout << "If the letter is not in the word, it will light up in ";
                        setColor(9);
                        cout << "blue";
                        setColor(7);
                        cout << "." << endl;
                        cin.ignore(); //Wait for user to press Enter**
                        cin.get();
                        break;

                    case 2:
                        cout << "Exiting, ...";
                        return 0;


                        setColor(7);
                        cin.ignore();
                        cin.get();

                        return 0;

                    }


                }

                Sleep(1000);
                system("cls");

            }


        }
    }
}