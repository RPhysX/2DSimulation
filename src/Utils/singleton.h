#pragma once
#include <typeinfo>
/* 
*  =======================================================
*  singleton.h
*  2DSimulation
*
*  Created by Primemaster on 03/10/2017.
*  Copyright 2017 RPhysX. All rights reserved.
*
*  =======================================================
*/

/*
Bases: null
Definition: A class wich is instatiated only once trought the program's lifetime (Automatically)
Implementation: Make this class a parent of the desired singleton class, this class type is initialized only when the method Instace() is called
*/
template<typename T>
class Singleton
{
public:
	Singleton() {};
	Singleton(const Singleton&) = delete; //Not copiable
	Singleton(Singleton&&) = delete; //Not movable - Not exactly needed in C++11
	Singleton& operator=(const Singleton&) = delete; //No self-assignment
	Singleton& operator=(Singleton&&) = delete; //No self-assignment [move]

public:
	static T * Instance()
	{
		static T instance; //Ensures the instance is deleted automatically in the end of the program lifetime
		std::cout << "Singleton of type " << typeid(T).name() << " was instatiated successfully with ID: [" << typeid(T).raw_name() << "]" << std::endl;

		return &instance;
	}
};

