#include <iostream>
#include <string>

#include "Automobile.hpp"



/*******************************************************************************
** Member function definitions
*******************************************************************************/
Automobile::Automobile( const std::string & color,
                        const std::string & brand,
                        const std::string & model,
                        const std::string & plateNumber )
  : color_(color), brand_(brand), model_(model), plateNumber_(plateNumber)
{}






/*******************************************************************************
** Non-member function definitions
*******************************************************************************/
bool operator==( const Automobile& lhs, const Automobile& rhs ) { //compares if each member of lhs and rhs are equal and returns true or false.
  if (lhs.color_ == rhs.color_ && lhs.brand_ == rhs.brand_ && lhs.model_ == rhs.model_ && lhs.plateNumber_ == rhs.plateNumber_){
    return true;
  }
  else
  return false;
}



bool operator!=( const Automobile& lhs, const Automobile& rhs ) //returns the opposite to the check of whether or not lhs = rhs. 
{ return !( lhs == rhs ); }



std::ostream & operator<<( std::ostream& stream, const Automobile& vehicle ){// streams in the members of the vehichle and returns the stream
                                                                            // in order to acquire color, brand, model, and platenumber.
  stream << vehicle.color_ << vehicle.brand_ << vehicle.model_ << vehicle.plateNumber_;
  return stream;
}
