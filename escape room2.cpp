/*
Names: Tyler Zhang & Andrew Sinha
Program Name: Escape the Room - Theme: Greek Mythology 
Date: 1/3/25
Extra: Use of a string array
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

int tries;
// intitializes our functions before they are given a function body
void sleepWrite(string text, int speed);
string makeUpperCase(string s);
void runScene1();
void runScene2();
void runScene3();

int main(){ 
    time_t current = time(nullptr);
    srand(time(0));
    sleepWrite("Welcome to the Greek Mythology Escape Room!!!", 25);
    sleepWrite("You will be tasked with solving puzzles and using clues to escape this unknown world you have found yourself in.", 25);
    sleepWrite("Would you like to proceed? Y/N", 25);
    
    // calculates a random number between 2 and 3
    int secondRoom = (rand() % 2 + 2);
    cout << secondRoom << endl;
    char resp;
    cin >> resp;
    
    while (true) {
        if (toupper(resp) == 'Y'){
            runScene1();
            if (secondRoom == 2) {
                runScene2();
                runScene3();
                sleepWrite("Well, you've done it. You've escaped this mysterious place. Ahead of you is a portal. Stepping through, you find yourself in a new land - filled with mythical creatures and gods. There's no going home. Enjoy your new life. ESCAPE SUCCEEDED", 25);
            }
            else {
                runScene3();
                runScene2();
                sleepWrite("Well, you've done it. You've escaped this mysterious place. Ahead of you is a portal. Stepping through, you find yourself in a new land - filled with mythical creatures and gods. There's no going home. Enjoy your new life. ESCAPE SUCCEEDED", 25);
            }
            
            break;
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
    // calculates the difference between the current time and the starting time of the escape room
    cout << "It took you: " << difftime(time(nullptr), current) << " seconds" << " to finish this escape room." << endl; 
    return 0;
}

void sleepWrite(string text, int speed) {
    for (int i = 0; i < text.length(); i++) {
        cout << text[i];
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    cout << endl;
}
string makeUpperCase(string s) {
    for (int i = 0; i < s.length(); i++) {
        // makes each character in the string uppercase
        s[i] = toupper(s[i]);
    }
    return s;
}
void runScene1() {
    char resp2;
    bool d1 = false;
    bool deciphertool = false;
    string dguess = "";
    sleepWrite("You find yourself in a strange room you've never seen before. How did you get here? That's the primary question on your mind. The room is large, with floor-to-ceiling marble pillars and a thatch roof reinforced with clay.\n Ahead of you on one of the pillars is a loose slab of marble that seemse to be able to be pulled out.\n To your right is a Bookcase with a loose book that you may be able to read.\n Behind you is a wooden table with a note that you can try to read for possible clues.\n Finally, on your left is a door that is locked by a wordlock. You can open it with a correct guess.", 12);
    while(!d1){
        sleepWrite("Would you like to investigate the\n A) Pillar\n B) Bookcase\n C) Note\n D) Door", 25);
        cin >> resp2;
        // uses a switch case to check each possibility of input (lowercase is fine because it is maken uppercase)
        switch (toupper(resp2)) {
            case 'A': {
                sleepWrite("You investigate the pillar, noticing a loose piece of marble. Would you like to pull it out? Y/N", 25);
                cin >> resp2;

                if(toupper(resp2) == 'Y'){
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
                    // prints greek script because they don't have the deciphering tool
                    cout << "ο Ποσειδώνας ήταν εδώ" << endl;
                }
                break;
            }
            case 'D': {
                sleepWrite("You decided to head towards the locked door. Keeping it shut is a wordlock. Would you like to try to open it? Y/N", 25);
                cin >> resp2; 
                if(toupper(resp2) == 'Y'){
                    sleepWrite("Enter the word you would like to guess: ", 25);
                    cin >> dguess;
                    dguess = makeUpperCase(dguess);              
                    // checks if the user's input uppercase is the word WATER
                    if (dguess == "WATER") {
                        sleepWrite("Congrats! You have unlocked the first door! You can now move to the next room. But beware. It is even more dangerous.", 25);
                        d1 = true;
                    }

                    else{
                        sleepWrite("That is incorrect.", 25);
                        tries+=1;
                    }

                    if(tries == 7){
                        sleepWrite("Time is a valuable asset. One which you, it seems, have run out of. Water slowly fills the room. First to your ankles, then to your knees. Higher and higher it goes, until you're completely underwater. You run out of breath and then, nothing. ESCAPE FAILED.",25);
                        exit(0);
                    }
                }
                break;   
            }
                
            default: {
                sleepWrite("Please enter a valid input.", 25);
                cin >> resp2;
            }
        }
    }
}

void runScene2(){
    char resp3;
    int guess;
    bool d2 = false;
    bool hasArrow = false;
    bool hasBow = false;
    bool hasMag = false;
    bool foundClue = false;
    sleepWrite("You have entered the next room. The ceiling seems to have come a bit lower than the last room.\n Ahead of you seems to be another door, locked by a passcode, behind a statue of Zeus. At the base of the statue seems to be a broken machine. An ancient bow sits in the corner of the room. There is a lightning bolt built into the floor with small words on it. A magnifying glass is dangling from the ceiling by a string. Finally, there is a hole in the wall.", 25);
    while (!d2) {
        sleepWrite("Would you like to investigate the\n A) Broken Machine\n B) Ancient Bow\n C) Lightning Bolt\n D) Magnifying Glass\n E) Hole in Wall\n F) Door", 25);
        cin >> resp3;
        switch (toupper(resp3)) {
            case 'A': {
                if (foundClue) {
                    sleepWrite("You find that the broken machine has keys on it, but they only go from 1 to 10. Would you like to press on a button? Y/N", 25);
                    cin >> resp3;
                    if(toupper(resp3) == 'Y'){
                        int buttonNum;
                        sleepWrite("Which button would you like to press?", 25);
                        cin >> buttonNum;
                        if (buttonNum >= 1 && buttonNum <= 10) {
                            int calc = pow(buttonNum, 2) - 3; 
                            // converts the calculated number to a string 
                            sleepWrite(to_string(calc), 25);
                        }
                        else {
                            sleepWrite("The floor shakes. Invalid number, please try again.", 25);
                        }
                    }

                    else {
                        sleepWrite("You choose to back out.", 25);
                    }
                }
                else {
                    sleepWrite("Looking at the broken machine, you don't know what it does, so you choose to step away.", 25);
                }
                break;
                
            }
            case 'B': {
                if (hasArrow) {
                    sleepWrite("You pick up the ancient bow from the ground, and you nock an arrow. ", 25);
                }
                else {
                    sleepWrite("You pick up the ancient bow from the ground, but you see that it doesn't have any arrows to make it useful.", 25);
                }
                hasBow = true;
                break;
            }
            case 'C': {
                if (hasMag) {
                    sleepWrite("You look closely at the words on the lightning bolt, and you pull out your magnifying glass to see it more clearly. Taking a closer look, you see that it says, 'Hint: The broken machine outputs values based on a formula, which is what is needed to figure out the key passcode to the door.'", 25);
                    foundClue = true;
                }
                else {
                    sleepWrite("You look closely at the words on the lightning bolt, but it doesn't seem legible.", 25);
                }
                break;
            }
            case 'D': {
                if (hasBow && hasArrow) {
                    sleepWrite("Right above you is the magnifying glass dangling from the ceiling from a string. You aim the bow up and tug on the bowstring before releasing, letting the arrow fly through the air, before the arrowhead pierces the string and the magnifying glass falls to the ground. You now have the magnifying glass.",25);
                    hasMag = true;   
                }
                else {
                    sleepWrite("The magnifying glass dangles from the ceiling above youu, but you can't seem to reach it. If only there was a way to get it down.", 25);
                }
                break;
            }
            case 'E': {
                sleepWrite("You approach the hole in the wall, and it looks very dark. Reach in? Y/N", 25);
                cin >> resp3;
                if(toupper(resp3) == 'Y'){
                    sleepWrite("You reach in the hole, and it is very dusty and dirty.", 25);
                    sleepWrite("Wait.", 25);
                    sleepWrite("...", 100);
                    sleepWrite("You feel a something dusty and sharp inside and grab it out. It falls out, and it appears to be an arrow.", 25);
                    hasArrow = true;
                }

                else{
                    sleepWrite("You choose to leave the hole alone.", 25);
                }
                break;
            }
            case 'F': {
                sleepWrite("You decided to head towards the locked door. Keeping it shut is a keypad. You hear Zeus say, 'OUTPUT TO 12'. Would you like to try to open it? Y/N", 25);
                cin >> resp3; 
                if(toupper(resp3) == 'Y'){
                    sleepWrite("ENTER THE NUMBER.", 25);
                    cin >> guess;         
                    if (guess == 141) {
                        sleepWrite("Congrats! You have unlocked the next door! You can now move to the next room.", 25);
                        d2 = true;
                    }
                    else{
                        sleepWrite("That is incorrect.", 25);
                        tries+=1;
                    }
                    if (tries == 7){
                        sleepWrite("The gods are not to be angered. Yet you somehow accomplished that by angering Zeus of all the gods. From above a lightning bolt comes, striking you down where you stand, leaving only a pile of ashes. ESCAPE FAILED.", 25);
                        exit(0);
                    }
                }
                break;  
            }
            default: {
                sleepWrite("Please enter a valid input.", 25);
                cin >> resp3;
            }
        }
    }

}
void runScene3() {
    bool d3 = false;
    bool hasHandle = false;
    bool hasSword = false;
    bool hasScythe = false;
    bool hasScytheB = false;
    int hole;
    char resp4;
    string arr[3] = {"You search the first hole. You put your hand in it, pulling out the blade to the scythe.", "You have decided to search the second hole. You reach inside but only feel something crawl along your hand. You pull your arm out and find a spider crawling on you.", " You put your hand in the third hole and feel a round object. You pull it out to find the handle to the sword."};
    sleepWrite("You have entered the next room. It seems to be a monument towards past greek heroes - Perseus, Odysseus, Heracles, Achilles, Jason, Daedalus, and Theseus, each with their own statue.\n These statues stand in front of you, tall and mighty. On the base of the statue, there seems to be writing in greek.\n To your right is a piece of parchment paper that may give a clue to the room.\n Behind you is an ancient sword made of bronze with a missing handle.\n Further beyond the sword are three holes at floor level that seems to be arm width.\n To your left is a strangely shaped keyhole that is not in the shape of any normal key.\n To the left of the door seems to be a scythe without the blade.\n", 25);
    while(!d3){
        sleepWrite("Would you like to investigate the:\n A. Statues\n B. Parchment\n C. Sword \n D. Holes \n E. Door \n F. Scythe \n G. ???", 25); 
        cin >> resp4;
        switch(toupper(resp4)){
            case 'A': {
                sleepWrite("You have decided to investigate the statues. On the base of all of them is a small date of birth and death. One stands out to you though - Perseus - who had slain Medusa with a sword, beheading her. This may be useful information for later.", 25);
                break;
            }

            case 'B': {
                sleepWrite("You decided to investigate the piece of parchment on the table. It reads, 'Only One Shall Fit'. Ominous, yet useful. Keep this in mind - it may just get you out of this room in the end.", 25);
                break;
            }

            case 'C': {
                sleepWrite("You decided to investigate the handle-less sword.", 25);
                if(hasHandle){
                    sleepWrite("However, you have found the handle for the sword. With this, you attach the handle through some work and now hold a full sword.\n This sword is not just any sword - it is the sword Perseus used to slay Medusa. It may come in handy later.", 25);
                    hasSword = true;
                }
                else{
                    sleepWrite("Unfortunately, you cannot do anything with this sword as it has no handle. But, you notice the significance of the sword -  it is the sword Perseus used to kill Medusa. It must be useful.", 25);
                }
                break;
            }
            
            case 'D': {
                sleepWrite("You have investigated the holes. There are three of them - the one on the left, in the middle, and to the right. Would you like to search hole\n 1.\n 2.\n 3.", 25);
                cin >> hole;
                if(hole == 1){
                    sleepWrite(arr[hole - 1], 25);
                    hasScytheB = true;
                }
                else if(hole == 2){
                    sleepWrite(arr[hole - 1], 25);
                }
                else if (hole == 3) {
                    sleepWrite(arr[hole - 1], 25);
                    hasHandle = true;
                }
                else {
                    sleepWrite("Invalid hole.", 25);
                }
                break;
            }
            
            case 'E': {
                sleepWrite("You have decided to investigate the door.", 25);
                
                if(hasSword){
                    sleepWrite("Would you like to use the sword?", 25);
                    cin >> resp4;
                    
                    if(toupper(resp4) == 'Y'){
                        sleepWrite("You notice that the sword handle has the same design as the lock of the door. Placing the handle in, the door unlocks, letting you exit the room. Congrats! You have escaped this room!", 25);
                        d3 = true;
                        break;
                    }
                
                    else{
                        sleepWrite("You decided not to. Fair enough.", 25);
                    }
                }
                
                else if(hasScythe){
                    sleepWrite("You have the scythe. However, the blade and the handle do not fit in the door. At least you have a cool item, right?", 25);
                }
                
                else{
                    sleepWrite("You can do nothing currently.", 25);
                }
                break;
            }
            
            case 'F': {
                sleepWrite("You decided to investigate the scythe.", 25);
                
                if(hasScytheB){
                    sleepWrite("You have the blade for the scythe. With some work, you managed to reattach it. You now have the scythe Cronus used to kill his father, Uranus, the father of the sky itself.", 25);
                    hasScythe = true;
                }
                
                else{
                    sleepWrite("You cannot do anything with the scythe currently. It looks cool though.", 25);
                }
                break;
            }
            
            case 'G': {
                sleepWrite("Interesting choice, mortal. You decided to go to the door hidden in the corner of the room, opening it to see Medusa herself.", 25);
                
                if(hasSword){
                    sleepWrite("Thankfully, you have the sword that killed her once. You can do it again. And so you do, preventing a silly death.", 25);
                }
                
                else{
                    sleepWrite("You cannot defend yourself, so you are turned to stone because you looked at her. Unfortunate. ESCAPE FAILED.", 25);
                    exit(0);
                }
            }

        }
    }
}


