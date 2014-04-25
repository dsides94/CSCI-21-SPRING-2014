/*
 * Programming Project 3
 * 
 * This program implements a doubly-linked list.
 *
 * David Sides
 * Date created: 4/16/2014
 * Last date modified: 4/23/2014
 */

#include "DLList.h"

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc <= 1){
        cout << "Error: No command-line argument." << endl;
    }
    else{
        DLList<int> *intList = NULL;
	
    	ifstream fileIn(argv[1]);
    	
    	if(!fileIn.good()){
    	    cout << "Error: File could not be opened." << endl;
    	}
    	else{
    	    string line;
            while(getline(fileIn, line)){
                char operation = line[0];
                
                //cout << operation << " : ";
                
                if(operation == '#'){
                    //cout << "COMMENT" << endl;
                }
                else if(operation == 'C'){
                    cout << "LIST CREATED" << endl;
                    if(intList != NULL){
                        delete intList;
                    }
                    intList = new DLList<int>;
                }
                else if(intList == NULL){
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                }
                else{
                    if(operation == 'X'){
                        cout << "LIST CLEARED" << endl;
                        intList->clear();
                    }
                    else if(operation == 'D'){
                        cout << "LIST DELETED" << endl;
                        delete intList;
                        intList = NULL;
                    }
                    else if(operation == 'A'){
                        try{
                            cout << "VALUE " << intList->getFront() << " AT HEAD" << endl;
                        }
                        catch (DLListException e){
                            cout << e.message << endl;
                        }
                    }
                    else if(operation == 'Z'){
                        try{
                            cout << "VALUE " << intList->getBack() << " AT TAIL" << endl;
                        }
                        catch (DLListException e){
                            cout << e.message << endl;
                        }
                    }
                    else if(operation == 'T'){
                        if(intList->getSize() > 0){
                            intList->popFront();
                            cout << "REMOVED HEAD" << endl;
                        }
                        else{
                            cout << "LIST EMPTY" << endl;
                        }
                    }
                    else if(operation == 'K'){
                        if(intList->getSize() > 0){
                            intList->popBack();
                            cout << "REMOVED TAIL" << endl;
                        }
                        else{
                            cout << "LIST EMPTY" << endl;
                        }
                    }
                    else if(operation == 'N'){
                        cout << "LIST SIZE IS " << intList->getSize() << endl;
                    }
                    else if(operation == 'P'){
                        if(intList->getSize() > 0){
                            cout << *intList << endl;
                        }
                        else{
                            cout << "LIST EMPTY" << endl;
                        }
                    }
                    else{
                        string str = line.substr(2);
                        stringstream ss(str);
                        int value = 0;
                        ss >> value;
                        
                        if(operation == 'I'){
                            cout << "VALUE " << value << " INSERTED" << endl;
                            intList->insert(value);
                        }
                        else if(operation == 'F'){
                            cout << "VALUE " << value << " ADDED TO HEAD" << endl;
                            intList->pushFront(value);
                        }
                        else if(operation == 'B'){
                            cout << "VALUE " << value << " ADDED TO TAIL" << endl;
                            intList->pushBack(value);
                        }
                        else if(operation == 'E'){
                            if(intList->removeAll(value)){
                                cout << "VALUE " << value << " ELIMINATED" << endl;
                            }
                            else{
                                cout << "VALUE " << value << " NOT FOUND" << endl;
                            }
                        }
                        else if(operation == 'R'){
                            if(intList->removeFirst(value)){
                                cout << "VALUE " << value << " REMOVED" << endl;
                            }
                            else{
                                cout << "VALUE " << value << " NOT FOUND" << endl;
                            }
                        }
                        else if(operation == 'G'){
                            if(intList->get(value)){
                                cout << "VALUE " << value << " FOUND" << endl;
                            }
                            else{
                                cout << "VALUE " << value << " NOT FOUND" << endl;
                            }
                            
                        }
                    }
                }
            }
    	}
    	if(intList != NULL){
    	    delete intList;
    	    intList = NULL;
    	}
    	
    	fileIn.close();
    }
    
	return 0;
}