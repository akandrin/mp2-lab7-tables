#pragma once
#include <random>
#include <algorithm>

template<class T>
struct NextValue
{
	T operator()(T value) { return value + 1; }
};

template<class T>
class RandomRange
{
	std::vector<T> data;
	size_t index = 0;
public:
	template<class FunctorNextValue>
	RandomRange(T begin, T end, FunctorNextValue&& func)
	{
		for (; begin != end; begin = func(begin))
		{
			data.push_back(begin);
		}
		data.push_back(begin);
		std::random_device rd;
		std::mt19937 generator(rd());
		std::shuffle(data.begin(), data.end(), generator);
	}

	T GetNext()
	{
		return data[index++];
	}

	bool HasNext() const
	{
		return index < data.size();
	}
};

