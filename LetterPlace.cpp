#include <iostream>
#include <windows.h>

using namespace std;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);//��������� �� �� ��������� �������
}

int main() {
    char arr1[5] = { 'r', 'a', 'd', 'i', 'o' }; //���� ������ �� �� ������ ���� �� ���������� ��������, ��� � ���� �� ������ ��� ������ ����
    char arr2[5];

    for (int i = 0; i < 5; i++) {
        cin >> arr2[i];//������� �� ������
    }


    for (int i = 0; i < 5; i++) {

        

            if (arr2[i] == arr1[i]) {
                setColor(2);
                cout << arr2[i]; //��������� ���� ������� � �� ���������� �����

            }
            else {

                bool DiffPosition = false;

                for (int k = 0; k < 5; k++) { //���� ����� ��������� ���� ������� � ��� �� ����� ����� ����� � ������
                    if (arr2[i] == arr1[k]) {
                        setColor(6);
                        cout << arr2[i];
                        DiffPosition = true;
                        break;
                    }
                }


                if (!DiffPosition) { //��� ������� �� � ��� � �������� � �����
                    setColor(9);
                    cout << arr2[i];
                }
            }

            

            setColor(7);//����� �������� ���� �� �������


    }
}




        



