#include <queue>
#include <stdexcept>
#include <string>

#include "ClaimCheck.hpp"
#include "ParkingLot.hpp"


/*******************************************************************************
** ParkingLot Member function definitions
*******************************************************************************/
ClaimCheck ParkingLot::dropOff( const Automobile& vehicle ) { //populate the parkedcar objects members with some initializer data and push onto the queue.
 ClaimCheck ticket(vehicle);
  ParkedCar newCar = {ticket.vehicle(),ticket.claimNumber()};


  parkedCars_.push(newCar);
  return ticket;
}




Automobile ParkingLot::pickUp( const ClaimCheck& ticket ) {
  ParkedCar Car1 ={ticket.vehicle(),ticket.claimNumber()};
   for (int i = 0; i < parkedCars_.size(); i++){//create parked car object. get the front of the queue. check for match between ticket
                                                //and parked car claimnumber.if equal return the ticket vehicle if not pop car from queue then
                                                // push the car to the back of the queue
     if (ticket.claimNumber() != Car1.claimNumber_){
        Car1 = parkedCars_.front();
        parkedCars_.pop();
        parkedCars_.push(Car1);
        }
    if (ticket.claimNumber() == Car1.claimNumber_){
          parkedCars_.pop();
         return ticket.vehicle();
       }
    else
       throw std::invalid_argument("The car was not in the lot");

  }
  return ticket.vehicle();
}




size_t ParkingLot::quantity()
{ // return the size of the queue.

    return parkedCars_.size();

}
