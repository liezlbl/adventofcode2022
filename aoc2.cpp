#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// class Round{
//     int choice; // rock, paper, or scissors score (1, 2, 3)
//     int outcome; // win, lose, draw (6, 0, 3)
//     int roundSum = 0;
// }

int main()
{
    ifstream myfile;
    // Round *arr = new Round(10000000);
    string line;
    int choice; // rock, paper, or scissors score (1, 2, 3)
    int outcome; // win, lose, draw (6, 0, 3)
    int totalSum = 0;
    int i = 0;
    myfile.open("aoc2.txt");
    if ( myfile.is_open() )
    {   
        while (myfile)
        {
            getline(myfile, line);
            // outer ifs - opponent play
            // inner ifs - your play
            if (!myfile.good())
            {
                break;
            }

            if (line[0] == 'A') // rock
            {
                if (line[2] == 'X') // p1- rock, draw // p2- scissors, lose
                {
                    // p1
                    // choice = 1;
                    // outcome = 3;
                    // p2
                    choice = 3;
                    outcome = 0;
                }
                else if (line[2] == 'Y') // p1- paper, win // p2- rock, draw
                {
                    // p1
                    // choice = 2;
                    // outcome = 6;
                    // p2
                    choice = 1;
                    outcome = 3;
                }
                else if (line[2] == 'Z') // p1- scissors, loss // p2- paper, win
                {
                    // p1
                    // choice = 3;
                    // outcome = 0;
                    // p2
                    choice = 2;
                    outcome = 6;
                }
            }
            else if (line[0] == 'B') // p1- paper
            {
                if (line[2] == 'X') // p1- rock, loss // p2- rock, lose
                {
                    // p1
                    // choice = 1;
                    // outcome = 0;
                    // p2
                    choice = 1;
                    outcome = 0;
                }
                else if (line[2] == 'Y') // p1- paper, draw // p2- paper, draw
                {
                    // p1
                    // choice = 2;
                    // outcome = 3;
                    // p2
                    choice = 2;
                    outcome = 3;
                }
                else if (line[2] == 'Z') // p1- scissors, win // p2- scissors, win
                {
                    // p1
                    // choice = 3;
                    // outcome = 6;
                    // p2
                    choice = 3;
                    outcome = 6;
                }
            }
            else if (line[0] == 'C') // scissors
            {
                if (line[2] == 'X') // p1- rock, win // p2- paper, lose
                {
                    // p1
                    // choice = 1;
                    // outcome = 6;
                    // p2
                    choice = 2;
                    outcome = 0;
                }
                else if (line[2] == 'Y') // p1- paper, loss // p2- scissors, draw
                {
                    // p1
                    // choice = 2;
                    // outcome = 0;
                    // p2
                    choice = 3;
                    outcome = 3;
                }
                else if (line[2] == 'Z') // p1- scissors, draw // p2- rock, win
                {
                    // p1
                    // choice = 3;
                    // outcome = 3;
                    // p2
                    choice = 1;
                    outcome = 6;
                }
            }
            totalSum += choice;
            totalSum += outcome;
        }
        cout << totalSum << endl;
    }
    myfile.close();
    return 0;
}
