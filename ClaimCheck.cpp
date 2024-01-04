#include <iostream>

#include "Automobile.hpp"
#include "ClaimCheck.hpp"



/*******************************************************************************
** Class attributes
*******************************************************************************/
size_t ClaimCheck::nextAvailableClaimNumber = 100;


/*******************************************************************************
** Member function definitions
*******************************************************************************/
ClaimCheck::ClaimCheck( const Automobile & vehicle )
  : vehicle_(vehicle),claimNumber_(nextAvailableClaimNumber++)
    // use initializer list to set claimNumber equal to nextAvailableClaimNumber with post incrementation.
{


}



Automobile ClaimCheck::vehicle() const //return a vehichle.
{ return vehicle_; }



size_t ClaimCheck::claimNumber() const // return a claimNumber.
{ return claimNumber_;  }



/*******************************************************************************
** Non-member function definitions
*******************************************************************************/
bool operator==( const ClaimCheck & lhs, const ClaimCheck & rhs ) // checks if two claimcheck claimNumbers are equal.
{
  if (lhs.claimNumber_ == rhs.claimNumber_){
    return true;
  }
  else
    return false;
}



bool operator!=( const ClaimCheck & lhs, const ClaimCheck & rhs )// returns whether or not lhs = rhs.
{ return ! (lhs == rhs); }



std::ostream & operator<<( std::ostream & stream, const ClaimCheck & ticket )//streams in the tickets vehicle and claimNumber.
{

  stream << ticket.vehicle_ << ticket.claimNumber_;
  return stream;
}
