#include "manager.h"
#include "../Core/entity.h"
#include "../Common/texture.h"
#include "../Utils/common.h"
#include "../Core/atom.h"
#include "../Renderer/renderer.h"

template<typename T>
inline void Manager<T>::setRenderer(Renderer rend)
{
	assignedRenderer = rend;
}

template<typename T>
inline void Manager<T>::pushValue(std::string& value, std::string& name)
{
	valueMap.push_back(value);
	//if name and value are same create a copy of type 'name + id'
	if(name)
	nameMap.push_back(name);
}

template<typename T>
void Manager<T>::loadValues()
{
	int p = 0;
	for (auto val : valueMap)
	{
		data.emplace(nameMap[p], common::loadEntity<T>(val, assignedRenderer));
		assignedRenderer.push(data[nameMap[p++]]);
	}
}
