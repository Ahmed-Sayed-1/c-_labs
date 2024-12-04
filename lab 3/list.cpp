#include <iostream>
#include <stdexcept>
using namespace std;

class list
{
    double *items;
    int top;
    int size;

public:
    static int listsNum;

    list()
    {
        this->size = 0;
        items = nullptr;
        top = -1;
        listsNum++;
    }

    list(const list &l)
    {
        this->size = l.size;
        this->top = l.top;
        if (size > 0)
        {
            this->items = new double[size];
            for (int i = 0; i < size; i++)
            {
                this->items[i] = l.items[i];
            }
        }
        else
        {
            this->items = nullptr;
        }
        listsNum++;
    }

    list &operator=(const list &l)
    {
        if (this == &l)
        {
            return *this;
        }


        delete[] items;


        this->size = l.size;
        this->top = l.top;
        if (size > 0)
        {
            this->items = new double[size];
            for (int i = 0; i < size; i++)
            {
                this->items[i] = l.items[i];
            }
        }
        else
        {
            this->items = nullptr;
        }

        return *this;
    }

    bool operator==(const list &l) const
    {
        if (this->size != l.size)
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            if (this->items[i] != l.items[i])
            {
                return false;
            }
        }

        return true;
    }

    void insert(int index, double data)
    {
        if (index < 0 || index > size)
        {
            throw exception();
        }

        double *newItems = new double[size + 1];
        for (int i = 0, j = 0; i < size + 1; i++)
        {
            if (i == index)
            {
                newItems[i] = data;
            }
            else
            {
                newItems[i] = items[j++];
            }
        }

        delete[] items;
        items = newItems;
        size++;
        top++;
    }


    void push(double data)
    {
        double *newItems = new double[size + 1];
        for (int i = 0; i < size; i++)
        {
            newItems[i] = items[i];
        }
        newItems[size] = data;

        delete[] items;
        items = newItems;
        size++;
        top++;
    }


    double pop()
    {
        if (top == -1)
        {
            throw exception();
        }

        double value = items[top];
        top--;
        size--;
        return value;
    }
    double remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw exception();
        }
        double x=(this->items)[index];
        double *newItems = new double[size - 1];
        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != index)
            {
                newItems[j++] = items[i];
            }
        }

        delete[] items;
        items = newItems;
        size--;
        top--;
        return x;
    }

    double removeValue(double value)
    {
        int index = -1;

        for (int i = 0; i < size; i++)
        {
            if (items[i] == value)
            {
                index = i;
                i=size;
            }
        }

        if (index == -1)
        {
            throw exception();
        }

        return  remove(index);
    }

    void display()
    {
        if (top == -1)
        {
            cout << "List is empty." << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << items[i] << "\n";
        }
        cout << endl;
    }

    int length()
    {
        return size;
    }

    ~list()
    {
        delete[] items;
        listsNum--;
        cout << "\nBye bye" << endl;
    }
};

int list::listsNum = 0;

int main()
{
    list l;
    list l1;

    for (int i = 0; i < 10; i++)
    {
        l.push(i);
    }

    for (int i = 1000; i < 1010; i++)
    {
        l1.push(i);
    }

    l = l1;
    //l.insert(1,10002);
    l.display();

    cout << l.removeValue(1000) << endl;
    cout << l.length() << endl;
    l.display();
    return 0;
}

