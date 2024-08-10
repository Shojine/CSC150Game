#pragma once
#include<string>

#define CLASS_DECLARATION(class) \
	static const char* GetTypename() { return #class; }

class Object 
{
public:
	Object() = default;
	Object(const std::string& name) : m_name{ name } {}
	virtual ~Object() = default;

	virtual void Initialize() = 0;
	virtual void Activate()   { active = true;  }
	virtual void Deactivate() { active = false; }

public:
	std::string m_name;
	bool active{ false };
};