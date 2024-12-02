#include <iostream>

using namespace std;

class complex_num
{
    double real;
    double img;

public:
    void set_real(double real)
    {
        this->real = real;
    }

    void set_img(double img)
    {
        this->img = img;
    }

    double get_real()
    {
        return real;
    }

    double get_img()
    {
        return img;
    }

    complex_num add(complex_num c)
    {
        complex_num x;
        x.real = this->real + c.real;
        x.img = this->img + c.img;
        return x;
    }

    complex_num sub(complex_num c)
    {
        complex_num x;
        x.real = this->real - c.real;
        x.img = this->img - c.img;
        return x;
    }

    void display()
    {
        if (real != 0)
        {
           cout<<real;
        }
        if (img > 0)
        {
            cout << (real != 0 ? "+" : "") << img<<"i"<<endl;
        }
        else if(img < 0)
        {
            cout<<img<<"i"<<endl;
        }
};
    void swap1(int *x,int *y)
    {
        *x=*x+*y;
        *y=*x-*y;
        *x=*x-*y;
    }
    void swap2(int &x,int &y)
    {
        x=x+y;
        y=x-y;
        x=x-y;
    }
    void swap3(int x,int y)
    {
        x=x+y;
        y=x-y;
        x=x-y;
    }


int main()
{

    complex_num c;
    c.set_real(-10.0);
    c.set_img(-15.0);

    complex_num x;
    x.set_real(10);
    x.set_img(15);


    complex_num v = c.add(x);

    v.display();

    return 0;
};
