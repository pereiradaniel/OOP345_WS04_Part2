#include "Restaurant.h"

namespace sdds {
	Restaurant::~Restaurant() {
		delete[] _res;
		_res = nullptr;
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) {
	}

	Restaurant::Restaurant(const Restaurant& src) {
	}

	Restaurant &Restaurant::operator=(Restaurant&& src) noexcept {
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept {
	}

	size_t Restaurant::size() const {
	}

	ostream& operator<<(ostream& os, Restaurant& copy) {
	}
}