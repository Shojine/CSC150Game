#pragma once
#include "Resource.h"
#include "../Core/Singleton.h"
#include<map>
#include<iostream>

class ResourceManager : public Singleton<ResourceManager>
{
public:
	template<typename T, typename ... TArgs>
	inline res_t<T> Get(const std::string& name, TArgs ... args);

	friend class Singleton;
	
private:
	std::map<std::string, res_t<Resource>> m_recources;
};

template<typename T, typename ... TArgs>
inline res_t<T> ResourceManager::Get(const std::string& name, TArgs ... args)
{
	if (m_recources.find(name) != m_recources.end())
	{
		//return recource 
		return std::dynamic_pointer_cast<T>(m_recources[name]);
	}
	//resource not found, create resource
	res_t<T> resource = std::make_shared<T>();
	if (!resource->Create(name, args ...))
	{
		//resource not created
		std::cerr << "Could not create resource: " << name << std::endl;
		return res_t<T>();
	}
	m_recources[name] = resource;
	return resource;
}