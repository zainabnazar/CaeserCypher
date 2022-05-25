#include <iostream>
#include <fstream>
#include <sys/time.h>

using namespace std;
int main()
{
    char filename[30], ch, story[683296];
    int tot = 0, i = 0;
    ifstream fp;
    cout << "Enter the Name of File: ";
    cin >> filename;
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
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
    //cout << "Encrypted message: " << story;
    ofstream myfile;
    myfile.open("output.txt");
    myfile << story;
    myfile.close();
    cout << endl
         << "Total Characters = " << tot;
    cout << endl;
    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-10;
    printf("Time measured: %.6f mseconds.\n", elapsed * 1000);
    return 0;
}