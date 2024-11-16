#include <iostream>

using namespace std;

int main()
{
    bool Symbol;
    char arr[5];
    
    for (int i = 0; i < 5; i++) {

        cin >> arr[i];

    }

    for (int i = 0; i < 5; i++) {

        if (arr[i] < 65 || (arr[i] > 90 && arr[i] < 97) || arr[i] > 122) {

            Symbol = true;

        }

    }

    if (Symbol = true) {
        cout << "You can't put symbols";
    }

}

 