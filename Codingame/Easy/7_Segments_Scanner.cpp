#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_DIGIT = 300;
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

 string String_slice(string sName1, int Start, int End)
 {
    string s = "";

    for(int i = Start; i < End; i ++)
    {
        s += sName1[i];
    }
    return s;
 }

int main()
{

    string line_1, line_2, line_3;
    getline(cin, line_1);
    getline(cin, line_2);
    getline(cin, line_3);

    int answer[MAX_DIGIT], linelength = line_1.size()/3;

    for(int i = 0; i < linelength; i++)
    {
        string l1 = String_slice(line_1, i * 3, i * 3 + 3);
        string l2 = String_slice(line_2, i * 3, i * 3 + 3);
        string l3 = String_slice(line_3, i * 3, i * 3 + 3);

        if(l1 != " _ ")
        {
            if(l2 == "  |")
            {
                answer[i] = 1;
            }
            else
            {
                answer[i] = 4;
            }
        }
        else if(l3 == "|_|")
        {
            if(l2== "| |")
            {
                answer[i] = 0;
            }
            else if(l2 =="|_|")
            {
                answer[i] = 8;
            }
            else
                answer[i] = 6;
        }
        else if(l3 == " _|")
        {
            if(l2 == " _|")
            {
                answer[i] = 3;
            }
            else if (l2 == "|_ ")
            {
                answer[i] = 5;
            }
            else
                answer[i] = 9;
        }
        else
            {
                if(l3 == "  |")
                    answer[i] = 7;
                else
                    answer[i] = 2;
            }
    }
  // String_slice(line_1, line_2, line_3);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    for(int i = 0; i < linelength; i++)
        cout << answer[i];
    cout<<'\n';
}
