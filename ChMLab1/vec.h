#pragma once
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class Vec
{
private:
	vector <double> vector;
	int size;
public:
	Vec();
	Vec(int _size);
	//d1 d2 - диапозоны
	Vec(int _size, int d1, int d2);
	Vec(int _size, std::vector<double> _vector);
	void setSize(int _size);
	int getSize();
	void setVector(std::vector<double> _vector);
	std::vector<double> getVector();
	Vec operator+(Vec& obj);
	Vec operator+(std::vector<double> _vector);
	Vec operator-(Vec& obj);
	Vec operator-(std::vector<double> _vector);
	double operator*(Vec& obj);
	Vec operator*(double number);
	double operator*(std::vector<double> _vector);
	void operator=(Vec obj);
	void operator=(std::vector<double> _vector);
	double modul();
	friend istream& operator>>(istream& in, Vec& obj);
	friend ostream& operator<<(ostream& out, Vec obj);
	~Vec();
};




