/*
 * Programming Project 4
 * 
 * This program implements a Binary Search Tree.
 *
 * David Sides
 * Date created: 5/7/2014
 * Last date modified: 5/14/2014
 */

#include "Word.h"
#include "BSTree.h" 

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc <= 1){
        cout << "Error: No command-line argument." << endl;
    }
    else{
        BSTree<Word> *tree = NULL;
	
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
                    cout << "TREE CREATED" << endl;
                    if(tree != NULL){
                        delete tree;
                    }
                    tree = new BSTree<Word>;
                }
                else if(tree == NULL){
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                }
                else{
                    if(operation == 'X'){
                        cout << "TREE CLEARED" << endl;
                        tree->clear();
                    }
                    else if(operation == 'D'){
                        cout << "TREE DELETED" << endl;
                        delete tree;
                        tree = NULL;
                    }
                    else if(operation == 'N'){
                        cout << "TREE SIZE IS " << tree->getSize() << endl;
                    }
                    else if(operation == 'O'){
                        if(tree->getSize() > 0){
                            tree->inOrder();
                        }
                        else{
                            cout << "TREE EMPTY" << endl;
                        }
                    }
                    else if(operation == 'E'){
                        if(tree->getSize() > 0){
                            tree->reverseOrder();
                        }
                        else{
                            cout << "TREE EMPTY" << endl;
                        }
                    }
                    else{
                        string str;
                        if(line[line.length()-1] == '\r'){
                            str = line.substr(2, line.length()-3);
                        }
                        else{
                            str = line.substr(2);
                        }
                        Word word(str);
                        //cout << "WORD: " << str << endl;

                        if(operation == 'I'){
                            if(tree->insert(word)){
                                cout << "WORD " << str << " INSERTED" << endl;
                            }
                            else{
                                Word *w = tree->get(word);
                                w->incrementCount();
                                cout << "WORD " << str << " INCREMENTED" << endl;
                            }
                        }
                        else if(tree->getSize() > 0){
                            if(operation == 'F'){
                                if(tree->find(word)){
                                    cout << "FOUND " << str << endl;
                                }
                                else{
                                    cout << str << " NOT FOUND" << endl;
                                }
                            }
                            else if(operation == 'R'){
                                if(tree->remove(word)){
                                    cout << "REMOVED " << str << endl;
                                }
                                else{
                                    cout << str << " NOT FOUND" << endl;
                                }
                            }
                            else if(operation == 'G'){
                                Word *w = tree->get(word);
                                if(w != NULL){
                                    cout << "GOT " << str << ' ' << w->getCount() << endl;
                                }
                                else{
                                    cout << str << " NOT FOUND" << endl;
                                }
                            }
                        }
                        else{
                            cout << "TREE EMPTY" << endl;
                        }
                    }
                }
            }
    	}
    	
    	if(tree != NULL){
    	    delete tree;
    	    tree = NULL;
    	}
    	
    	fileIn.close();
    }
    
	return 0;
}