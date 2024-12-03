#include <iostream>
#include <stdexcept>
using namespace std;

class stack
{
    double *items;
    int top;
    int size;

public:
    static int stacksNum;
    stack(int size)
    {
        this->size = size;
        items = new double[size];
        top = -1;
        stacksNum++;
    }


    int push(double data)
    {
        if (top == size - 1)
        {
            return 0;
        }
        else
        {
            items[++top] = data;
            return 1;
        }
    }


    double pop()
    {
        if (top == -1)
        {
            throw exception();
        }
        else
        {
            return items[top--];
        }
    }


    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << items[i] << "\t";
        }
        cout << endl;
    }


    ~stack()
    {
        delete[] items;
        stacksNum--;
        cout << "\nBye bye" << endl;
    }
};
int stack::stacksNum = 0;
int main()
{
    double data;
    stack s(5);
    stack s1(5);
    stack s2(5);

    cout << (s.push(1) == 0 ? "Failed" : "Success") << endl;
    cout << (s.push(2) == 0 ? "Failed" : "Success") << endl;
    cout << (s.push(3) == 0 ? "Failed" : "Success") << endl;
    cout << (s.push(4) == 0 ? "Failed" : "Success") << endl;
    cout << (s.push(5) == 0 ? "Failed" : "Success") << endl;
    cout << (s.push(6) == 0 ? "Failed" : "Success") << endl;


    s.display();


    try
    {
        data = s.pop();
        cout << "Success, data = " << data << endl;
    }
    catch (exception &e)
    {
        cout << "Failed: " << endl;
    }

    s.display();
    cout<<stack::stacksNum<<endl;

    return 0;
}
