#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
using namespace std;

class Game
{
    int length;
    static const int NUM = 26;
    string wordlist[NUM];

public:
    Game(): length(0), wordlist{"apiary", "beetle", "cereal", "danger", "ensign",
                                "florid", "garage", "health", "insult", "jackal",
                                "keeper", "loaner", "manage", "nonce", "onset",
                                "plaid", "quilt", "remote", "stolid", "train",
                                "useful", "valid", "whence", "xenon", "yearn",
                                "zippy"} {}

    void setLength(int l) { length = l; }
    int getLength() const { return length; }
    string setWordlist(string* newWordlist)
    {
        for (int i = 0; i < wordlist->length(); ++i)
        {
            wordlist[i] = newWordlist[i];
        }
    }
    const string* getWordlist() const { return wordlist; }
    static int getNum() { return NUM; }

};

void displayMisses(int);
void greeting();



int main()
{
    Game myGame;
    ofstream ofs("MyWords.txt");
    for (int i = 0; i < myGame.getNum(); ++i)
    {
        ofs << myGame.getWordlist()[i] << endl;
    }
    ofs.close();
    srand(time(0));
    char play;
    cout << "Will you play a word game? (y/n) ";
    cin >> play;
    play = tolower(play);

    while (play == 'y')
    {
        string target = myGame.getWordlist()[rand() % 26];
        myGame.setLength(target.length());
        string attempt(myGame.getLength(), '-');
        string badChars;
        int guesses = 7;

        greeting();
        cout << "Guess my secret word. It has " << myGame.getLength() << " letters, and you guess\n"
        << "one letter at a time. You get " << guesses << " wrong guesses.\n";

        cout << "Your word: " << attempt << endl;

        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badChars.find(letter) != string::npos || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);

            if (loc == string::npos)
            {
                cout << "Oh, bad guess! See what you've done:\n\n";
                --guesses;
                displayMisses(guesses);

                badChars += letter;
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;

                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badChars.length() > 0)
                    cout << "Bad choices: " << badChars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
        {
            cout<<"You saved the person from being hanged!\n";
            cout<<"Congratulations!\n";
        }
        else
            cout << "Sorry, the word is " << target << ".\n";
        cout << "Will you play another? (y/n) ";
        cin >> play;
        play = tolower(play);
    }
    cout << "Bye\n";

    return 0;
}

void greeting()
{
    cout << "----------------\n";
    cout << "*** HANGMAN ***\n";
    cout << "________________________________\n";
    cout << "Deadly challenge of saving \nthe person from being hanged!\n";
    cout << "--------------------------------\n";
}

void displayMisses(int g)
{
    switch (g)
    {
        case 6:
            cout << R"(
    +---+
    |   |
        |
        |
        |
        |
    ========

)";
            break;
        case 5:
            cout << R"(
    +---+
    |   |
    0   |
        |
        |
        |
    ========

)";
            break;
        case 4:
            cout << R"(
    +---+
    |   |
    0   |
    |   |
        |
        |
    ========

)";
            break;
        case 3:
            cout << R"(
    +---+
    |   |
    0   |
   /|   |
        |
        |
    ========

)";
            break;
        case 2:
            cout << R"(
    +---+
    |   |
    0   |
   /|\  |
        |
        |
    ========

)";
            break;
        case 1:
            cout << R"(
    +---+
    |   |
    0   |
   /|\  |
   /    |
        |
    ========

)";
            break;
        case 0:
            cout << R"(
    +---+
    |   |
    0   |
   /|\  |
   / \  |
        |
    ========

)";
            break;
    }
}