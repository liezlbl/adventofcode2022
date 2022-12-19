#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

int main()
{
    int calories;
    ifstream myfile;
    myfile.open("aoc1.txt");
    string line;
    int *arr = new int(10000000);
    int num = 0;
    int i = 0;
    if ( myfile.is_open() )
    {   
        while (myfile) 
        {
            getline(myfile, line);
            // for (line; getline(myfile, line); /**/)
            // {
                // if next elf, store num in arr
            if (line.empty())
            {
                arr[i] = num;
                cout << arr[i] << endl;
                i++;
                num = 0;
            }
            // add cals for elf input
            else
            {
                num += stoi(line);
            }
            // }
        }
        //sort array, return largest
        int x, j;
        // int n = sizeof(*arr);
        for (x = 0; x < i; x++)
            // Last i elements are already
            // in place
            for (j = 0; j < i - x - 1; j++)
                if (arr[j] < arr[j + 1])
                    swap(arr[j], arr[j + 1]);
        cout << arr[0] << endl;
        cout << arr[1] << endl;
        cout << arr[2] << endl;
    }
    myfile.close();
    // int n = sizeof(*arr) / sizeof(arr[0]);
    // // int *sortedArr = new int(100000);
    // sort(arr, arr+n, greater<int>());
    // cout << arr[0] << endl;
    return 0;
}