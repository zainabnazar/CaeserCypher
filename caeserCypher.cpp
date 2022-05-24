#include <iostream>
#include <stdio.h>
#include <sys/time.h>

using namespace std;

int main()
{
    char message[100], ch;
    int i, key;
    cout << "Enter a message to encrypt: ";
    cin.getline(message, 100);
    cout << "Enter key: ";
    cin >> key;
    // Start measuring time
    struct timeval begin, end;
    gettimeofday(&begin, 0);
    for (i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    cout << "Encrypted message: " << message;
    // Stop measuring time and calculate the elapsed time
    gettimeofday(&end, 0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds * 1e-10;

    printf("Time measured: %.20f seconds.\n", elapsed);
    return 0;
}