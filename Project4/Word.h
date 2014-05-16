#pragma once

#include <string>
#include <cstdlib>

class Word{
    public:
    
        /* 
         * Default Constructor.
         * Sets count to 1.
         */
        Word();
        
        /* 
         * Overloaded Constructor.
         * Sets count to 1, and word to a lowercase version of newWord.
         * @param newWord the word for this Word object.
         */
        Word(std::string newWord);
        
        /*
         * Default Destructor.
         */
        virtual ~Word();
        
        /*
         * Gets the word for this Word object.
         */ 
        std::string getWord() const;
        
        /*
         * Sets the word for this Word object, and makes it all lowercase.
         * @param newWord the new word for this Word object.
         */
        void setWord(std::string newWord);
        
        /*
         * Gets the number of times this word has occured.
         */
        unsigned int getCount() const;
        
        /* 
         * Increments the occurence count for this word.
         */
        void incrementCount();
        
        /*
         * Overloaded comparison operator.
         * Compares the words for two different Word objects.
         * @param w1 the first Word for comparision.
         * @param w2 the second Word for comparision
         * @return a bool that is true if the words are equal.
         */
        friend bool operator==(const Word &w1, const Word &w2);
        
        /*
         * Overloaded less-than operator.
         * Checks if a word is less than another word alphabetically.
         * @param w1 the first Word for comparision.
         * @param w2 the second Word for comparision
         * @return a bool that is true if the word is less than another
                   word alphabetically.
         */
        friend bool operator<(const Word &w1, const Word &w2);
        
        /*
         * Overloaded greater-than operator.
         * Checks if a word is greater than another word alphabetically.
         * @param w1 the first Word for comparision.
         * @param w2 the second Word for comparision
         * @return a bool that is true if the word is greater than another
                   word alphabetically.
         */
        friend bool operator>(const Word &w1, const Word &w2);
        
        /*
         * Overloaded insertion operator.
         * Inserts the word for this Word object into the specified ostream.
         * @param out the stream that the word is inserted into.
         * @param word the word that is inserted into the stream
         * @return out an ostream that is the out stream.
         */
        friend std::ostream& operator<<(std::ostream& out, const Word &word);
    
    private:
        std::string word;
        unsigned int count;
};