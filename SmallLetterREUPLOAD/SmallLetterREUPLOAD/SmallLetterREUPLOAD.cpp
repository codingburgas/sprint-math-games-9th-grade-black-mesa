#include <iostream>

using namespace std;

int main()
{

    char arr[5];

    for (int i = 0; i < 5; i++) {

        cin >> arr[i];//��������� �� ������

    }

    for (int i = 0; i < 5; i++) {

        if (arr[i] >= 65 && arr[i] <= 90) {

            arr[i] = arr[i] + 32; //��� ������� � ������, � �������� � �����

        }
        else {

            arr[i] = arr[i];

        }

    }

    for (int i = 0; i < 5; i++) {

        cout << arr[i];//���� � ��� �� ���������� �� ����, �� ������ ���� �� ���������� ��������

    }

}
