#pragma once
#include<string>

class Object 
{
public:
	Object() = default;
	Object(const std::string& name) : m_name{ name } {}

	virtual void Initialize() = 0;
	virtual void Activate()   { active = true;  }
	virtual void Deactivate() { active = false; }

public:
	std::string m_name;
	bool active{ false };
};