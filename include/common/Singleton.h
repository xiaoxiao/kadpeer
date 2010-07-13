#ifndef __SINGLETON_H_
#define __SINGLETON_H_
#include<iostream>
template <class Type>
class Singleton
{
public:
    static Singleton *getInstance();
    virtual ~Singleton();
    Type getVal();
    void setVal(Type v);
protected:
    Singleton();
    static Singleton *instance;
    Type val;
};

template<class Type>
Singleton<Type>::Singleton(){ 
}
template<class Type>
Singleton<Type>::~Singleton()
{
    delete instance;
}
template<class Type>
Singleton<Type>* Singleton<Type>::instance=new Singleton<Type>();

template<class Type>
Singleton<Type>* Singleton<Type>::getInstance()
{
    return instance;
}
template<class Type>
void Singleton<Type>::setVal(Type v)
{
    val=v;
}

template<class Type>
Type Singleton<Type>::getVal()
{
    return val;
}
#endif
