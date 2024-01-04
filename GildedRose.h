#pragma once

#include <string>
using std::string;
//This is project 1
// This is already done for you...
class Item {
public:
    string name;
    int sellIn;
    int quality;
    Item(string, int, int);
    Item();
};
Item::Item(){

}

Item::Item(string new_name, int new_sellIn, int new_quality)
: name(new_name), sellIn(new_sellIn), quality(new_quality) {
}


// This class is incomplete...
class GildedRose {
private:
  size_t aItem;
  size_t arraySize;
  size_t numItem;
  Item MyItems[10];
    // Add something to hold at least 10 items

public:
    GildedRose();
    ~GildedRose();

    size_t size() const;
    Item& get(size_t);
    void add(const Item&);

    Item& operator[](size_t);
};
GildedRose::GildedRose(){ //default constructor initializes numItem to ten to initialize size of array of type item.
  numItem = 10;
  Item MyItems[numItem];
}
GildedRose::~GildedRose() { //destructor: no use of dynamic memory so able to leave it blank.

};
size_t GildedRose::size() const{ // returns the current size of the array of type Item
  for(size_t arraySize=0;arraySize<numItem;arraySize++){

}
  return arraySize+1;
};
Item& GildedRose::get(size_t){ //gives the item at the current index.
  if (aItem < 10){
  }
  return MyItems[aItem];
};
void GildedRose::add(const Item&){ //Adds an item to the array of type Item.
if (aItem < 10){
   MyItems[aItem];
}
};
Item& GildedRose::operator[](size_t){ //Also gives item at current index using operator overloading.
if (aItem > arraySize){
  std::cout << "The index is invalid";
  return MyItems[0];
}
  return MyItems[aItem];
};
