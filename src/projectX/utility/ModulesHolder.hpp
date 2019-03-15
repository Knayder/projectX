#pragma once

#include <tuple>
#include "TupleForEach.hpp"

namespace px {
	template<typename... ModTypes>
	class ModulesHolder {
	public:
		ModulesHolder() {
			forEach(modulesHolder, [this](auto& mod) {
				mod.depsParser.grantAccess(mod, modulesHolder);
			});
		}

		template<typename Type, typename... TypeArgs>
		auto init(TypeArgs... typeArgs) {
			//@TODO: check if Type exists in modules and if has init func
			return std::get<Type>(modulesHolder).init(typeArgs...);
		}

		template<typename Type>
		Type& get() {
			//@TODO: check if Type exists in modules
			return std::get<Type>(modulesHolder);
		}


	private:

		std::tuple<ModTypes...> modulesHolder;
	};

}