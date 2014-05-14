#include "Word.h"

#include <iostream>
#include <string>

Word::Word()
: count(1)
{}

Word::Word(std::string newWord)
: word(newWord),
  count(1)
{
    for(unsigned int i = 0; i < word.length(); i++){
        word[i] = tolower(word[i]);
    }
}

Word::~Word(){
    
}

std::string Word::getWord() const{
    return word;
}

unsigned int Word::getCount() const{
    return count;
}

void Word::setWord(std::string newWord){
    word = newWord;
    for(unsigned int i = 0; i < word.length(); i++){
        word[i] = tolower(word[i]);
    }
}

void Word::incrementCount(){
    count++;
}

bool operator==(const Word &w1, const Word &w2){
    return (w1.getWord() == w2.getWord());
}

bool operator<(const Word &w1, const Word &w2){
    return (w1.getWord() < w2.getWord());
}

bool operator>(const Word &w1, const Word &w2){
    return (w1.getWord() > w2.getWord());
}

std::ostream& operator<<(std::ostream& out, const Word &word){
    out << word.getWord() << ' ' << word.getCount();
    return out;
}