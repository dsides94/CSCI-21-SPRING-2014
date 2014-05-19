#include "treasurechest.h"

#include <sstream>

void TreasureChest::addItem(const Item& newItem){
    chest.push_back(newItem);
}

void TreasureChest::insertItem (const Item& newItem, unsigned int position){
    if(position < chest.size()){
        chest.insert(chest.begin() + position, newItem);
    }
    else{
        chest.push_back(newItem);
    }
}

const Item* TreasureChest::getItem (unsigned int position){
    if(position < chest.size()){
        return &chest[position];
    }
    else{
        return NULL;
    }
}

Item TreasureChest::removeItem (unsigned int position) throw (string){
    if(position < chest.size()){
        Item removed = chest[position];
        chest.erase(chest.begin() + position);
        return removed;
    }
    else{
        throw string("ERROR: attempting remove at invalid position");
    }
}

void TreasureChest::clear (){
    chest.clear();
}

bool TreasureChest::empty () const{
    return (chest.size() == 0);
}

unsigned int TreasureChest::getSize () const{
    return chest.size();
}

void TreasureChest::sortByName (){
    sort(chest.begin(), chest.end(), compareItemsByName);
}

void TreasureChest::sortByValue (){
    sort(chest.begin(), chest.end(), compareItemsByValue);
}

void TreasureChest::sortByQuantity (){
    sort(chest.begin(), chest.end(), compareItemsByQuantity);
}

ostream& operator<< (ostream& outs, const TreasureChest& src){
    stringstream ss;
    for(unsigned int i = 0; i < src.chest.size(); i++){
        if(i != 0){
            ss << ',';
        }
        ss << src.chest[i].name;
    }
    outs << ss.str();
    //cout << '\n' << ss.str() << '\n';
    return outs;
}

bool compareItemsByName (const Item& lsrc, const Item& rsrc){
    return (lsrc.name < rsrc.name);
}

bool compareItemsByValue (const Item& lsrc, const Item& rsrc){
    return (lsrc.value < rsrc.value);
}

bool compareItemsByQuantity (const Item& lsrc, const Item& rsrc){
    return (lsrc.quantity < rsrc.quantity);
}