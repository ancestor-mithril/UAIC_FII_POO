#pragma once
#include <tuple>
#include <vector>

namespace ninth_lab
{

	template<class T1, class T2>
	class Map
	{
		int _currentIndex = 0;
		std::vector<T1> _keys;
		std::vector<T2> _values;
	public:

		T2& operator[](T1 key);
		Map<T1, T2>& operator++();
		bool operator!=(Map<T1, T2>& other);
		std::tuple<T1, T2, std::size_t> operator*();
		Map<T1, T2>& begin();
		Map<T1, T2>& end();
		template<std::size_t Index>
		std::tuple_element<Index, Map<T1, T2>>& get(Map<T1, T2>& map);

		void Set(T1& key, T2& value);
		bool Get(const T1& key, T2& valueToBeCopied);
		unsigned Count();
		void Clear();
		bool Delete(const T1& key);
		bool Includes(const Map<T1, T2>& map);
	};

	template <class T1, class T2>
	T2& Map<T1, T2>::operator[](T1 key)
	{
		auto it = std::find(_keys.begin(), _keys.end(), key);
		
		if (it == _keys.end())
		{
			_keys.push_back(key);
			_values.push_back(T2{});
			return _values.back();
		}
		
		auto index = it - _keys.begin();
		return _values[index];
	}

	template <class T1, class T2>
	Map<T1, T2>& Map<T1, T2>::operator++()
	{
		_currentIndex++;
		return *this;
	}

	template <class T1, class T2>
	bool Map<T1, T2>::operator!=(Map<T1, T2>& other)
	{
		return !(_currentIndex == other._currentIndex);
	}

	template <class T1, class T2>
	std::tuple<T1, T2, std::size_t> Map<T1, T2>::operator*()
	{
		return std::make_tuple(_keys[_currentIndex], _values[_currentIndex], _currentIndex);
	}

	template <class T1, class T2>
	Map<T1, T2>& Map<T1, T2>::begin()
	{
		_currentIndex = 0;
		return *this;
	}

	template <class T1, class T2>
	Map<T1, T2>& Map<T1, T2>::end()
	{
		const int last = _keys.size()/* - 1*/;
		_currentIndex = last;
		
		return *this;
	}

	template <class T1, class T2>
	template <std::size_t Index>
	std::tuple_element<Index, Map<T1, T2>>& Map<T1, T2>::get(Map<T1, T2>& map)
	{
		if constexpr (Index == 0) return _keys[_currentIndex];
		if constexpr (Index == 1) return _values[_currentIndex];
		if constexpr (Index == 2) return _currentIndex;
	}

	template <class T1, class T2>
	void Map<T1, T2>::Set(T1& key, T2& value)
	{
		if (auto it = std::find(_keys.begin(), _keys.end(), key); it == _keys.end())
		{
			_keys.push_back(key);
			_values.push_back(value);
		}
		else
		{
			auto index = it - _keys.begin();
			_values[index] = value;
		}
	}

	template <class T1, class T2>
	bool Map<T1, T2>::Get(const T1& key, T2& valueToBeCopied)
	{
		if (auto it = std::find(_keys.begin(), _keys.end(), key); it == _keys.end())
		{
			return false;
		}
		else
		{
			auto index = it - _keys.begin();
			valueToBeCopied = _values[index];
			return true;
		}
	}

	template <class T1, class T2>
	unsigned Map<T1, T2>::Count()
	{
		return _keys.size();
	}

	template <class T1, class T2>
	void Map<T1, T2>::Clear()
	{
		_currentIndex = 0;
		_keys.clear();
		_values.clear();
	}

	template <class T1, class T2>
	bool Map<T1, T2>::Delete(const T1& key)
	{
		auto it = std::find(_keys.begin(), _keys.end(), key);
		
		if (it == _keys.end())
		{
			return false;
		}
		
		auto index = it - _keys.begin();
		_keys.erase(index);
		_values.erase(index);
		
		return true;
	}

	template <class T1, class T2>
	bool Map<T1, T2>::Includes(const Map<T1, T2>& map)
	{
		for (auto [key, value, index] : map)
		{
			if (std::find(_keys.begin(), _keys.end(), key) == _keys.end())
			{
				return false;
			}
		}
		
		return true;
	}
}

