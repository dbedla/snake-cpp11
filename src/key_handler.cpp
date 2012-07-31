#include "../include/key_handler.h"
#include <iostream>

CKeyHandler::CKeyHandler()
{
    _key = '\0';

}

char CKeyHandler::getKeyFromKeybord()
{

    char returnKeyVal;

    tcgetattr( STDIN_FILENO, &_oldt );
    _newt = _oldt;
    _newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &_newt );
    returnKeyVal = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &_oldt );

    return returnKeyVal;

}

