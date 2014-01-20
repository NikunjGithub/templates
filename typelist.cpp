#include <iostream>
#include <typeinfo>
using namespace std;

struct NullType{
};

template<class T,class U>
struct TypeList{

typedef T head;
typedef U tail;
    
};

typedef TypeList<int,TypeList<char,NullType> > IntTypes;

template<class TList> struct Length;
template<>struct Length<NullType>
{
    enum{value = 0};
};

template<class T,class U>
struct Length< TypeList<T,U> >
{
    enum{value = 1 + Length<U>::value};
};

template <class TList,unsigned int index> struct TypeAt;

template<class Head,class Tail>
struct TypeAt<TypeList<Head, Tail>,0 >
{
    typedef Head Result;
};

template<class Head,class Tail,unsigned int i>
struct TypeAt<TypeList<Head,Tail>, i>
{
    typedef typename TypeAt<Tail,i-1>::Result Result;
};

int main()
{
   
   IntTypes obj;
     
   int arr[Length<IntTypes>::value];
   
   cout<<Length<IntTypes>::value<<endl;
   
   TypeAt<IntTypes,2>::Result obj1;
 
   cout<<typeid(obj1).name()<<endl;
   
   return 0;
}


