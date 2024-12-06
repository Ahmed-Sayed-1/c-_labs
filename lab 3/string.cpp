#include <iostream>

using namespace std;

class String
{
private:

    char *ptr = nullptr;
    int size = 0;
    int Str_len(char text[])
    {
        int i = 0;
        while(text[i] != '\0')
        {
            i++;
        }
        return i;
    }
public:

friend ostream& operator<<(ostream& out, const String& st);

friend istream& operator>>(istream& in, String& st);



    String(){}
//--------------------------------------------------------------
    String(const char *st)
    {
        int counter = 0;

        while (st[counter]!='\0')
        {
            counter++;
        }

        size = counter;
        ptr = new char[size+1];

        for (int i = 0;i<size;i++)
        {
            ptr[i] = st[i];
        }
        ptr[size] = '\0';
    }
//--------------------------------------------------------------
    String(const String & a)
    {

        size = a.size;
        ptr = new char[size];
        int i ;
        for (int i = 0;i<size-1;i++)
        {
            ptr[i] = (a.ptr)[i];
        }
        ptr[i] = '\0';
    }
//--------------------------------------------------------------
    void operator=(const char *st)
    {
        int counter = 0;

        while (st[counter]!='\0'){
            counter++;
        }

        size = counter;
        ptr = new char[size+1];

        for (int i = 0;i<size;i++){
            ptr[i] = st[i];
        }
        ptr[size] = '\0';
    }
//--------------------------------------------------------------
    String& operator=(const String &other)
    {

    if (this != &other) {

        delete[] ptr;
        size = other.size;
        ptr = new char[size];

        for (int i = 0; i < size; i++)
        {
            ptr[i] = other.ptr[i];
        }
    }
    return *this;
    }
//--------------------------------------------------------------
    String operator+(const String &other)const
    {
        String result;
        int newSize = size + other.size;
        result.ptr = new char[newSize];
        result.size = newSize;
        for(int i = 0; i<size;i++)
        {
            result.ptr[i] = ptr[i];
        }
        for(int i =0;i<other.size;i++)
        {
            result.ptr[size+i] = other.ptr[i];
        }
        result.ptr[newSize] = '\0';
        return result;
    }
//--------------------------------------------------------------
    String& operator+=(const String &s)
    {
        int newSize = size + s.size;
        char *newPtr = new char[newSize + 1];

        for (int i = 0; i < size; i++)
        {
            newPtr[i] = ptr[i];
        }

        for (int i = 0; i < s.size; i++)
        {
            newPtr[size + i] = s.ptr[i];
        }

        newPtr[newSize] = '\0';

        delete[] ptr;
        ptr = newPtr;
        size = newSize;

        return *this;
    }
//--------------------------------------------------------------
    String& operator+=(char *s)
    {
        int newSize = size + Str_len(s);
        char *newPtr = new char[newSize + 1];

        for (int i = 0; i < size; i++)
        {
            newPtr[i] = ptr[i];
        }

        for (int i = 0; i < Str_len(s); i++)
        {
            newPtr[size + i] = s[i];
        }

        newPtr[newSize] = '\0';

        delete[] ptr;
        ptr = newPtr;
        size = newSize;

        return *this;
    }
//--------------------------------------------------------------
    String str_concat(const String &s)
    {
        String result;
        int newSize = size + s.size;
        result.ptr = new char[newSize];
        result.size = newSize;
        for(int i = 0; i<size;i++)
        {
            result.ptr[i] = ptr[i];
        }
        for(int i =0;i<s.size;i++)
        {
            result.ptr[size+i] = s.ptr[i];
        }
        result.ptr[newSize] = '\0';
        return result;
    }
//--------------------------------------------------------------
    String str_concat(char *s)
    {
        String result;
        int newSize = size + Str_len(s);
        result.ptr = new char[newSize];
        result.size = newSize;
        for(int i = 0; i<size;i++)
        {
            result.ptr[i] = ptr[i];
        }
        for(int i =0;i<Str_len(s);i++)
        {
            result.ptr[size+i] = s[i];
        }
        result.ptr[newSize] = '\0';
        return result;
    }
//--------------------------------------------------------------
    int len()
    {
        return size;
    }
//--------------------------------------------------------------
    bool operator==(const String &s)
    {
        if (this->size!=s.size)
        {
            return false;
        }else
        {
            for(int i = 0 ; i < s.size ; i++)
            {
                if(this->ptr[i]!=s.ptr[i])
                {
                    return false;
                }
            }
        }

        return true;
    }
//--------------------------------------------------------------
    char operator[](int index)
    {
        if(index<0 || index>size-1)
        {
            throw  exception();
        }
        return ptr[index];
    }
//--------------------------------------------------------------
    int Ahmed_Strcmp(String &str2)
    {

        if(this->len() < str2.len()){
            return -1;
        }
        if( this->len() > str2.len()){
            return 1;
        }


        for(int i =0; (this->ptr)[i] != '\0'; i++)
        {
            if((this->ptr)[i] > (str2.ptr)[i]){
                return 1;
            }
            if((this->ptr)[i] < (str2.ptr)[i]){
                return -1;
            }
        }
    return 0;
    }
//--------------------------------------------------------------
    int Ahmed_Strcmp(char *str2)
    {

        if(this->len() < Str_len(str2)){
            return -1;
        }
        if( this->len() > Str_len(str2)){
            return 1;
        }


        for(int i =0; (this->ptr)[i] != '\0'; i++)
        {
            if((this->ptr)[i] > str2[i]){
                return 1;
            }
            if((this->ptr)[i] < str2[i]){
                return -1;
            }
        }
    return 0;
    }

//--------------------------------------------------------------
    void Str_cpy(String &source)
    {
        int i=0;
        char * s= new char[source.size+1];;
            for(i; (source.ptr)[i] != '\0'; i++)
            {
                 s[i]=(source.ptr)[i];
            }

        s[i] = '\0';
        this->size=i;
        delete [] ptr;
        ptr=s;

    }
//--------------------------------------------------------------
    void Str_cpy(char * source)
    {
        int i=0;
        char * s= new char[Str_len(source)+1];;
            for(i; source[i] != '\0'; i++)
            {
                 s[i]=source[i];
            }

        s[i] = '\0';
        this->size=i;
        delete [] ptr;
        ptr=s;

    }
//--------------------------------------------------------------
    String sub_Str(int start, int end)
    {
        if (start > end || start < 0 || start >= this->size || end >= this->size)
        {
            throw exception();
        }

        String s;
        s.size = end - start + 1;
        s.ptr = new char[s.size + 1];

        int i = 0;
        for (; start <= end; ++start, ++i)
        {
            s.ptr[i] = this->ptr[start];
        }
        s.ptr[i] = '\0';

        return s;
    }
//--------------------------------------------------------------
    bool sub_StrIN(const String & s)
    {
        if(s.size > this->size)
        {
            return false;
        }

        for(int i=0 ; i< this-> size ;i++)
        {
            if(s.ptr[0] == this->ptr[i])
            {
               int j=0;
               while(j<s.size && this->ptr[i + j] == s.ptr[j])
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
    bool sub_StrIN(char * s)
    {
        if(Str_len(s) > this->size)
        {
            return false;
        }
        int str_len=Str_len(s);

        for(int i=0 ; i< this-> size ;i++)
        {
            if(s[0] == this->ptr[i])
            {
               int j=0;
               while(j< str_len && this->ptr[i + j] == s[j])
               {
                j++;
               }
               if (j==str_len)
               {
                return true;
               }
            }

        }
        return false;

    }
//--------------------------------------------------------------
    bool operator>(const String &s) const
    {
        int min = (this->size < s.size) ? this->size : s.size;

        for (int i = 0; i < min ; i++)
        {
            if (this->ptr[i] > s.ptr[i])
                return true;
            if (this->ptr[i] < s.ptr[i])
                return false;
        }

        return this->size > s.size;
    }
//--------------------------------------------------------------
bool operator<(const String &s) const
{
    int min = (this->size < s.size) ? this->size : s.size;

    for (int i = 0; i < min; i++)
    {
        if (this->ptr[i] < s.ptr[i])
            return true;
        if (this->ptr[i] > s.ptr[i])
            return false;
    }

    return this->size < s.size;
}
//--------------------------------------------------------------
    ~String()
    {
        delete[] ptr;
    }
//--------------------------------------------------------------
};

    ostream& operator<<(ostream& out, const String& st)
    {
        for(int i = 0;i<st.size;i++){
            out << st.ptr[i];
        }
    return out;
    };

istream& operator>>(istream& in, String& st)
{

    char buffer[1000];
    in >> buffer;

    delete[] st.ptr;
    int length = 0;
    while (buffer[length] != '\0') {
        length++;
    }

    st.ptr = new char[length + 1];
    st.size = length;

    for (int i = 0; i < length; i++) {
        st.ptr[i] = buffer[i];
    }
    st.ptr[length] = '\0';

    return in;

};

int main(){
    // String x("test");
    // cout<<x.len();
    // cout<<x;
    // cout<<x[1];
    // String y("no");
    // cout<<endl;
    // x=y;
    // cout<<x;
    //String x,y;
    String x="lhmed";
    String y=" hme";
    x+="    lol";
    // x = "123";
    // y = "456";
    // y = x+y;
    // cout<<y<<endl;
    // cout<<x<<endl;
    //cin >> x;
    cout<<"\n"<<x<<endl;
    return 0;
}
