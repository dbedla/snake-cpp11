#include <key_handler.h>

CKeyHandler::CKeyHandler()
{
    _key = '\0';
    _readKey = true;

}

void CKeyHandler::stopKeboardRead()
{
    boost::lock_guard<boost::mutex>  guard( _mtxReadKey);
    _readKey = false;
}

bool CKeyHandler::getReadKey()
{
    boost::lock_guard<boost::mutex>  guard( _mtxReadKey);
    return _readKey;
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

void CKeyHandler::parseKeyMove()
{
    //I also know how to use switch instruction :D
    while(getReadKey())
    {
        char k = getKeyFromKeybord();
        switch (k)
        {
            case LEFT:
            case RIGHT:
            case DOWN:
            case UP:
            {
                notyfie((Direction) k);
                break;
            }

        }
    }
}

void CKeyHandler::notyfie(const Direction passData)
{
    std::for_each(_observerList.begin(), _observerList.end(),
                  [&passData](IObserver<Direction> *observer){observer->update(passData);});
}

void CKeyHandler::attach(IObserver<Direction> *newObserver)
{
 _observerList.push_back(newObserver);
}

void CKeyHandler::detach(IObserver<Direction> *oldObserver)
{
     _observerList.remove(oldObserver);
}
