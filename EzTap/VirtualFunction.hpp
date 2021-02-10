#pragma once
#include <cstddef>
#include <optional>

namespace VFNC
{
	template<typename T, std::size_t Idx, typename ...Args>
	constexpr T callFunc(void* classBase, Args... args) noexcept
	{
		return ((*reinterpret_cast<T(__thiscall***)(void*, Args...)>(classBase))[Idx])(classBase, args...);
	}
}

#define VF(returnType, name, idx, args, argsRaw) \
returnType name args noexcept \
{\
	return VFNC::callFunc<returnType, idx>argsRaw; \
}

#define VirtualFunction(returnType, name, idx, args, argsRaw) \
returnType name args noexcept \
{\
	return VF::callFunc<returnType, idx>argsRaw; \
}

#define VirtualFunctionEH(returnType, name, idx, args, argsRaw) \
returnType name args noexcept \
{\
	return VF::callFuncEH<returnType, idx>argsRaw; \
}

#define RNETVAR(type, name, baseClass, offset) \
	type name() { \
		return *reinterpret_cast<type*>(reinterpret_cast<unsigned long>(baseClass) + offset); \
	}

#define WNETVAR(type, name, baseClass, offset) \
	void Set##name(type val) { \
		*reinterpret_cast<type*>(reinterpret_cast<unsigned long>(baseClass) + offset) = val; \
	}

#define ANETVAR(type, name, baseClass, offset) \
	RNETVAR(type, name, baseClass, offset) \
	WNETVAR(type, name, baseClass, offset)