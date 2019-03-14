#pragma once

#include <tuple>

namespace px {
	template<typename... ModTypes>
	class ModulesHolder {
	public:
		ModulesHolder() {

		}

		template<typename Type, typename... TypeArgs>
		auto init(TypeArgs... typeArgs) {
			//@TODO: check if Type exists in modules and if has init func
			return std::get<Type>(modules).init(typeArgs...);
		}

		template<typename Type>
		Type& get() {
			//@TODO: check if Type exists in modules
			return std::get<Type>(modules);
		}


	private:
		std::tuple<ModTypes...> modules;
	};

}