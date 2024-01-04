#include	<iostream>

#include	"GateControl.hpp"

using namespace std;


extern	string	gCurrentDate;

extern	string	gCurrentTime;

bool	GateControl::AccessAllowed(CardNumber number) //create transaction object. check if authorized check if time is between start and end time. return access allowed.
{
	Transaction trans;
	if (authorizationMap_.find(number) != authorizationMap_.end()){
		if(authorizationMap_.at(number).startTime_ <= gCurrentTime && authorizationMap_.at(number).endTime_ >= gCurrentTime ){
			trans.number_ = number;
			trans.name_ = authorizationMap_[number].name_;
			trans.date_ = gCurrentDate;
			trans.time_ = gCurrentTime;
			trans.accessAllowed_ = true;
			transactionVector_.push_back(trans);
		}
		else	{
			trans.number_ = number;
			trans.name_ = authorizationMap_[number].name_;
			trans.date_ = gCurrentDate;
			trans.time_ = gCurrentTime;
			trans.accessAllowed_ = false;
			transactionVector_.push_back(trans);
			}
		}
	else {
		trans.number_ = number;
		trans.name_ = "***";
		trans.date_ = gCurrentDate;
		trans.time_ = gCurrentTime;
		trans.accessAllowed_ = false;
		transactionVector_.push_back(trans);
	}
	return trans.accessAllowed_;
}

bool	GateControl::AddAuthorization(CardNumber number, const string& name, //adds authorization to the map.
		const string& startTime, const string& endTime)	{
	Authorization check_au1(number, name, startTime, endTime);
	AuthorizationIterator myit1;

		if (authorizationMap_.find(number) == authorizationMap_.end()){//not in map so add is possible
			authorizationMap_.insert(pair <CardNumber,Authorization>(number,check_au1));
			return true;
		}
		else
		{																																	// in map cannot add return false.

			return false;
		}
}

bool	GateControl::ChangeAuthorization(CardNumber number, const string& name, //allows user to input new authorization.
		const string& startTime, const string& endTime){
	bool potchange;
	Authorization check_au3(number,name,startTime,endTime);

	AuthorizationIterator myit2;
	for (myit2 = authorizationMap_.begin(); myit2 != authorizationMap_.end(); myit2++){
		if (authorizationMap_.find(number) == authorizationMap_.end()){// not in map cannot change return false.
			potchange = false;
		}
		if (authorizationMap_.find(number) != authorizationMap_.end()){ //in map chage is possible return true
			potchange = true;
			authorizationMap_[number] = Authorization(number, name, startTime, endTime);
		}
	}
	return potchange;
}

bool	GateControl::DeleteAuthorization(CardNumber number){ //delets an authorization stored in the map.
	bool potdelete;
	AuthorizationIterator myit3;
		for (myit3 = authorizationMap_.begin(); myit3 != authorizationMap_.end(); myit3++){
			if (authorizationMap_.find(number) == authorizationMap_.end()){
				potdelete = false;
		}
			else if (authorizationMap_.find(number) != authorizationMap_.end()){
				potdelete = true;
				authorizationMap_.erase(number);
		}
	}
		return potdelete;

}

void	GateControl::GetAllAuthorizations(AuthorizationVector& authorizationVector){ // iterate throught the map and push all values in the map onto the vector.

	AuthorizationIterator	myit6;
	authorizationVector.clear();
		for(myit6 = authorizationMap_.begin(); myit6 != authorizationMap_.end(); myit6++){
		authorizationVector.push_back(myit6->second);
		}
	}

void	GateControl::GetAllTransactions(TransactionVector& transactionVector) { // return all values in the transction vector. create an object and cout all.
	transactionVector = transactionVector_;
}

bool	GateControl::GetCardAuthorization(CardNumber number, Authorization& authorization){ // gives the authorization for the given card number.
	bool card_Au;
	AuthorizationIterator myit4;
			if (authorizationMap_.find(number) == authorizationMap_.end()){
				card_Au = false;
			}
			if (authorizationMap_.find(number) != authorizationMap_.end()){
				authorization = authorizationMap_[number];
				card_Au = true;
			}

	return card_Au;
}

bool	GateControl::GetCardTransactions(CardNumber number,
		TransactionVector& transactionVector){ //gives the transactionVector the value of the transaction.
	bool card_trans = false;
	transactionVector.clear();
	for (int i = 0; i < transactionVector_.size(); i++){
		if (transactionVector_[i].number_ == number){
			card_trans = true;
			transactionVector.push_back(transactionVector_[i]);
		}

	}
	return card_trans;
}
