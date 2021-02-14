#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** _res{ nullptr }; // a dynamically allocated array of **pointers** to objects of type `Reservation`: `const 
		size_t _cnt{ 0 };
	public:
		ConfirmationSender() = default;
		~ConfirmationSender();

		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender operator=(ConfirmationSender&& src) noexcept;
		ConfirmationSender(ConfirmationSender&& src) noexcept;

		ConfirmationSender& operator +=(const Reservation& res); // adds the reservation `res` to the array by adding its address.
		ConfirmationSender& operator -=(const Reservation& res); // removes the reservation `res` from the array by removing its address

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& copy); // overload the insertion operator to insert the content of a `ConfirmationSender` object into an **ostream** object
	};
}

#endif