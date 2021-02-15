#include "Restaurant.h"
# 
namespace sdds {
	Restaurant::~Restaurant() {
		delete[] res_res;
		res_res = nullptr;
	}

	Restaurant::Restaurant(const sdds::Reservation* reservations[], size_t cnt) {
		res_res = new Reservation[cnt];
		res_num = cnt;
		for (size_t i = 0; i < cnt; i++) {
			res_res[i] = *reservations[i];
		}
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (this != &src) {
			res_num = src.res_num;
			delete[] res_res;
			res_res = new Reservation[res_num];
			for (size_t i = 0; i < res_num; i++) {
				res_res[i] = src.res_res[i];
			}
		}
		return *this;
	}

	Restaurant::Restaurant(const Restaurant& src) {
		*this = src;
	}

	Restaurant &Restaurant::operator=(Restaurant&& src) noexcept {
		if (this != &src) {
			res_num = src.res_num;

			delete[] res_res;
			res_res = src.res_res;
			
			src.res_res = nullptr;
			src.res_num = 0;
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& src) noexcept {
		*this = move(src);
	}

	size_t Restaurant::size() const {
		return res_num;
	}

	ostream& operator<<(ostream& os, Restaurant& copy) {
		os << "--------------------------\n"
			<< "Fancy Restaurant (CALL_CNT)\n"
			<< "--------------------------\n";

		if (copy.res_num == 0) {
			os << "This restaurant is empty!\n";
		}
		else {
			for (size_t i = 0; i < copy.res_num; i++) {
				os << copy.res_res[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
}