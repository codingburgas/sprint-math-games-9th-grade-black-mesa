#include <iostream>
#include <windows.h>

using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);//позволява да се оцветяват буквите
}

int main() {
    char arr1[5] = { 'r', 'a', 'd', 'i', 'o' }; //това трябва да се изтрие като се съединяват кодовете, тук е само да покаже как работи кода
    char arr2[5];

    for (int i = 0; i < 5; i++) {
        cin >> arr2[i];//въвежда се думата
    }


    for (int i = 0; i < 5; i++) {

        

            if (arr2[i] == arr1[i]) {
                setColor(2);
                cout << arr2[i]; //проверява дали буквата е на правилното място

            }
            else {

                bool DiffPosition = false;

                for (int k = 0; k < 5; k++) { //този цикъл проверява дали буквата я има на някое друго място в думата
                    if (arr2[i] == arr1[k]) {
                        setColor(6);
                        cout << arr2[i];
                        DiffPosition = true;
                        break;
                    }
                }


                if (!DiffPosition) { //ако буквата не е там я оцветява в синьо
                    setColor(9);
                    cout << arr2[i];
                }
            }

            

            setColor(7);//връща основния цвят на буквите


    }
}




        



