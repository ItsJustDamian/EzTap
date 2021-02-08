#pragma once
#include <iostream>
#include "../../VirtualFunction.hpp"

#define EVENT_DEBUG_ID_INIT 42
#define EVENT_DEBUG_ID_SHUTDOWN 13

struct bf_read;
struct bf_write;

class IGameEvent;
class KeyValues;

class IGameEvent
{
public:
	virtual ~IGameEvent() {};
	virtual const char* GetName() const = 0;

	virtual bool IsReliable() const = 0;
	virtual bool IsLocal() const = 0;
	virtual bool IsEmpty(const char* keyname = NULL) = 0;

	virtual bool GetBool(const char* keyname = NULL, bool default_value = false) = 0;
	virtual int GetInt(const char* keyname = NULL, int default_value = 0) = 0;
	virtual uint64_t GetUint64(const char* keyname = NULL, uint64_t default_value = 0) = 0;
	virtual float GetFloat(const char* keyname = NULL, float default_value = 0.0f) = 0;
	virtual const char* GetString(const char* keyname = NULL, const char* default_value = "") = 0;
	virtual const wchar_t* GetWString(const char* keyname = NULL, const wchar_t* default_value = L"") = 0;
	virtual const void* GetPtr(const char* keyname = NULL, const void* default_values = NULL) = 0;

	virtual void SetBool(const char* keyname, bool value) = 0;
	virtual void SetInt(const char* keyname, int value) = 0;
	virtual void SetUint64(const char* keyname, uint64_t value) = 0;
	virtual void SetFloat(const char* keyname, float value) = 0;
	virtual void SetString(const char* keyname, const char* value) = 0;
	virtual void SetWString(const char* keyname, const wchar_t* value) = 0;
	virtual void SetPtr(const char* keyname, const void* value) = 0;
};

class IGameEventListener2
{
public:
	virtual ~IGameEventListener2(void) {}

	virtual void FireGameEvent(IGameEvent* event) = 0;
	virtual int  GetEventDebugID(void) = 0;

public:
	int m_iDebugId;
};

class IGameEventManager2
{
public:
	VF(bool, addListener, 3, (IGameEventListener2* listener, const char* name), (this, listener, name, false));
	VF(void, removeListener, 5, (IGameEventListener2* listener), (this, listener));

};