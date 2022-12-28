#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool inRange(unsigned int low, unsigned int high, unsigned int x)
{
    return ((x-low) <= (high-low));
}
int main()
{
    ifstream myfile;
    myfile.open("aoc4.txt");
    string elf1_begin;
    int n1 = 0;
    string elf1_end;
    int n2 = 0;
    string elf2_begin;
    int n3 = 0;
    string elf2_end;
    int n4 = 0;
    bool flag = false;
    int counter = 0;
    if (myfile.is_open())
    {
        while (myfile)
        {
            if (!myfile.good())
            {
                break;
            }
            getline(myfile, elf1_begin, '-');
            if (elf1_begin.empty())
            {
                break;
            }
            n1 = stoi(elf1_begin);
            getline(myfile, elf1_end, ',');
            n2 = stoi(elf1_end);
            getline(myfile, elf2_begin, '-');
            n3 = stoi(elf2_begin);
            getline(myfile, elf2_end, '\n');
            n4 = stoi(elf2_end);

            // part 1
            // if (n3 >= n1 && n4 <= n2)
            // {
            //     counter++;
            // }
            // else if(n1 >= n3 && n2 <= n4)
            // {
            //     counter++;
            // }
            
            // part 2
            for (int i = n1; i <= n2; i++)
            {
                if (inRange(n3, n4, i))
                {
                    counter++;
                    flag = true;
                    break;
                }
                else
                {
                    for (int j = n3; j <= n4; j++)
                    {
                        if (inRange(n1, n2, j))
                        {
                            counter++;
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag == true)
                {
                    break;
                }
            }
        }
        cout << counter << endl;
    }
    myfile.close();
    return 0;
}