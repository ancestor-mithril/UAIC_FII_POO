#pragma once
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

#include "CustomException.h"

namespace eleventh_lab
{
	class Compare
	{
	public:
		virtual ~Compare() = default;
		virtual int CompareElements(void* e1, void* e2) = 0;
	};

	template<class T>
	class ArrayIterator
	{
		int Current; // mai adaugati si alte date si functii necesare pentru iterator
		T** _pointer;
	public:
		explicit ArrayIterator(T** pointer);

		ArrayIterator& operator++ ();
		ArrayIterator& operator-- ();
		bool operator==(ArrayIterator<T>&);
		bool operator!=(ArrayIterator<T>&);

		T* GetElement();
	};

	template<class T>
	class Array
	{
		T** List; // lista cu pointeri la obiecte de tipul T*
		int Capacity; // dimensiunea listei de pointeri
		int Size; // cate elemente sunt in lista
		void increaseCapacity();
		void deleteList();
		void moveElementsToRight(int position, int steps);
		void moveElementsToLeft(int position, int steps);
	public:
		Array(); // Lista nu e alocata, Capacity si Size = 0
		~Array(); // destructor
		explicit Array(int capacity); // Lista e alocata cu 'capacity' elemente
		Array(const Array<T>& otherArray); // constructor de copiere

		T& operator[] (int index); // arunca exceptie daca index este out of range
		const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this

		const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
		const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
		const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

		Array<T>& operator=(const Array<T>& otherArray);
		bool operator==(const Array<T>& otherArray);

		void Sort(); // sorteaza folosind comparatia intre elementele din T
		void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
		void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

		// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
		int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
		int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
		int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

		int Find(const T& elem); // cauta un element in Array
		int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
		int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

		int GetSize();
		int GetCapacity();

		ArrayIterator<T> GetBeginIterator();
		ArrayIterator<T> GetEndIterator();

	};

	template <class T>
	ArrayIterator<T>::ArrayIterator(T** pointer) : Current(0), _pointer(pointer)
	{
	}

	template <class T>
	ArrayIterator<T>& ArrayIterator<T>::operator++()
	{
		Current++;
	}

	template <class T>
	ArrayIterator<T>& ArrayIterator<T>::operator--()
	{
		Current--;
	}

	template <class T>
	bool ArrayIterator<T>::operator==(ArrayIterator<T>& other)
	{
		return _pointer + Current == other._pointer + other.Current;
	}

	template <class T>
	bool ArrayIterator<T>::operator!=(ArrayIterator<T>& other)
	{
		return !(this == other);
	}

	template <class T>
	T* ArrayIterator<T>::GetElement()
	{
		return _pointer[Current];
	}

	template <class T>
	void Array<T>::increaseCapacity()
	{
		const auto newCapacity = 2 * Capacity;
		auto newList = new T * [newCapacity];
		memcpy(newList, List, Capacity * sizeof(T));
		Capacity = newCapacity;
		delete[] List;
		List = newList;
	}

	template <class T>
	void Array<T>::deleteList()
	{
		for (auto i = 0; i < Size; i++)
		{
			delete List[i];
		}
		delete[] List;
	}

	template <class T>
	void Array<T>::moveElementsToRight(const int position, const int steps)
	{
		if (position < 0 || position >= Size)
		{
			throw std::out_of_range("Index out of range: " + std::to_string(position));
		}

		while (Size + steps > Capacity)
		{
			increaseCapacity();
		}

		for (int i = Size - 1; i >= position; --i)
		{
			List[i + steps] = std::copy(List[i]); //move should be okay
		}
		Size += steps;
	}

	template <class T>
	void Array<T>::moveElementsToLeft(const int position, const int steps)
	{
		if (position < 0 || position >= Size)
		{
			throw std::out_of_range("Index out of range: " + std::to_string(position));
		}
		if (position + steps >= Size)
		{
			throw utils::CustomException("Position: " + std::to_string(position) + " and steps: " + std::to_string(steps) + " are greater than size");
		}

		for (int i = 0; i < steps; ++i)
		{
			List[position + i] = std::move(List[position + i + 1]);
		}
		Size -= steps;
	}

	template <class T>
	Array<T>::Array() : List(nullptr), Capacity(0), Size(0)
	{
	}

	template <class T>
	Array<T>::~Array()
	{
		deleteList();
	}

	template <class T>
	Array<T>::Array(const int capacity) : Capacity(capacity), Size(0)
	{
		List = new T * [capacity];
	}

	template <class T>
	Array<T>::Array(const Array<T>& otherArray) : List(std::copy(otherArray.List)), Capacity(otherArray.Capacity), Size(otherArray.Size)
	{
	}

	template <class T>
	T& Array<T>::operator[](int index)
	{
		if (index < 0 || index >= Size)
		{
			throw std::out_of_range("Index out of range: " + std::to_string(index));
		}
		return List[index];
	}

	template <class T>
	const Array<T>& Array<T>::operator+=(const T& newElem)
	{
		Size++;
		if (Capacity < Size)
		{
			increaseCapacity();
		}
		List[Size - 1] = newElem;
		return *this;
	}

	template <class T>
	const Array<T>& Array<T>::Insert(const int index, const T& newElem)
	{
		moveElementsToRight(index, 1);
		List[index] = newElem;
		return *this;
	}

	template <class T>
	const Array<T>& Array<T>::Insert(const int index, const Array<T> otherArray)
	{
		moveElementsToRight(index, otherArray.Size);
		for (int i = 0; i < otherArray.Size; ++i)
		{
			List[index + i] = std::move(otherArray.List[i]);
		}
		return *this;
	}

	template <class T>
	const Array<T>& Array<T>::Delete(const int index)
	{
		moveElementsToLeft(index, 1);
		return *this;
	}

	template <class T>
	Array<T>& Array<T>::operator=(const Array<T>& otherArray)
	{
		if (this == &otherArray)
		{
			return &this;
		}
		deleteList();
		List = std::move(otherArray.List);
		Size = otherArray.Size;
		Capacity = otherArray.Capacity;
		return true;
	}

	template <class T>
	bool Array<T>::operator==(const Array<T>& otherArray)
	{
		if (Size != otherArray.Size)
		{
			return false;
		}
		for (auto i = 0; i < Size; ++i)
		{
			if (*List[i] != *otherArray.List[i])
			{
				return false;
			}
		}
		return true;
	}

	template <class T>
	void Array<T>::Sort()
	{
		std::sort(List, List + Size);
	}

	template <class T>
	void Array<T>::Sort(int(*compare)(const T&, const T&))
	{
		std::sort(List, List + Size, compare);
	}

	template <class T>
	void Array<T>::Sort(Compare* comparator)
	{
		std::sort(List, List + Size, comparator);
	}

	template <class T>
	int Array<T>::BinarySearch(const T& elem)
	{
		if (std::binary_search(List, List + Size, elem))
		{
			return std::lower_bound(List, List + Size, elem);
		}
		return -1;
	}

	template <class T>
	int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		if (std::binary_search(List, List + Size, elem, compare))
		{
			return std::lower_bound(List, List + Size, elem, compare);
		}
		return -1;
	}

	template <class T>
	int Array<T>::BinarySearch(const T& elem, Compare* comparator)
	{
		if (std::binary_search(List, List + Size, elem, comparator))
		{
			return std::lower_bound(List, List + Size, elem, comparator);
		}
		return -1;
	}

	template <class T>
	int Array<T>::Find(const T& elem)
	{
		auto it = std::find(List, List + Size, elem); //May not work

		if (it == List + Size)
		{
			return -1;
		}
		return it - List;
	}

	template <class T>
	int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
	{
		auto it = std::find(List, List + Size, elem, compare); //May not work

		if (it == List + Size)
		{
			return -1;
		}
		return it - List;
	}

	template <class T>
	int Array<T>::Find(const T& elem, Compare* comparator)
	{
		auto it = std::find(List, List + Size, elem, comparator); //May not work

		if (it == List + Size)
		{
			return -1;
		}
		return it - List;
	}

	template <class T>
	int Array<T>::GetSize()
	{
		return Size;
	}

	template <class T>
	int Array<T>::GetCapacity()
	{
		return Capacity;
	}

	template <class T>
	ArrayIterator<T> Array<T>::GetBeginIterator()
	{
		return new ArrayIterator<T>(List);
	}

	template <class T>
	ArrayIterator<T> Array<T>::GetEndIterator()
	{
		return new ArrayIterator<T>(List + Size);
	}
}
