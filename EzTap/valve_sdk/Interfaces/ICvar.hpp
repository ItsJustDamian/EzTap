#pragma once
#include "../../VirtualFunction.hpp"

template <typename T>
class UtlVector {
public:
	constexpr T& operator[](int i) noexcept { return memory[i]; };
	constexpr const T& operator[](int i) const noexcept { return memory[i]; };

	T* memory;
	int allocationCount;
	int growSize;
	int size;
	T* elements;
};

class ConVar {
public:
	VF(float, getFloat, 12, (), (this));
	VF(int, getInt, 13, (), (this));
	VF(void, setValue, 14, (const char* value), (this, value));
	VF(void, setValue, 15, (float value), (this, value));
	VF(void, setValue, 16, (int value), (this, value));

	std::byte pad[24];
	std::add_pointer_t<void __cdecl()> changeCallback;
	ConVar* parent;
	const char* defaultValue;
	char* string;
	std::byte pad1[28];
	UtlVector<void(__cdecl*)()> onChangeCallbacks;
};

class ICvar {
public:
	VF(ConVar*, findVar, 15, (const char* name), (this, name));
};