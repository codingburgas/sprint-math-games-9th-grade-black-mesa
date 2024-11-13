#include <iostream>
using namespace std;
int main()
{
    int game;
    cout << "Menu:" << endl;
    cout << "1:Play Game" << endl;
    cout << "2:Help (press 2)" << endl;
    cin >> game;
    switch (game) {
    case 1:
        cout << "";
        break;
    case 2:
        cout << "To play the game first press 1 to start and then write a five letter word. You have 6 tries to guess the word. When you enter a word and you do not guess the correct one but you have a letter/letters that are in the correct word it will be coloured with yellow.If there is a letter/letters that is in the correct place it is coloured in green.";
        break;
    }
}