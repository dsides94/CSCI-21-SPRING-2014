#pragma once

#include <string>

class Prize{
    public:
    
        /*
         * Default constructor.
         * Initializes prizeName to 'NO NAME' and prizeValue to 0.
         */
        Prize();
        
        /*
         * Initializes prizeName and prizeValue to the paramaters.
         * @param newPrizeName a string that prizeName is set to.
         * @param newPrizeValue an unsigned int that prizeValue is set to.
         */
        Prize(std::string newPrizeName, unsigned int newPrizeValue);
        
        /*
         * Default deconstructor that is empty.
         */
        ~Prize();
        
        /*
         * Get the prize name.
         * @return a string that is the prizeName of the prize
         */
        std::string getPrizeName() const;
        
        /*
         * Set the prize name.
         * @param newPrizeName a string that prizeName is set to.
         */
        void setPrizeName(std::string newPrizeName);
        
         /*
         * Get the prize value;
         * @return an unsigned int that is the prizeValue of the prize
         */
        unsigned int getPrizeValue() const;
        
        /*
         * Set the prize Value.
         * @param newPrizeValue an unsigned int that prizeValue is set to.
         */
        void setPrizeValue(unsigned int newPrizeValue);
        
        /*
         * This lets your compare two prizes by checking if prizeName
         * and prizeValue for both prizes are equal.
         * @param &p1 the first prize being comapred.
         * @param &p2 the second prize being comapred.
         * @return a bool that is true if the prizes are equal and false if not.
         */
        friend bool operator==(const Prize &p1, const Prize &p2);
        
    private:
        std::string     prizeName;
        unsigned int    prizeValue;
};