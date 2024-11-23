#include <iostream>

using namespace std;

int main()
{

    char arr[5];

    for (int i = 0; i < 5; i++) {

        cin >> arr[i];//въвеждане на думата

    }

    for (int i = 0; i < 5; i++) {

        if (arr[i] >= 65 && arr[i] <= 90) {

            arr[i] = arr[i] + 32; //ако буквата е главна, я превръща в малка

        }
        else {

            arr[i] = arr[i];

        }

    }

    for (int i = 0; i < 5; i++) {

        cout << arr[i];//това е тук за изпробване на кода, да изтрие като се съединяват кодовете

    }

}
