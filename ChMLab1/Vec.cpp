#include "vec.h"

Vec::Vec()
{
	size = 0;
}

Vec::Vec(int _size)
{
	size = _size;
}

Vec::Vec(int _size, int d1, int d2)
{
	size = _size;
	int random;
	for (int i = 0; i < _size; i++)
	{
		random = rand() % (d2 - d1 + 1) + d1;
		while (random == 0)
			random += rand() % (d2 - d1 + 1) + d1;
		vector.push_back(random);
	}
}

Vec::Vec(int _size, std::vector<double> _vector)
{
	size = _size;
	vector = _vector;
}

void Vec::setSize(int _size)
{
	size = _size;
}

int Vec::getSize()
{
	return size;
}

void Vec::setVector(std::vector<double> _vector)
{
	vector = _vector;
}

std::vector<double> Vec::getVector()
{
	return vector;
}

Vec Vec::operator+(Vec& obj)
{
	std::vector <double> vec1;

	if (size == obj.getSize())
	{
		for (int i = 0; i < size; i++)
			vec1.push_back(vector[i] + obj.getVector()[i]);
		return Vec(size, vec1);
	}
	else
		return Vec(size);
}

Vec Vec::operator+(std::vector<double> _vector)
{
	std::vector <double> vec1;
	if (size == _vector.size())
	{
		for (int i = 0; i < size; i++)
			vec1.push_back(vector[i] + _vector[i]);
		return Vec(size, vec1);
	}
	else return Vec(size);
}

Vec Vec::operator-(Vec& obj)
{

	std::vector <double> vec1;

	if (size == obj.getSize())
	{
		for (int i = 0; i < size; i++)
			vec1.push_back(vector[i] - obj.getVector()[i]);
		return Vec(size, vec1);
	}
	else
		return Vec(size);
}

Vec Vec::operator-(std::vector<double> _vector)
{
	std::vector <double> vec1;
	if (size == _vector.size())
	{
		for (int i = 0; i < size; i++)
			vec1.push_back(vector[i] - _vector[i]);
		return Vec(size, vec1);
	}
	else return Vec(size);
}

double Vec::operator*(Vec& obj)
{
	//scp- число 
	double skp = 0;

	if (size == obj.getSize())
	{
		for (int i = 0; i < size; i++)
			skp += vector[i] * obj.getVector()[i];
		return skp;
	}
	else
		return skp;
}

Vec Vec::operator*(double number)
{
	std::vector <double> vec1;

	for (int i = 0; i < size; i++)
		vec1.push_back(vector[i] * number);
	return Vec(size, vec1);
}

double Vec::operator*(std::vector<double> _vector)
{
	double skp = 0;
	if (size == _vector.size())
	{
		for (int i = 0; i < size; i++)
			skp += vector[i] * _vector[i];
		return skp;
	}
	return skp;
}

void Vec::operator=(Vec obj)
{
	vector = obj.getVector();
	size = obj.getSize();
}

void Vec::operator=(std::vector<double> _vector)
{
	vector = _vector;
	size = _vector.size();
}
//Ќахождение по модулю самого большого числа
double Vec::modul()
{
	double max = abs(vector[0]);
	for (int i = 0; i < size; i++)
	{
		if (abs(vector[i]) > max)
			max = abs(vector[i]);
	}
	return max;
}

Vec::~Vec()
{
}


istream& operator>>(istream& in, Vec& obj)
{
	double number;
	vector<double> vec1;
	for (int i = 0; i < obj.getSize(); i++)
	{
		in >> number;
		vec1.push_back(number);
	}
	obj.setVector(vec1);
	return in;
}

ostream& operator<<(ostream& out, Vec obj)
{

	for (int i = 0; i < obj.getSize(); i++)
	{
		out << obj.getVector()[i] << "; ";
	}
	return out;
}
