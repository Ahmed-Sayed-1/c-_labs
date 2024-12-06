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
//--------------------------------------------------------------
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
//--------------------------------------------------------------
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
//--------------------------------------------------------------
    list sub_list(int start, int end)
    {
        if (start > end || start < 0 || start >= this->size || end >= this->size)
        {
            throw exception();
        }

        list s;
        s.size = end - start + 1;
        s.items = new double[s.size + 1];

        int i = 0;
        for (; start <= end; ++start, ++i)
        {
            s.items[i] = this->items[start];
        }
        s.items[i] = '\0';

        return s;
    }
//--------------------------------------------------------------
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
    //--------------------------------------------------------------
    bool sub_listIN(const list & s)
    {
        if(s.size > this->size)
        {
            return false;
        }

        for(int i=0 ; i< this-> size ;i++)
        {
            if(s.items[0] == this->items[i])
            {
               int j=0;
               while(j<s.size && this->items[i + j] == s.items[j])
               {
                j++;
               }
               if (j==s.size)
               {
                return true;
               }
            }

        }
        return false;

    }
//--------------------------------------------------------------
    bool sub_listIN(double s[],int len)
    {
        if(len > this->size)
        {
            return false;
        }

        for(int i=0 ; i< this-> size ;i++)
        {
            if(s[0] == this->items[i])
            {
               int j=0;
               while(j< len && this->items[i + j] == s[j])
               {
                j++;
               }
               if (j==len)
               {
                return true;
               }
            }

        }
        return false;

    }
//--------------------------------------------------------------
    bool operator==(const list &s)
    {
        if (this->size!=s.size)
        {
            return false;
        }else
        {
            for(int i = 0 ; i < s.size ; i++)
            {
                if(this->items[i]!=s.items[i])
                {
                    return false;
                }
            }
        }

        return true;
    }

//--------------------------------------------------------------
    double operator[](int index)
    {
        if (index < 0 || index > size)
        {
            throw exception();
        }
        return (this->items)[index];
    }
//--------------------------------------------------------------
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
//--------------------------------------------------------------
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

//--------------------------------------------------------------
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
//--------------------------------------------------------------
    /*double operator[](double index)
    {
        if (index < 0 || index >= size)
        {
            throw exception();
        }
        return (this->items)[index];
    }*/
//--------------------------------------------------------------
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
//--------------------------------------------------------------
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
//--------------------------------------------------------------
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
//--------------------------------------------------------------
    int length()
    {
        return size;
    }
//--------------------------------------------------------------
    list operator+(const list &s)
    {
        list result;
        int newSize = size + s.size;
        result.items = new double[newSize];
        result.size = newSize;
        for(int i = 0; i<size;i++)
        {
            result.items[i] = items[i];
        }
        for(int i =0;i<s.size;i++)
        {
            result.items[size+i] = s.items[i];
        }
        result.top = result.size - 1;
        return result;
    }

//--------------------------------------------------------------
    list& operator+=(const list &s)
    {
        int newSize = size + s.size;
        double *newPtr = new double[newSize + 1];

        for (int i = 0; i < size; i++)
        {
            newPtr[i] = items[i];
        }

        for (int i = 0; i < s.size; i++)
        {
            newPtr[size + i] = s.items[i];
        }

        delete[] items;
        items = newPtr;
        size = newSize;
        top = size - 1;
        return *this;
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

    for (int i = 10; i < 20; i++)
    {
        l1.push(i);
    }
    //double x1[]={1,2};
    //l1=l.sub_list(0,2);
    //l.insert(1,10002);
    // l.display();
    l+=l1;
    //cout << (l==l1 ? "true" : "false") << endl;
    //cout << l.length() << endl;
    l.display();
    return 0;
}

