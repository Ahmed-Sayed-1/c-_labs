#include <iostream>

using namespace std;

class complex_num
{
    double real;
    double img;

public:
    complex_num (double real = 0 ,double img = 0)
    {
        this->real = real;
        this->img = img;
    }
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
    }
    void setComplex(int real ,int img)
    {
        this->real = real;
        this->img = img;
    }
    complex_num * operator+=(complex_num c)
    {
        this->real+=c.real;
        this->img+=c.img;
        return this;

    }

    bool operator==(complex_num c)
    {
        return (this->real == c.real && this-> img == c.img);
    }

    complex_num operator+(complex_num c)
    {
        complex_num x;
        x.real = this->real + c.real;
        x.img = this->img + c.img;
        return x;
    }

    complex_num operator+(int c)
    {
        complex_num x;
        x.real = this->real + c;
        return x;
    }
    complex_num operator-(complex_num c)
    {
        complex_num x;
        x.real = this->real - c.real;
        x.img = this->img - c.img;
        return x;
    }
    complex_num operator-(int c)
    {
        complex_num x;
        x.real = this->real - c;
        return x;
    }



    complex_num operator++(){
        this->real++;
        this->img++;
        return *this;
    }

    complex_num operator++(int n){
    complex_num c =*this;
    this->real++;
    this->img++;
    return c;
    }

    ~complex_num()
    {
        cout<<"good by"<<endl;
    }
};


int main()
{

    complex_num c;

    c.set_real(1);
    c.set_img(1);

    complex_num x;
    x.set_real(1);
    x.set_img(1);

    c++;
   // c+=x;
    c.display();
  cout << ((c == x) ? "true" : "false") << endl;

    return 0;
};
