#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <fstream>
#include <string>

using namespace std;
char FileName[] = "Chapter 1 It is a truth universally acknowledged,";

int main()
{
    char ch;
    int i;
    string line;
    ifstream inMyStream(FileName);
    int c;
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    for (i = 0; FileName[i] != '\0'; ++i)
    {
        ch = FileName[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + 2;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            FileName[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 2;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            FileName[i] = ch;
        }
    }
    cout << "Encrypted message: " << FileName;
    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-10;

    printf("Time measured: %.20f seconds.\n", elapsed);
    return 0;
}