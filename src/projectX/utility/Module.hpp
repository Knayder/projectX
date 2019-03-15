#pragma once

#include <tuple>

namespace px {

	template<typename... Deps>
	class Module {
	public:
		template<typename... DepsTypes>
		struct DepsParser {
			template<typename... ModTypes>
			void grantAccess(Module<Deps...>& mod, std::tuple<ModTypes...>& modulesHolder) {
				((std::get<DepsTypes*>(mod.depModules) = &(std::get<DepsTypes>(modulesHolder))), ...);
			}

		};
		DepsParser<Deps...> depsParser;

		Module() {

		}

		template<typename ModType>
		ModType& getModule() {
			return *(std::get<ModType*>(depModules));
		}

		template<typename ModType>
		const ModType& getModule() const {
			return *(std::get<ModType*>(depModules));
		}


	private:
		std::tuple<Deps*...> depModules;
	};

}