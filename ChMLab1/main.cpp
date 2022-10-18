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
    /*int n,k,l,d1,d2;

    cout << "Input size of matrix: ";
    cin >> n;
    cout << "Input number of first vector: ";
    cin >> k;
    cout << "Input number of second vector: ";
    cin >> l;
    cout << "Input left: ";
    cin >> d1;
    cout << "Input right: ";
    cin >> d2;
    if (d2 < d1)
    {
        int now = d1;
        d1 = d2;
        d2 = now;
    }
    if (k > l)
    {
        int now = k;
        k = l;
        l = now;
    }
    vector<int> a,b,c,p,q;
    for (int i = 0; i < n; i++)
    {
        b.push_back(rand() % (d2 - d1 + 1) + d1);
        if (i != k )
            p.push_back(rand()%(d2-d1+1) + d1);
        else
            p.push_back(b[b.size()-1]);
        if(i!=l)
            q.push_back(rand() % (d2 - d1 + 1) + d1);
        else
            q.push_back(b[b.size() - 1]);
    }
    for (int i = 0; i < n-1; i++)
    {
        if (i != k-1 && i!=l-1)
        {
            a.push_back(rand() % (d2 - d1 + 1) + d1);
        }
        else if(i==k-1)
        {
            a.push_back(p[k - 1]);
        }
        else if (i == l-1 )
        {
            a.push_back(q[l - 1]);
        }

        if (i != k && i != l)
        {
            c.push_back(rand() % (d2 - d1 + 1) + d1);
        }
        else if (i == k)
        {
            c.push_back(p[k + 1]);
        }
        else if (i == l)
        {
            c.push_back(q[l + 1]);
        }
    }
    cout << "a:\n";
    print(a);
    cout << "\nb:\n";
    print(b);
    cout << "\nc:\n";
    print(c);
    cout << "\np:\n";
    print(p);
    cout << "\nq:\n";
    print(q);*/

    Matrix matr(8, -10, 10, -100, 100, -10, 10, -10, 10);
    Vec x(8, -10, 10), f, x1, res, f1;
    f = matr * x;
    //cout << "f_nach=" << f<<"\n";
    //cout << "x_tochn=" << x << "\n";

    //cout << matr <<"\n";

    f = matr.step1(f);
    f1 = matr * x;
    //cout << "f_izm="<<f << "\n" << "f1=" << f1 << "\n" << matr << "\n"<<"f-f1="<<(f-f1).modul();
    f = matr.step2(f);
    f1 = matr * x;
    //cout << "f_izm=" << f << "\n" << "f1=" << f1 << "\n" << matr << "\n" << "f-f1=" << (f - f1).modul();
    f = matr.step3(f);
    f1 = matr * x;
    //cout << "f_izm=" << f << "\n" << "f1=" << f1 << "\n" << matr << "\n" << "f-f1=" << (f - f1).modul();
    x1 = matr.step4(f);
    //cout << "x1=" << x1<< "\n";
    //cout << x << "\n";
    res = x - x1;
    //cout << res;
    cout << "Max error: " << res.modul();


}

