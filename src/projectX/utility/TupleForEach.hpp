#pragma once

#include <utility>

namespace px {
	template<template<typename...> typename T, typename... Ts, typename F, size_t... Is>
	void forEachImpl(T<Ts...>& obj, F&& call, std::index_sequence<Is...>) {
		((call(std::get<Is>(obj))), ...);
	}

	template<template<typename...> typename T, typename... Ts, typename F>
	void forEach(T<Ts...>& obj, F&& call) {
		forEachImpl(obj, call, std::index_sequence_for<Ts...>());
	}
}