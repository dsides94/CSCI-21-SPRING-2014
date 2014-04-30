#pragma once

#include <cstdlib>
#include <iostream>

template <typename T>
class Box{
    public:
        Box(T newContents)
        : contents(newContents)
        {} 
        
        void setContents(T newContents){
            contents = newContents;
        }
        
        T getContents() const{
            return contents;
        }
        
        friend std::ostream& operator<<(std::ostream& out, const Box<T>& src){
            out << src.contents;
            return out;
        }
        
    private:
        T contents;
};