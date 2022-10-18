#pragma once
#include "vec.h"
class Matrix
{
private:
	Vec a;
	Vec b;
	Vec c;
	Vec p;
	Vec q;
	int size;
	int k;
	//согласование - место пересечение - одинаковые числа в векторах должны быть
	void agreementpq();
public:
	void agreement();
	Matrix(int _size);
	Matrix(int _size, int d1, int d2, int db1, int db2, int dc1, int dc2, int dpq1, int dpq2,int _k);
	Matrix(int _size, Vec _a, Vec _b, Vec _c, Vec _p, Vec _q);
	void aSet(Vec vec1);
	void bSet(Vec vec1);
	void cSet(Vec vec1);
	void pSet(Vec vec1);
	void qSet(Vec vec1);
	void kset(int _k);
	void sizeSet(int _size);
	Vec aGet();
	Vec bGet();
	Vec cGet();
	Vec pGet();
	Vec qGet();
	int sizeGet();
	int kGet();
	Vec step1(Vec f);
	Vec step2(Vec f);
	Vec step3(Vec f);
	Vec step4(Vec f);
	Matrix operator+(Matrix& obj);
	Matrix operator-(Matrix& obj);
	Vec operator*(Vec& obj);
	friend istream& operator>>(istream& in, Matrix& obj);
	friend ostream& operator<<(ostream& out, Matrix obj);
	~Matrix();
};

