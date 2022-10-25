#include <iostream>
#include <random>
#include <vector>
#include "Vec.h"
#include "Matrix.h"
using namespace std;

void print(vector<int> a)
{

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

}

int main()
{
    
    Matrix matr(14, 0, 9, 0, 9, 0, 9, -0, 9,8);
    Vec x(14, 0, 9), f, x1, res, f1;
    f = matr * x;
    //cout << "f_nach=" << f<<"\n";
    //cout << "x_tochn=" << x << "\n";

    cout << matr <<"\n";
    matr.printMatrix();
    f = matr.step1(f);
    f1 = matr * x;
    cout << "f_izm=" << f << "\n" << "f1=" << f1 << "\n" << "\n" << matr << "\n" << "f-f1=" << (f - f1).modul() << endl;
    /*cout <<" a= " << matr.aGet() << "\n" << " b= " << matr.bGet() << "\n" << " c= " << matr.cGet() << "\n" << " p= " << matr.pGet() << "\n" << " q= " << matr.qGet() << "\n";*/
    /*
    f = matr.step2(f);
    f1 = matr * x;
    cout << "f_izm=" << f << "\n" << "f1=" << f1 << "\n" << "\n" << matr << "\n" << "f-f1=" << (f - f1).modul()<<endl;
    f = matr.step3(f);
    f1 = matr * x;*/
    //cout << "f_izm=" << f << "\n" << "f1=" << f1 << "\n" << matr << "\n" << "f-f1=" << (f - f1).modul();
    x1 = matr.step4(f);
    //cout << "x1=" << x1<< "\n";
    //cout << x << "\n";
    res = x - x1;
    //cout << res;
    //cout << "Sum:  " << x+f;

    //cout << "Max error: " << res.modul();


}

