#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L;
    cin.ignore();
    int H;
    cin >> H;
    cin.ignore();
    string T;
    getline(cin, T);


    vector<vector<string>> letters = vector<vector<string>>(27, vector<string>(H, "ERR"));

    string line;
    for (size_t i(0); i < H; ++i)
    {
        getline(cin, line);
        int len = line.length();
        for (size_t j(0); j < 27; ++j)
        {
            letters[j][i] = line.substr(j * L, L);
        }

    }

    char letter_A('A');
    char letter_Z('Z');
    char letter_a('a');
    char letter_z('z');

    for (size_t i(0); i < H; ++i)
    {
        string outRow("");

        for (size_t j(0); j < T.length(); ++j)
        {
            char letter(T.at(j));

            int pos(0);

            if (letter >= letter_A && letter <= letter_Z)
            {
                pos = letter - letter_A;
            } else if (letter >= letter_a && letter <= letter_z)
            {
                pos = letter - letter_a;
            } else pos = 26;

            outRow = outRow + letters[pos][i];
        }
        cout << outRow << endl;
    }
}
