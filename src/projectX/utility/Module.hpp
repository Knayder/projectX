#pragma once

#include <tuple>

#include "projectX/utility/TypeTraits.hpp"

namespace px {

	template<typename... Deps>
	class Module {
	public:
		using DepModules_t = std::tuple<Deps*...>;

		template<typename... DepsTypes>
		struct DepsParser {
			template<typename... ModTypes>
			void grantAccess(Module<Deps...>& mod, std::tuple<ModTypes...>& modulesHolder) {
				static_assert((tt::tuple_contains_type<DepsTypes, std::tuple<ModTypes...>>() && ...), "Trying to access unexisting module");
				((std::get<DepsTypes*>(mod.depModules) = &(std::get<DepsTypes>(modulesHolder))), ...);
			}

		};
		DepsParser<Deps...> depsParser;

		Module() {

		}

		template<typename ModType>
		ModType& getModule() {
			static_assert(tt::tuple_contains_type<ModType*, DepModules_t>(), "This module is inaccessible");
			return *(std::get<ModType*>(depModules));
		}

		template<typename ModType>
		const ModType& getModule() const {
			static_assert(tt::tuple_contains_type<ModType*, DepModules_t>(), "This module is inaccessible");
			return *(std::get<ModType*>(depModules));
		}


	private:
		DepModules_t depModules;
	};

}