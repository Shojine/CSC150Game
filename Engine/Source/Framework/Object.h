#pragma once
#include<string>
#include "Core/Serializable.h"

#define CLASS_DECLARATION(classname) \
	static const char* GetTypename() { return #classname; } \
	virtual void Read(const json_t& value); \
	virtual void Write(json_t& value);

#define FACTORY_REGISTER(classname) \
	class Register##classname													\
{																	\
	public:															\
	Register##classname()														\
	{																\
		Factory::Instance().Register<classname>(#classname);		\
	}																\
}; \
	static Register##classname register_instance;

#define CLASS_PROTOTYPE(classname) \
	virtual std::unique_ptr<Object> Clone() \
	{											\
		return std::make_unique<classname>(*this);									\
	};								


class Object : public Serializable
{
public:
	Object() = default;
	Object(const std::string& name) : m_name{ name } {}
	virtual ~Object() = default;
	virtual std::unique_ptr<Object> Clone() = 0;


	CLASS_DECLARATION(Object)
	//CLASS_PROTOTYPE(Object)

	virtual void Initialize() = 0;
	virtual void Activate()   { active = true;  }
	virtual void Deactivate() { active = false; }

public:
	std::string m_name;
	bool active{ true };
	bool persistent{ true };
};