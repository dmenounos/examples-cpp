#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "utils.hpp"

namespace utils {

	class Object {

	public:

		virtual ~Object();

		virtual auto toString() const -> string;
	};

}

#endif // OBJECT_HPP
