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
  int x=1;
  int y=2;
  
  swap1(x,y);
  cout<<x<<"\t"<<y<<endl;
  
  swap2(x,y);
  cout<<x<<"\t"<<y<<endl;
  
  swap3(x,y);
  cout<<x<<"\t"<<y<<endl;

    return 0;
};
