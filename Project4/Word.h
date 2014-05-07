#pragma once

#include <string>
#include <cstdlib>

class Word{
    public:
        Word()
        : count(1)
        {}
        
        Word(newWord)
        : word(newWord),
          count(1)
        {}
        
        ~Word(){}
        
        string getWord() const{
            return word;
        }
    
    private:
        string word;
        unsigned int count;
};