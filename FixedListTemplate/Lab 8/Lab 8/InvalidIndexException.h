#pragma once

#include <exception>

class InvalidIndexException : public std::exception
{
	virtual const char * what() const noexcept {
		return "Invalid index";
	}
};