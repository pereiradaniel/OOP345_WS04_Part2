#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

using namespace std;

namespace sdds {
	class Reservation {
		string res_id;		// an array of characters
		string res_name;	// name on the reservation
		string res_email;	// the email to for confirmation
		int res_people;		// number of people in the party
		int res_day;		// day of arrival (1-28)
		int res_hour;		// hour of arrival (1-24)
	public:
		Reservation() = default; // a default constructor
		Reservation(const string& res); // Constructor that receives the reservation as a string.
		friend ostream& operator<<(ostream& os, const Reservation& src); // overload the insertion operator to insert the contents of a reservation object into an `ostream` object
	};
}

#endif