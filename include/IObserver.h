#ifndef IOBSERVER_H
#define IOBSERVER_H

template <typename reciveData>
class IObserver
{
public:
    virtual void update( const reciveData){}
    ~IObserver(){}
};

template <typename passData>
class ISubject
{
public:
    virtual void notyfie(const passData){}
    virtual void attach(IObserver<passData> &){}
    virtual void detach(IObserver<passData> &){}
    ~ISubject(){}
};



#endif // IOBSERVER_H
