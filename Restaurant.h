#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include <iostream>
#include "Reservation.h"

namespace sdds {
	class Restaurant {
		Reservation* res_res{ nullptr }; // a dynamically allocated array of objects of type `Reservation`: `Reservation*`
		size_t res_num;
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt); // a constructor that receives as a parameter an array of pointers to objects of type `Reservation`
		
		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src) noexcept;
		Restaurant& operator=(Restaurant&& src) noexcept;
		
		size_t size() const; // a query that returns the number of reservations in the system.
		~Restaurant();

		friend ostream& operator<<(ostream& os, Restaurant& src); // overload the insertion operator to insert the content of a `Restaurant` object into an **ostream** object.
	};
}

#endif