#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ifstream myfile;
    myfile.open("aoc3.txt");
    string line;
    int len = 0;
    char priority;
    int priority_value = 0;
    vector<string> sacks;
    int index = 0;
    bool flag;
    int counter = 1;
    int sum = 0;
    map<char, int> lowerVals;
    map<char, int> upperVals;
    for (int i = 0; i < 26; i++)
    {
        lowerVals['a' + i] = 1 + i;
    }
    for (int j = 0; j < 26; j++) 
    {
        upperVals['A' + j] = 27 + j;
    }
    if ( myfile.is_open() )
    {   
        while (myfile) 
        {
            getline(myfile, line);
            if (!myfile.good())
            {
                break;
            }
            // part 1
            // len = line.length();
            // for (int k = 0; k < len/2; k++)
            // {
            //     bool flag = false;
            //     for (int f = len/2; f < len; f++)
            //     {
            //         if (line[k] == line[f])
            //         {
            //             priority = line[f];
            //             if (isupper(priority))
            //             {
            //                 priority_value = upperVals[priority];
            //             }
            //             else if (islower(priority))
            //             {
            //                 priority_value = lowerVals[priority];
            //             }
            //             cout << priority << ": " << priority_value << endl;
            //             flag = true;
            //             break;
            //         }
            //     }
            //     if (flag == true)
            //     {
            //         break;
            //     }
            // }
            // sum += priority_value;
            // part 2
            sacks.push_back(line);
            if (counter % 3 == 0)
            {
                flag = false;
                for (int k = 0; k < sacks[index].length(); k++)
                {
                    for (int j = 0; j < sacks[index-1].length(); j++)
                    {
                        if (sacks[index][k] == sacks[index-1][j])
                        {
                            for (int m = 0; m < sacks[index-2].length(); m++)
                            {
                                if (sacks[index-1][j] == sacks[index-2][m])
                                {
                                    priority = sacks[index-2][m];
                                    if (isupper(priority))
                                    {
                                        priority_value = upperVals[priority];
                                    }
                                    else if (islower(priority))
                                    {
                                        priority_value = lowerVals[priority];
                                    }
                                    flag = true;
                                    sum += priority_value;
                                    break;
                                }
                            }
                        }
                        if (flag == true)
                        {
                            break;
                        }
                    }
                    if (flag == true)
                    {
                        break;
                    }
                }
            }
            index++;
            counter++;
        }
        cout << sum << endl;
    }
    myfile.close();
    return 0;
}