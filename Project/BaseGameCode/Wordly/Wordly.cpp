#include <iostream>
#include <cstdlib> //za srand i rand
#include <windows.h> //za cvqt
#include <cstring> //za string

using  namespace std;
void setColor(int color) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);//позволява да се оцветяват буквите
}

int main()
{
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

                        arr2[index_arr2][y] = char(int(arr2[index_arr2][y]) + 32); //ако буквата е главна, я превръща в малка

                    }
                    else
                    {
                        arr2[index_arr2][y] = arr2[index_arr2][y];
                    }

                }
                if (arr2[index_arr2][i] == randomWord[i])
                {
                    setColor(2);
                    cout << arr2[i]; //проверява дали буквата е на правилното място

                }
                else
                {

                    bool DiffPosition = false;

                    for (int k = 0; k < 5; k++) { //този цикъл проверява дали буквата я има на някое друго място в думата
                        if (arr2[index_arr2][i] == randomWord[k]) {
                            setColor(6);
                            cout << arr2[index_arr2][i];
                            DiffPosition = true;
                            break;
                        }
                    }


                    if (!DiffPosition) { //ако буквата не е там я оцветява в синьо
                        setColor(9);
                        cout << arr2[index_arr2][i];
                    }
                }



                setColor(7);//връща основния цвят на буквите


            }
        }
    }
}