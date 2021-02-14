#include "ConfirmationSender.h"

namespace sdds {

	ConfirmationSender::~ConfirmationSender() {
		delete[] _res;
		_res = nullptr;
	}



}