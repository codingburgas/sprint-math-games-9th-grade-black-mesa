#include <iostream>
#include <fstream>   //for text file
#include <cstdlib>   //za  rand()

using  namespace std;
int main()
{
    //int attepts = 6;
    string arrWords[5] = { "radio", "where", "pupil", "games", "fifth" };
    srand(time(0));
    int randomWordNumber = rand() % 5; //izbira random duma
    string randomWord = arrWords[randomWordNumber];  //tuk sum proverqval


    cout << "Random Word - " << randomWord << endl;
    char letter;
    cin >> letter;
    for (int i = 0; i<int((randomWord.length())); i++)
    {
        if (letter == char(randomWord[i]))
        {
            cout << "Letter is correct!" << endl << "Place number - " << i;
            break;
        }
    }

    /*for (int i = 0; i < attepts; i++)
    {
        cin >> world;
        if (int(world.length()) == 5)
        {
            cout << "OK!" << endl;
        }
        else
        {
            cout << "Please type only words with 5 letters! (+1 attempt)" << endl;
            ++attepts;
        }
    }*/
}