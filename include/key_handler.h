#ifndef KEY_HANDLER_H
#define KEY_HANDLER_H

#include <cstdio>
#include <termios.h>

#include <unistd.h>
#include <iostream>

#include <sys/stat.h>
#include <fcntl.h>
#include <IObserver.h>
#include <def.h>
#include <list>
#include <algorithm>
#include <boost/thread.hpp>

class CKeyHandler: public ISubject<Direction>
{
public:
    CKeyHandler();
    void parseKeyMove();
    void stopKeboardRead();

    //ISubject
    virtual void notyfie(const Direction);
    virtual void attach(IObserver<Direction> *);
    virtual void detach(IObserver<Direction> *);

private:
    char getKeyFromKeybord();
    bool getReadKey();

    std::list<IObserver<Direction> *> _observerList;
    char _key;
    termios _oldt;
    termios _newt;
    boost::mutex _mtxReadKey;
    bool _readKey;
};


#endif // KEY_HANDLER_H
