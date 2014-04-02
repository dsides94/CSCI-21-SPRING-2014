#pragma once

#include <iostream>
#include "prize.h"

class Box{
    public:
    
        /*
         * Default constructor.
         * Initializes boxNumber to 0, boxColor to 'NO COLOR', prizeCapacity
         * to 5, prizeCount to 0, and prizes to an array the size of
         * prizeCapacity.
         */
        Box();
        
        /*
         * Initializes boxNumber to newBoxNumber, boxColor to newBoxColor, 
         * prizeCapacity to newPrizeCapacity, prizeCount to 0, and prizes to an
         * array the size of prizeCapacity.
         * @param newBoxNumber an unsigned int that boxNumber is set to.
         * @param newBoxNumber a string that boxColor is set to.
         * @param newPrizeCapacity an unsigned int that prizeCapacity is set to,
         *        and is the size of the prize array.
         */
        Box(unsigned int newBoxNumber, std::string newBoxColor, unsigned int newPrizeCapacity);
        
        /*
         * Default deconstructor that is empty.
         */
        ~Box();
        
        /*
         * Get the box number.
         * @return an unsigned int that is the number of the box.
         */
        unsigned int getBoxNumber() const;
        void setBoxNumber(unsigned int newBoxNumber);
        
        /*
         * Get the box color.
         * @return a string that is the color of the box.
         */
        std::string getBoxColor() const;
        void setBoxColor(std::string newBoxColor);
        
        /*
         * Get the prize capacity.
         * @return an unsigned int that is the size of the box prize array.
         */
        unsigned int getPrizeCapacity() const;
        
        /*
         * Get the prize count.
         * @return an unsigned int that is count of prizes.
         */
        unsigned int getPrizeCount() const;
        
        /*
         * Add a prize to this box.
         * @param prize the prize that you want to add to this box.
         * @return a bool that is true if the prize was successfully added to
         *         this box, and false if it wasn't.
         */
        bool addPrize(Prize prize);
        
        /*
         * Get a prize from this box at a specified index.
         * @param index an unsigned int that is the index of the prize.
         * @return a prize at the specified index if the index is valid,
         *         if the index is invalid, returns the scratch prize.
         */
        Prize getPrize(unsigned int index);
        
        /*
         * Removes a prize from this box at the specified index.
         * @param index an unsigned int that is the index of the prize.
         * @return a prize at the specified index if the index is valid,
         *         if the index is invalid, returns the scratch prize.
         */
        Prize removePrize(unsigned int index);
        
    private:
        unsigned int boxNumber;
        std::string boxColor;
        unsigned int prizeCapacity;
        unsigned int prizeCount;
        Prize scratch;
        Prize *prizes;
    
};