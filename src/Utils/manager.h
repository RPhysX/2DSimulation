#pragma once
#include <iostream>
#include <map>
#include <vector>

class Renderer;

template<typename T>
class Manager
{
public:
	Manager() = default;
	~Manager() = default;

	T operator[](std::string& name)
	{
		return data[name];
	}

	void setRenderer(Renderer rend);
	void pushValue(std::string& value, std::string& name);

	void loadValues();



private:
	std::vector<std::string> valueMap;
	std::vector<std::string> nameMap;
	std::map<std::string, T> data;

	Renderer& assignedRenderer;
};

