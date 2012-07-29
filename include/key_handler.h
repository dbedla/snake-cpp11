#ifndef KEY_HANDLER_H
#define KEY_HANDLER_H

#include <cstdio>
#include <termios.h>

#include <unistd.h>
#include <iostream>

#include <sys/stat.h>
#include <fcntl.h>


class CKeyHandler
{
public:
    CKeyHandler();
    char getKeyFromKeybord();

private:
    char _key;
    termios _oldt;
    termios _newt;
};


#endif // KEY_HANDLER_H
