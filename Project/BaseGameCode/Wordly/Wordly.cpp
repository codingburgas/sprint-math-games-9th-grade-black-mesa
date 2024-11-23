#include <iostream>
#include <cstdlib> //za srand i rand
#include <windows.h> //za cvqt
#include <cstring> //za string

using  namespace std;
void setColor(int color) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);//pozvolqva da se ocvetqt bukvite
}

int main()
{
    bool Symbol=false;
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

        for(int index_num=0; index_num<5; index_num++)
        {
            if (int(Word[index_Word][index_num]) < 65 && int((Word[index_Word][index_num]) > 90 || (int(Word[index_Word][index_num]) < 97) && int(Word[index_Word][index_num]) > 122)) //proverqva dali v dumata ima simvoli
            {
                Symbol = true;
            }
        }
        if(Symbol == true)
        {
            cout << "Please don't type any symbols!" << endl;
            ++attempts;
            Symbol=false;
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