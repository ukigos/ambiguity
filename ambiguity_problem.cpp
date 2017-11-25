//Sloving the ambiguity problem or diamond problem using scope resolution operator...
#include<iostream>
using namespace std;
class one{
protected:
  int a;
  int b;
public:
  void getdata(){
    cout<<"enter two integers."<<endl;
    cin>>a>>b;
  }
  void display(){
    cout<<"Integers are: "<<a<<" and "<<b<<endl;
  }
};
class two : public one
{
protected:
  char c;
  char d;
public:
  void getdata(){
    one :: getdata();
    cout<<"enter two characters."<<endl;
    cin>>c>>d;
  }
  void display(){
    one :: display();
    cout<<"Characters are: "<<c<<" and "<<d<<endl;
  }
};
class three : public one
{
protected:
  float e;
  float f;
public:
  void getdata(){
    cout<<"enter two values."<<endl;
    cin>>e>>f;
  }
  void display(){
    cout<<"Values are: "<<e<<" and "<<f<<endl;
  }
};
class fourth : public two, public three
{
protected:
  int g;
  int h;
public:
  void getdata(){
    two :: getdata();
    three :: getdata();
    //one :: getdata();      statement creates ambiguity as path is not specified
    cout<<"enter two integers."<<endl;
    cin>>g>>h;
  }
  void display(){
    two :: display();
    three :: display();
  //  one :: display();        statement creates ambiguity as path is not specified
    cout<<"Integers are: "<<g<<" and "<<h<<endl;
  }
};
int main()
{
  fourth f;
  f.getdata();
  f.display();
  return 0;
}
