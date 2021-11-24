#pragma once
#pragma once
#include <iostream>

//Trigonometric math
namespace math
{
	//ГСПЧ алгоритм рандома по сиду
	inline int rand(const int min, const int max, unsigned int seed)
	{
		seed = 8253729 * seed + 2396403;
		int rand = (8253729 * seed + 2396403) % (max + min + 1) - min;
		int i = 2;
		//Редко, но бывает, что не генерируется нужное число, поэтому:
		while (rand < min || rand > max)
		{
			rand = (8253729 * seed * i + 2396403) % (max + min) - min;
			i++;
		}
		return rand;
	}

	//ГСПЧ алгоритм рандома без сида
	inline int rand(const int min, const int max)
	{
		return rand(min, max, static_cast<int>(8253729 * (std::clock() / static_cast<float>(CLOCKS_PER_SEC))));
	}

	inline float __fastcall scale(const float a, const float b)
	{
		return a / b;
	}

};
