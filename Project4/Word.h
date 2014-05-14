#pragma once

#include <string>
#include <cstdlib>

class Word{
    public:
        Word();
        
        Word(std::string newWord);
        
        virtual ~Word();
        
        std::string getWord() const;
        
        void setWord(std::string newWord);
        
        unsigned int getCount() const;
        
        void incrementCount();
        
        friend bool operator==(const Word &w1, const Word &w2);
        
        friend bool operator<(const Word &w1, const Word &w2);
        
        friend bool operator>(const Word &w1, const Word &w2);
        
        friend std::ostream& operator<<(std::ostream& out, const Word &word);
    
    private:
        std::string word;
        unsigned int count;
};