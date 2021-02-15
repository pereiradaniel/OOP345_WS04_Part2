#include "ConfirmationSender.h"

namespace sdds {

	ConfirmationSender::~ConfirmationSender() {
		delete[] _res;
		_res = nullptr;
	}

	ConfirmationSender &ConfirmationSender::operator=(const ConfirmationSender& src) {
		if (this != &src) {
			_cnt = src._cnt;
			delete [] _res;
			_res = new const Reservation * [_cnt];
			for (size_t i = 0; i < _cnt; i++) {
				_res[i] = src._res[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		*this = src;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept {
		if (this != &src) {
			_cnt = src._cnt;
			delete [] _res;
			_res = src._res;
			src._res = nullptr;
			src._cnt = 0;
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept {
		*this = move(src);
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool exist = false;
		for (size_t i = 0; i < _cnt; i++) {
			if (_res[i] == &res) {
				exist = true;
			}
		}
		if (!exist) {
			const Reservation** temp = nullptr;
			temp = new const Reservation * [_cnt + 1];
			for (size_t j = 0; j < _cnt; ++j) {
				temp[j] = _res[j];
			}
			temp[_cnt] = &res;
			_cnt++;
			delete[] _res;
			_res = temp;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool exist = false;
		size_t index{ 0 };
		for (size_t i = 0; i < _cnt; ++i) {
			if (_res[i] == &res) {
				exist = true;
				index = i;
				i = _cnt;
			}
		}
		if (exist) {
			const Reservation** temp{ nullptr };
			temp = new const Reservation * [_cnt - 1];
			for (size_t j = 0; j < _cnt; ++j) {
				if (j < index) {
					temp[j] = _res[j];
				}
				else {
					temp[j] = _res[j + 1];
				}
			}
			--_cnt;
			delete[] _res;
			_res = temp;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& copy) {
		os << "--------------------------\n"
			<< "Confirmations to Send\n"
			<< "--------------------------\n";
		if (copy._cnt == 0) {
			os << "There are no confirmations to send!\n";
		}
		for (size_t i = 0; i < copy._cnt; i++) {
			if (copy._res[i] != nullptr) {
				os << *copy._res[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
}