#pragma once

class Matrix {
public:
	virtual int get_size() const = 0;
	virtual ~Matrix() { };
};