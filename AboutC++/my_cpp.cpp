#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class String
{
  public:
    String()
      :data_(new char[1])
    {
      *data_ = '\0';
    }
    String(const char* str)
      :data_ (new char[strlen(str) + 1])
    {
      strcpy(data_,str);
    }

  private:
    char* data_;
}
int main()
{

  cout<<"new cpp code"<<endl;
  return 0;
}
