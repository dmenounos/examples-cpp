#include "utils.hpp"

namespace utils {

	Object::~Object() {
	}

	auto Object::toString() const -> string {
		return to_string((uintptr_t) this);
	}

}
