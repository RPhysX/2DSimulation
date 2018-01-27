#pragma once
#include <iostream>
#include <typeinfo>
/*
*  =======================================================
*  math.h
*  2DSimulation
*
*  Created by Primemaster on 09/10/2017.
*  Copyright 2017 RPhysX.
*
*  =======================================================
*/

/*
Bases: null
Definition: Math helper functions and definitions
Implementation: Math functions and elements (e.g. Vectors)
*/

namespace math
{

	union Polar;
	typedef float Angle;

	/* Vector2f */
	template<typename T>
	struct Vector2
	{
		Vector2() //default ctor
		{
			this->x = 0;
			this->y = 0;
		}

		Vector2(T x, T y) //explicit ctor
		{
			this->x = x;
			this->y = y;
		}

		void operator()(T x, T y) //operator() ctor like
		{
			this->x = x;
			this->y = y;
		}

		T x;
		T y;

		inline T abs() //absolute value of vector
		{
			return sqrt(x*x + y*y);
		}

		inline Vector2<T> normalize() //vector normalization
		{
			T absV = abs();
			return Vector2<T>(x / absV, y / absV);
		}

		inline Vector2<Polar> polar() //vector normalization
		{
			return Vector2<Polar>(atan(y/x), abs());
		}
	};

	template<>
	struct Vector2<Polar>
	{
		Vector2() //default ctor
		{
			this->theta = 0;
			this->radius = 0;
		}

		Vector2(Angle theta, float radius) //explicit ctor
		{
			this->theta = theta;
			this->radius = radius;
		}

		void operator()(Angle theta, float radius) //operator() ctor like
		{
			this->theta = theta;
			this->radius = radius;
		}

		Angle theta;
		float radius;

		inline float abs() //absolute value of vector
		{
			return radius;
		}

		template<typename T>
		inline Vector2<Polar> cartesian() //vector normalization to cartesian coordenates
		{
			return Vector2<T>(radius * cos(theta), radius * sin(theta));
		}
	};

	typedef Vector2<double> Vector2d;
	typedef Vector2<float> Vector2f;
	typedef Vector2<Polar> PVector2f;
}

//Marmonte is love, Duramonte is life