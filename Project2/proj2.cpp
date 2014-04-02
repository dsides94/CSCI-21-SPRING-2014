/*
 * Programming Project 2
 * 
 * 
 *
 * David Sides
 * Date created: 2/24/2014
 * Last date modified: 4/2/2014
 */

#include "box.h"
#include "prize.h"

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

/*
 * Get an unsigned integer using cin.
 * @param message a string that is put in console to clarify the purpose
 *        of the input.
 * @return an unsigned integer that the user inputs.
 */
unsigned int inputGetUnsInt(string message);

/*
 * Get an unsigned integer using cin with a min and max.
 * @param message a string that is put in console to clarify the purpose
 *        of the input.
 * @param min an unsigned int that is the minimum value for the input.
 * @param max an unsigned int that is the maximum value for the input.
 * @return an unsigned integer that the user inputs.
 */
unsigned int inputGetUnsInt(string message, unsigned int min, unsigned int max);

/*
 * Get a string using cin.
 * @param message a string that is put in console to clarify the purpose
 *        of the input.
 * @return a string that the user inputs.
 */
string inputGetString(string message);

/*
 * Pauses the console and asks the user to press enter to continue.
 */
void pauseConsole();

int main ()
{
    Prize prize;
    Box box;
    int choice = 0;
    
    while(true){
        cout << "\n\n[Main Menu]\n\n";
        cout << "[1] Prize Interactive Test\n";
        cout << "[2] Box Interactive Test\n";
        cout << "[3] Unit Test\n";
        cout << "[0] Quit\n\n";
        
        choice = inputGetUnsInt("Choice", 0, 3);
        
        if(choice == 1){
            while(true){
                cout << "\n\n[Prize Menu]\n\n";
                cout << "Prize Name: " << prize.getPrizeName() << "\n";
                cout << "Prize Value: " << prize.getPrizeValue() << "\n\n";
                cout << "[1] Set Prize Name\n";
                cout << "[2] Set Prize Value\n";
                cout << "[3] Compare Two Prizes\n";
                cout << "[0] Main Menu\n\n";
                
                choice = inputGetUnsInt("Choice", 0, 3);
                
                cout << "\n";
                
                if(choice == 1){
                    cout << "[Setting Prize Name]\n";
                    prize.setPrizeName(inputGetString("New Name"));
                }
                else if(choice == 2){
                    cout << "[Setting Prize Value]\n";
                    prize.setPrizeValue(inputGetUnsInt("New Value"));
                }
                else if(choice ==3){
                    cout << "[Test Prize Comparison]\n";
                    Prize p[2];
                    for(unsigned int i = 0; i < 2; i++){
                        cout << "[Prize "<< i+1 << "]\n";
                        p[i].setPrizeName(inputGetString("Name"));
                        p[i].setPrizeValue(inputGetUnsInt("Value"));
                        cout << endl;
                    }
                    if(p[0] == p[1]){
                        cout << "Yes, these prizes are equal.";
                    }
                    else{
                        cout << "No, these prizes are not equal.";
                    }
                    
                    pauseConsole();
                }
                else{
                    break;
                }
            }
        }
        else if(choice == 2){
            while(true){
                cout << "\n\n[Box Menu]\n\n";
                cout << "Box Number: " << box.getBoxNumber() << "\n";
                cout << "Box Color: " << box.getBoxColor() << "\n";
                cout << "Prize Count: " << box.getPrizeCount() << "\n";
                cout << "Prize Capacity: " << box.getPrizeCapacity() << "\n\n";
                cout << "[1] Set Box Number\n";
                cout << "[2] Set Box Color\n";
                cout << "[3] Add Prize\n";
                cout << "[4] Remove Prize\n";
                cout << "[5] View Prizes\n";
                cout << "[0] Main Menu\n\n";
                cout << "Choice: ";
                
                choice = inputGetUnsInt("Choice", 0, 5);
                
                cout << "\n";
                
                if(choice == 1){
                    cout << "[Setting Box Number]\n";
                    box.setBoxNumber(inputGetUnsInt("New Number"));
                }
                else if(choice == 2){
                    cout << "[Setting Box Color]\n";
                    box.setBoxColor(inputGetString("New Color"));
                }
                else if(choice == 3){
                    cout << "[Adding Prize]\n";
                    if(box.getPrizeCount() < box.getPrizeCapacity()){
                        string name = inputGetString("Name");
                        unsigned int value = inputGetUnsInt("Value");
                        box.addPrize(Prize(name, value));
                    }
                    else
                    {
                        cout << "Box is full, can't add any more prizes.";
                        pauseConsole();
                    }
                    cout << "\n";
                }
                else if(choice == 4){
                    cout << "[Removing Prize]\n";
                    if(box.getPrizeCount() > 0){
                        cout << "Prizes:\n";
                        for(unsigned int i = 0; i < box.getPrizeCount(); i++){
                            Prize p = box.getPrize(i);
                            cout << "[" << i+1 << "]: " << "[Name: " << p.getPrizeName() << "] [Value: " << p.getPrizeValue() << "]\n";
                        }
                        cout << "[0]: Cancel\n\n";
                        choice = inputGetUnsInt("Choice", 0, box.getPrizeCount());
                        if(choice > 0){
                            box.removePrize(choice-1);
                        }
                        cout << "\n";
                    }
                    else{
                        cout << "No prizes in this box\n";
                        pauseConsole();
                    }
                    
                }
                else if(choice == 5){
                    cout << "[Viewing Prizes]\n";
                    if(box.getPrizeCount() > 0){
                        for(unsigned int i = 0; i < box.getPrizeCount(); i++){
                            Prize p = box.getPrize(i);
                            cout << "[" << i << "]: " << "[Name: " << p.getPrizeName() << "] [Value: " << p.getPrizeValue() << "]\n";
                        }
                    }
                    else{
                        cout << "No prizes in this box\n";
                    }
                    pauseConsole();
                }
                else{
                    break;
                }
            }
        }
        else if(choice == 3){
            unittest();
            pauseConsole();
        }
        else{
            break;
        }
    }

    return 0;
}

void pauseConsole()
{
    cout << "\nPress enter to continue.";
    cin.sync();
    cin.ignore(256,'\n');
    cin.get();
}

unsigned int inputGetUnsInt(string message)
{
    cout << message <<": ";
    unsigned int input;
    while (!(cin >> input))
    {
        cout << "Invalid Input\n";
        cout << message <<": ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    return input;
}

unsigned int inputGetUnsInt(string message, unsigned int min, unsigned int max)
{
    cout << message << " (" << min << " - " << max << "): ";
    unsigned int input;
    while (!(cin >> input) || input < min || input > max)
    {
        cout << "Invalid Input\n";
        cout << message << " (" << min << " - " << max << "): ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    return input;
}

string inputGetString(string message)
{
    cout << message << ": ";
    string str;
    cin.ignore(256,'\n');
    getline(cin, str);
    return str;
}

/*
 * Unit testing functionb1. Do not alter.
 */

void unittest ()
{
    cout << "\nSTARTING UNIT TEST\n\n";
	
    Box b1;
    Box b2(42, "blue", 3);
	
    cout << "** TESTING DEFAULT BOX **\n\n";
	
    try {
        btassert<bool>(b1.getBoxNumber() == 0);
        cout << "Passed TEST 1: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 1 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b1.getBoxColor() == "NO COLOR");
        cout << "Passed TEST 2: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 2 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b1.getPrizeCapacity() == 5);
        cout << "Passed TEST 3: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 3 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b1.getPrizeCount() == 0);
        cout << "Passed TEST 4: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 4 Box getPrizeCount() #\n";
    }
	
    b1.setBoxNumber(99);
    try {
        btassert<bool>(b1.getBoxNumber() == 99);
        cout << "Passed TEST 5: Box setBoxNumber()/getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 5 Box setBoxNumber()/getBoxNumber() #\n";
    }
	
    b1.setBoxColor("red");
    try {
        btassert<bool>(b1.getBoxColor() == "red");
        cout << "Passed TEST 6: Box setBoxColor()/getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 6 Box setBoxColor()/getBoxColor() #\n";
    }
    
    cout << "\n** TESTING CUSTOM BOX **\n\n";
	
    try {
        btassert<bool>(b2.getBoxNumber() == 42);
        cout << "Passed TEST 7: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 7 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b2.getBoxColor() == "blue");
        cout << "Passed TEST 8: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 8 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 9: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 9 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCount() == 0);
        cout << "Passed TEST 10: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 10 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(0) == Prize());
        cout << "Passed TEST 11: Box getPrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 11 Box getPrize(0) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(0) == Prize());
        cout << "Passed TEST 12: Box removePrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 12 Box removePrize(0) #\n";
    }
    
    b2.addPrize(Prize("BRONZE PRIZE", 1));
    try {
        btassert<bool>(b2.getPrizeCount() == 1);
        cout << "Passed TEST 13: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 13 Box addPrize()/getPrizeCount() #\n";
    }
    
    b2.addPrize(Prize("SILVER PRIZE", 100));
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 14: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 14 Box addPrize()/getPrizeCount() #\n";
    }
        
    b2.addPrize(Prize("GOLD PRIZE", 1000));
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 15: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 15 Box addPrize()/getPrizeCount() #\n";
    }
    
    try {
        btassert<bool>(b2.addPrize(Prize("DIAMOND PRIZE", 999)) == false);
        cout << "Passed TEST 16: Box addPrize(ARRAY FULL)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 16 Box addPrize(ARRAY FULL) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(1) == Prize("SILVER PRIZE", 100));
        cout << "Passed TEST 17: Box getPrize(1)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 17 Box getPrize(1) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize("GOLD PRIZE", 1000));
        cout << "Passed TEST 18: Box removePrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 18 Box removePrize(2) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 19: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 19 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize());
        cout << "Passed TEST 20: Box removeCargo(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 20 Box removeCargo(2) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(2) == Prize());
        cout << "Passed TEST 21: Box getPrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 21 Box getPrize(2) #\n";
    }
	
    try {
        btassert<bool>(b2.addPrize(Prize("RUBY PRIZE", 9999)) == true);
        cout << "Passed TEST 22: Box addPrize(\"RUBY PRIZE\", 9999)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 22 Box addPrize(\"RUBY PRIZE\", 9999) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 23: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 23 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 24: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 24 Box getPrizeCapacity() #\n";
    }
	
    cout << "\n** TESTING PRIZE **\n\n";
	
    Prize p1;
	
    try {
        btassert<bool>(p1.getPrizeName() == "NO NAME");
        cout << "Passed TEST 25: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 25 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p1.getPrizeValue() == 0);
        cout << "Passed TEST 26: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 26 Prize getPrizeValue() #\n";
    }
	
    p1.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p1.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 27: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 27 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p1.setPrizeValue(17);
    try {
        btassert<bool>(p1.getPrizeValue() == 17);
        cout << "Passed TEST 28: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 28 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
	
    Prize p2("HAT PRIZE", 50);
	
    try {
        btassert<bool>(p2.getPrizeName() == "HAT PRIZE");
        cout << "Passed TEST 29: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 29 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p2.getPrizeValue() == 50);
        cout << "Passed TEST 30: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 30 Prize getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 31: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 31 !(Prize == Prize) #\n";
    }
    
    p2.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p2.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 32: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 32 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p2.setPrizeValue(17);
    try {
        btassert<bool>(p2.getPrizeValue() == 17);
        cout << "Passed TEST 33: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 33 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(p1 == p2);
        cout << "Passed TEST 34: (Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 34 (Prize == Prize) #\n";
    }
    
    p2.setPrizeValue(1);
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 35: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 35 !(Prize == Prize) #\n";
    }
	
    cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
        throw X();
}