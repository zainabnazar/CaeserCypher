# CaeserCypher
It was said that Julius Caesar protected his private documents by encrypting them using a cipher. The cypher works by taking each letter of the input text and shifting it by a number of letters. If the shift takes the letter past the end of the alphabet then it moves back to the beginning of the alphabet. In the case of a shift by 2
, w, x , y and z would map to y, z, a, b.  Case ought to be preserved, and any non-(A-Z/a-z) characters are left unmodified.
The challenge this week is to encrypt the entirety of Jane Austin's "Pride and Prejudice" as fast as possible (without using any compile-time pre-computation). You can disregard any time taken to read/write the problem and its output to disk.
Rewards:

:five:  Points are awarded for encoding the book in under 500ms*
:two:  Further points are awarded for encoding the book in under 100ms*
:two:  Further points are awarded for encoding the book in under 50ms*
The remaining :one: point is awarded to the fastest submission.

* Performance will be tested on my MacBook Pro (2019)


# Build the project
Make sure to build the file by using C++ compiler, to do that in vscode:

1- install the below C++ complier
![Screenshot 2022-05-26 at 13 40 27](https://user-images.githubusercontent.com/82872249/170489499-ca05f224-2f19-4261-87ce-871df5a3023f.png)

2- Open caeserCyhper.cpp in vscode.

3- Click on Terminal >> Run build task >> Choose the compiler >> You should get a successful build message in the console


# Run the project
1- Run this in the command line 

./caeserCyhper

2- Choose the txt file you want to encrypt (In our case, it is: prideAndPrejudice.txt)

3- Press enter and you should see the time in millisecond and the number of characters for the whole text file.

4- You can see the encrypted text in output.txt file
