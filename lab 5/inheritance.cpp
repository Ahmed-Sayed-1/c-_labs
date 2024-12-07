#include <iostream>

using namespace std;
class base
{
    private:
        int a;
    protected:
        int b;
    public:

    base()
    {
        cout<< "base constractour call"<< endl;
    }
    base(int a,int b)
    {
        this-> a =a;
        this-> b =b;
        cout<< "base parameterized constractour call"<< endl;
    }
    void set_a()
    {
        this-> a =a;
    }
    void set_b()
    {
        this-> b=b;
    }
    void b_display(base b)
    {
        cout<<"display  base"<<endl;
    }
    ~base()
    {
        cout<< "base destractour call"<< endl;

    }
};
class derived : public base
{
    private:
        int c;
    protected:

    public:
    derived()
    {
        cout<< "derived constractour call"<< endl;

    }
    derived(int c):base( 5, 5)
    {
        this->c=c;
        cout<< "derived parameterized constractour call"<< endl;
    }
    derived( int a,int b ,int c):base( a, b)
    {
        this->c=c;
        cout<< "derived parameterized constractour call"<< endl;
    }
    void set_c()
    {
        this-> c =c;
    }

    void d_display(base b)
    {
        cout<<"display base in derived"<<endl;
    }
    void d_display(derived b)
    {
        cout<<"display derived in derived"<<endl;
    }
    ~derived()
    {
        cout<< "derived destractour call"<< endl;
    }

};
class secondDerived : public derived
{
    private:
        int d;
    protected:

    public:
    secondDerived()
    {
        cout<< "secondDerived constractour call"<< endl;
    }
    secondDerived(int a,int b, int c, int d):derived(a,b,c)
    {
        this->d=d;
        cout<< "secondDerived parameterized constractour call"<< endl;
    }
    void set_d()
    {
        this-> d =d;
    }
    ~secondDerived()
    {
        cout<< "secondDerived constractour call"<< endl;
    }

};

int main()
{
    base b1;
    derived d1;
    d1.d_display(d1);
    //derived d2(10);
    //derived d3(1,2,3);
    //secondDerived sd1;
    // secondDerived(1,2,3,4);
    //base *b2= &d1;
    //cout << "Hello world!" << endl;
    return 0;
}
