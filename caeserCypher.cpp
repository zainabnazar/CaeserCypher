#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <stdio.h>
#include <time.h>

using namespace std;
int main()
{
    char filename[30], ch, story[683296];
    int tot = 0, i = 0;
    ifstream fp;
    cout << "Enter the Name of File: ";
    cin >> filename;
    // Reading the text from prideAndPrejudice.txt file
    fp.open(filename, ifstream::in);
    if (!fp)
    {
        cout << endl
             << "File doesn't exist or Access denied!";
        return 0;
    }
    while (fp >> noskipws >> ch)
    {
        story[tot] = ch;
        tot++;
    }

    fp.close();
    // Start encryption measuring time
    clock_t start = clock();
    for (i = 0; story[i] != '\0'; ++i)
    {
        ch = story[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + 2;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            story[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 2;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            story[i] = ch;
        }
    }
    // End encryption measuring time and calculate the elapsed time
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    printf("\nTime measured: %.3f mseconds.\n", elapsed * 1000);
    // Write the encrypted text to output.txt file
    ofstream myfile;
    myfile.open("output.txt");
    myfile << story;
    myfile.close();
    // Print the total number of charachters
    cout << endl
         << "Total Characters = " << tot;
    cout << endl;
    return 0;
}