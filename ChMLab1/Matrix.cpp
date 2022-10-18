#include "matrix.h"

void Matrix::agreementpq()
{
	vector<double> a1, b1, c1;
	a1.push_back(p.getVector()[1]);
	a1.push_back(q.getVector()[2]);
	b1.push_back(p.getVector()[0]);
	b1.push_back(q.getVector()[1]);
	c1.push_back(q.getVector()[0]);
	for (int i = 2; i < size; i++)
	{
		if (i != size - 1)
			a1.push_back(a.getVector()[i]);
		b1.push_back(b.getVector()[i]);
		c1.push_back(c.getVector()[i - 1]);
	}
	a.setVector(a1);
	b.setVector(b1);
	c.setVector(c1);
}

void Matrix::agreement()
{
	vector<double> p1, q1;
	p1.push_back(b.getVector()[0]);
	p1.push_back(a.getVector()[0]);
	p1.push_back(p.getVector()[2]);
	q1.push_back(c.getVector()[0]);
	q1.push_back(b.getVector()[1]);
	q1.push_back(a.getVector()[1]);
	for (int i = 3; i < size; i++)
	{
		p1.push_back(p.getVector()[i]);
		q1.push_back(q.getVector()[i]);
	}
	p.setVector(p1);
	q.setVector(q1);
}

Matrix::Matrix(int _size)
{
	size = _size;
	a = Vec(_size - 1);
	b = Vec(_size);
	c = Vec(_size - 1);
	p = Vec(_size);
	q = Vec(_size);
}

Matrix::Matrix(int _size, int da1, int da2, int db1, int db2, int dc1, int dc2, int dpq1, int dpq2)
{
	a = Vec(_size - 1, da1, da2);
	b = Vec(_size, db1, db2);
	c = Vec(_size - 1, dc1, dc2);
	p = Vec(_size, dpq1, dpq2);
	q = Vec(_size, dpq1, dpq2);
	size = _size;
	agreement();
}

Matrix::Matrix(int _size, Vec _a, Vec _b, Vec _c, Vec _p, Vec _q)
{
	size = _size;
	a = _a;
	b = _b;
	c = _c;
	p = _p;
	q = _q;
	agreement();
}


void Matrix::aSet(Vec vec1)
{
	a = vec1;
}


void Matrix::bSet(Vec vec1)
{
	b = vec1;
}


void Matrix::cSet(Vec vec1)
{
	c = vec1;
}


void Matrix::pSet(Vec vec1)
{
	p = vec1;
}

void Matrix::qSet(Vec vec1)
{
	q = vec1;
}

void Matrix::sizeSet(int _size)
{
	size = _size;
}

Vec Matrix::aGet()
{
	return a;
}
Vec Matrix::bGet()
{
	return b;
}
Vec Matrix::cGet()
{
	return c;
}
Vec Matrix::pGet()
{
	return p;
}
Vec Matrix::qGet()
{
	return q;
}

int Matrix::sizeGet()
{
	return size;
}

Vec Matrix::step1(Vec f)
{
	vector<double> f1 = f.getVector(), ex, ex1;

	double R = 1 / b.getVector()[0];
	ex.push_back(c.getVector()[0] * R);
	f1[0] *= R;
	ex1.push_back(p.getVector()[0] * R);
	for (int i = 1; i < size; i++)
	{
		ex.push_back(q.getVector()[i] - p.getVector()[i] * ex[0]);
		f1[i] -= p.getVector()[i] * f1[0];
		ex1.push_back(p.getVector()[i] - ex1[0] * p.getVector()[i]);
	}
	p = Vec(size, ex1);
	q = Vec(size, ex);
	agreementpq();

	return Vec(f.getSize(), f1);
}

Vec Matrix::step2(Vec f)
{
	double del;

	vector<double> f1 = f.getVector(), a1, b1, c1, q1;
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
		{
			a1.push_back(0);
			c1.push_back(0);
		}
		b1.push_back(0);
		q1.push_back(0);
	}
	del = 1 / b.getVector()[size - 1];
	b1[size - 1] = 1;
	a1[size - 2] = a.getVector()[size - 2] * del;
	q1[size - 1] = q.getVector()[size - 1] * del;
	c1[size - 2] = 0;
	f1[size - 1] = f.getVector()[size - 1] * del;
	f1[size - 2] = f.getVector()[size - 2] - f1[size - 1] * c.getVector()[size - 2];
	b1[size - 2] = b.getVector()[size - 2] - a1[size - 2] * c.getVector()[size - 2];
	q1[size - 2] = q.getVector()[size - 2] - q1[size - 1] * c.getVector()[size - 2];
	for (int i = size - 2; i > 0; i--)
	{
		del = 1 / b1[i];
		b1[i] = 1;
		a1[i - 1] = a.getVector()[i - 1] * del;
		if (i != 1)
			f1[i] *= del;
		else f1[i] /= q1[i];
		q1[i] = q1[i] * del;
		c1[i - 1] = 0;
		f1[i - 1] = f.getVector()[i - 1] - f1[i] * c.getVector()[i - 1];
		b1[i - 1] = b.getVector()[i - 1] - a1[i - 1] * c.getVector()[i - 1];
		q1[i - 1] = q.getVector()[i - 1] - q1[i] * c.getVector()[i - 1];
	}
	b1[1] = 1;
	c1[0] = 0;
	q1[1] = 1;
	q1[0] = 0;
	q = Vec(size, q1);
	a = Vec(size - 1, a1);
	b = Vec(size, b1);
	c = Vec(size - 1, c1);
	agreementpq();
	return Vec(f.getSize(), f1);
}

Vec Matrix::step3(Vec f)
{
	vector<double> f1 = f.getVector(), q1;
	q1.push_back(0);
	q1.push_back(1);
	for (int i = 2; i < size; i++)
	{
		q1.push_back(q.getVector()[i] - q.getVector()[i] * q.getVector()[1]);
		f1[i] = f.getVector()[i] - q.getVector()[i] * f.getVector()[1];
	}
	q = Vec(size, q1);
	agreementpq();
	return Vec(f.getSize(), f1);
}
//
//Vec Matrix::step4(Vec f)
//{
//	vector<double>  f1 = f.getVector(), a1;
//	a1.push_back(0);
//	a1.push_back(0);
//	for (int i = 2; i < size - 1; i++)
//	{
//		a1.push_back(a.getVector()[i] - b.getVector()[i + 1] * a.getVector()[i]);
//		f1[i + 1] = f1[i + 1] - f1[i] * a.getVector()[i];
//	}
//	a = Vec(size-1, a1);
//	return Vec(f.getSize(),f1);
//}

Vec Matrix::step4(Vec f)
{
	vector<double>  x1;
	x1.push_back(f.getVector()[0]);
	x1.push_back(f.getVector()[1]);
	x1.push_back(f.getVector()[2]);
	for (int i = 2; i < size - 1; i++)
	{
		x1.push_back(f.getVector()[i + 1] - x1[i] * a.getVector()[i]);
	}

	return Vec(f.getSize(), x1);
}

Matrix Matrix::operator+(Matrix& obj)
{
	Vec a1 = a, b1 = obj.aGet();
	Matrix ex(obj.sizeGet());
	ex.aSet(a1 + b1);
	a1 = b; b1 = obj.bGet();
	ex.bSet(a1 + b1);
	a1 = c; b1 = obj.cGet();
	ex.cSet(a1 + b1);
	a1 = p; b1 = obj.pGet();
	ex.pSet(a1 + b1);
	a1 = q; b1 = obj.qGet();
	ex.qSet(a1 + b1);
	return ex;
}

Matrix Matrix::operator-(Matrix& obj)
{
	Vec a1 = a, b1 = obj.aGet();
	Matrix ex(obj.sizeGet());
	ex.aSet(a1 - b1);
	a1 = b; b1 = obj.bGet();
	ex.bSet(a1 - b1);
	a1 = c; b1 = obj.cGet();
	ex.cSet(a1 - b1);
	a1 = p; b1 = obj.pGet();
	ex.pSet(a1 - b1);
	a1 = q; b1 = obj.qGet();
	ex.qSet(a1 - b1);
	return ex;
}

Vec Matrix::operator*(Vec& obj)
{
	if (size == obj.getSize())
	{
		vector <double> ex;
		double number = 0;
		for (int i = 0; i < size; i++)
		{
			switch (i)
			{
			case(0):
				ex.push_back(b.getVector()[0] * obj.getVector()[0] + c.getVector()[0] * obj.getVector()[1]);
				break;
			case(1):
				ex.push_back(a.getVector()[0] * obj.getVector()[0] + b.getVector()[1] * obj.getVector()[1] + c.getVector()[1] * obj.getVector()[2]);
				break;
			case(2):
				ex.push_back(p.getVector()[2] * obj.getVector()[0] + a.getVector()[1] * obj.getVector()[1] + b.getVector()[2] * obj.getVector()[2] + c.getVector()[2] * obj.getVector()[3]);
				break;
			default:
				number = p.getVector()[i] * obj.getVector()[0] + q.getVector()[i] * obj.getVector()[1];
				if (i != size - 1)
					number += a.getVector()[i - 1] * obj.getVector()[i - 1] + b.getVector()[i] * obj.getVector()[i] + c.getVector()[i] * obj.getVector()[i + 1];
				else number += a.getVector()[i - 1] * obj.getVector()[i - 1] + b.getVector()[i] * obj.getVector()[i];
				ex.push_back(number);
				break;
			}
		}
		return Vec(size, ex);
	}
	else return Vec();

}

Matrix::~Matrix()
{
	a.~Vec();
	b.~Vec();
	c.~Vec();
	p.~Vec();
	q.~Vec();
}

istream& operator>>(istream& in, Matrix& obj)
{
	double number;
	vector <double> ex;
	cout << "Input a:";
	for (int i = 0; i < obj.aGet().getSize(); i++)
	{
		in >> number;
		ex.push_back(number);
	}
	obj.aSet(Vec(obj.aGet().getSize(), ex));
	ex.clear();
	cout << "Input b:";
	for (int i = 0; i < obj.bGet().getSize(); i++)
	{
		in >> number;
		ex.push_back(number);
	}
	obj.bSet(Vec(obj.bGet().getSize(), ex));
	ex.clear();
	cout << "Input c:";
	for (int i = 0; i < obj.cGet().getSize(); i++)
	{
		in >> number;
		ex.push_back(number);
	}
	obj.cSet(Vec(obj.cGet().getSize(), ex));
	ex.clear();
	cout << "Input p:";
	for (int i = 0; i < obj.pGet().getSize(); i++)
	{
		in >> number;
		ex.push_back(number);
	}
	obj.pSet(Vec(obj.pGet().getSize(), ex));
	ex.clear();
	cout << "Input q:";
	for (int i = 0; i < obj.qGet().getSize(); i++)
	{
		in >> number;
		ex.push_back(number);
	}
	obj.qSet(Vec(obj.qGet().getSize(), ex));
	ex.clear();
	obj.agreement();
	return in;
}

ostream& operator<<(ostream& out, Matrix obj)
{
	for (int i = 0; i < obj.sizeGet(); i++)
	{
		switch (i)
		{
		case(0):
			out << obj.bGet().getVector()[0] << " " << obj.cGet().getVector()[0] << " ";
			for (int j = 2; j < obj.sizeGet(); j++)
			{
				out << "0 ";
			}
			out << "\n";
			break;
		case(1):
			out << obj.aGet().getVector()[0] << " " << obj.bGet().getVector()[1] << " " << obj.cGet().getVector()[1] << " ";
			for (int j = 3; j < obj.sizeGet(); j++)
			{
				out << "0 ";
			}
			out << "\n";
			break;
		case(2):
			out << obj.pGet().getVector()[2] << " " << obj.aGet().getVector()[1] << " " << obj.bGet().getVector()[2] << " " << obj.cGet().getVector()[2] << " ";
			for (int j = 4; j < obj.sizeGet(); j++)
			{
				out << "0 ";
			}
			out << "\n";
			break;
		default:
			out << obj.pGet().getVector()[i] << " " << obj.qGet().getVector()[i] << " ";
			for (int j = 2; j < i - 1; j++)
			{
				out << "0 ";
			}
			if (i != obj.sizeGet() - 1)
				out << obj.aGet().getVector()[i - 1] << " " << obj.bGet().getVector()[i] << " " << obj.cGet().getVector()[i] << " ";
			else out << obj.aGet().getVector()[i - 1] << " " << obj.bGet().getVector()[i];
			for (int j = i + 2; j < obj.sizeGet(); j++)
			{
				out << "0 ";
			}
			out << "\n";
			break;
		}
	}
	return out;
}
