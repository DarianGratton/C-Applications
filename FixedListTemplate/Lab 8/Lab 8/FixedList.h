#pragma once

#include "InvalidIndexException.h"

template<class T, size_t N = 25>
class FixedList {
private:
	T contents[N];
	size_t num_of_elements;
public:
	FixedList() : num_of_elements{ 0 } { }
	~FixedList() { }

	// PRE: index < N
	// POST: Gets the value of the element in the
	//		 entered index
	// RETURN: the element in the entered index
	const T& get(unsigned int index) const
	{
		if (index >= N) {
			throw InvalidIndexException();
		}
		return contents[index];
	}

	// PRE: index < N
	// POST: Gets the value of the element in the
	//		 entered index
	// RETURN: the element in the entered index
	T& operator[](unsigned int index)
	{
		if (index >= N) {
			throw InvalidIndexException();
		}
		return contents[index];
	}

	// PRE: t != null
	// POST: Gets the index of the first occurence of the 
	//		 entered element
	// RETURN: the index of the first occurence of the element,
	//		   if element isn't found, returns 1
	int getFirstIndex(const T& t) const
	{
		for (int i = 0; i < capacity(); ++i) {
			if (contents[i] == t) {
				return i;
			}
		}
		return -1;
	}
 
	// RETURN: the number of elements in the fixed list 
	size_t size() const
	{
		return num_of_elements;
	}

	// RETURN: the max size of the fixed list
	size_t capacity() const
	{
		return N;
	}

	// PRE: number of elements < max capacity
	// POST: adds an element to the fixed list, and returns
	//       a boolean for whether it was successful or not
	// RETURN: false if the list is full, true if the insert was successful
	bool add(const T& t)
	{
		if (size() == capacity()) {
			return false;
		}
		contents[size()] = t;
		num_of_elements++;
		return true;
	}

	// PRE: list is not empty
	// POST: removes and returns the first occurrence of a given element
	//		 in the list, the empty space is filled by shifting any elements
	//		 towards the space to close it
	// RETURN: The first occurence of a given element in the list
	T remove(const T& t)
	{
		T element;
		int index = getFirstIndex(t);

		element = contents[index];
		contents[index] = NULL;
		num_of_elements--;
		for (int i = index; i < size(); ++i) {
			contents[i] = contents[i + 1];
		}

		return element;
	}
};