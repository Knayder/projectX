#pragma once

#include <tuple>

#include "projectX/utility/TupleForEach.hpp"
#include "projectX/utility/TypeTraits.hpp"

namespace px {
	template<typename... ModTypes>
	class ModulesHolder {
	public:

		using ModulesHolder_t = std::tuple<ModTypes...>;

		ModulesHolder() {
			forEach(modulesHolder, [this](auto& mod) {
				mod.depsParser.grantAccess(mod, modulesHolder);
			});
		}

		template<typename Type, typename... TypeArgs>
		auto init(TypeArgs... typeArgs) {
			return get<Type>().init(typeArgs...);
		}

		template<typename Type>
		Type& get() {
			static_assert(tt::tuple_contains_type<Type, ModulesHolder_t>(), "There is no such a type in Modules Holder");
			return std::get<Type>(modulesHolder);
		}

		template<typename Type>
		const Type& get() const {
			static_assert(tt::tuple_contains_type<Type, ModulesHolder_t>(), "There is no such a type in Modules Holder");
			return std::get<Type>(modulesHolder);
		}


	private:

		ModulesHolder_t modulesHolder;
	};

}