/*
Names: Tyler Zhang & Andrew Sinha
Program Name: Escape the Room - Theme: Greek Mythology 
Date: 1/3/25
Extra: ??????????
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <cctype>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

void sleepWrite(string text, int speed);
void makeUpperCase(string s);

bool d1 = false;
bool deciphertool = false;
string dguess = "";
int main(){
    time_t current = time(nullptr);
    sleepWrite("Welcome to the Greek Mythology Escape Room!!!", 25);
    sleepWrite("You will be tasked with solving puzzles and using clues to escape this unknown world you have found yourself in.", 25);
    sleepWrite("Would you like to proceed? Y/N", 25);

    char resp;
    cin >> resp;
    
    while (true) {
        if (toupper(resp) == 'Y'){
            sleepWrite("You find yourself waking up in a strange room. Marble pillars stretch up to a high, slanted ceiling. One pillar seems to have a loose piece of marble. To your right, there is a bookcase with a loose book. Behind you is a table with a note, and to your left is a door with a code lock.", 25);
            while(!d1){
                sleepWrite("Would you like to investigate the\n A) Pillar\n B) Bookcase\n C) Note\n D) Door", 25);
                cin >> resp;
                switch (toupper(resp)) {
                    case 'A': {
                        sleepWrite("You investigate the pillar, noticing a loose piece of marble. Would you like to pull it out? Y/N", 25);
                        cin >> resp;

                        if(toupper(resp) == 'Y'){
                            sleepWrite("You pull the marble slab out of the pillar, finding the deciphering tool! I wonder what this can be used for?", 25);
                            deciphertool = true;
                        }

                        else{
                            sleepWrite("You choose to back out.", 25);
                        }
                        break;
                    }
                    case 'B': {
                        sleepWrite("The loose book reads:\n To leave this room, find the god and enter what they are associated with. But beware: too many wrong attempts may lead to your doom!", 25);
                        break;
                    }
                    case 'C': {
                        sleepWrite("The note reads...", 25);
                        if (deciphertool) {
                            cout << "Poseidon was here." << endl;
                        }
                        else {
                            cout << "ο Ποσειδώνας ήταν εδώ" << endl;
                        }
                        break;
                    }
                    case 'D': {
                        sleepWrite("You decided to head towards the locked door. Keeping it shut is a wordlock. Would you like to try to open it? Y/N", 25);
                        cin >> resp; 
                        
                        if(toupper(resp) == 'Y'){
                            sleepWrite("Enter the word you would like to guess: ", 25);
                            cin >> dguess;
                            cout << dguess << endl;
                            makeUpperCase(dguess);
                            cout << dguess << endl;
                                                        
                            if (dguess == "WATER") {
                                sleepWrite("Congrats! You have unlocked the first door! You can now move to the next room. But beware. It is even more dangerous.", 25);
                                d1 = true;
                            }

                            else{
                                sleepWrite("That is incorrect.", 25);

                            }
                        }
                        break;   
                    }
                    default: {
                        sleepWrite("Please enter a valid input.", 25);
                        cin >> resp;
                    }
                }
                break;
            }
        }
        
        else if (toupper(resp) == 'N') {
            sleepWrite("You're not fun. You decided to not take part in the escape room. Goodbye!", 25);
            return 0;
        }
        else{
            sleepWrite("Please enter a valid option.", 25);
            cin >> resp;
        }
    }

    cout << "It took you:" + (time(nullptr) - current) << " to finish this escape room." << endl; 
    return 0;
}

void sleepWrite(string text, int speed) {
    for (int i = 0; i < text.length(); i++) {
        cout << text[i];
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    cout << endl;
}
void makeUpperCase(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
}