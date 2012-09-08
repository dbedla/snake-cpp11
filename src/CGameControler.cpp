#include "../include/CGameControler.h"

//#include "../include/CLogger.h"



CGameControler* CGameControler::_instance = NULL;

CGameControler& CGameControler::getInstance()
{
    if(_instance == NULL)
    {
        _instance = new CGameControler;
    }
    return *_instance;
}

void CGameControler::RunGame()
{
    _keyHandler.attach(&_moveSnakeObj);
    std::function<void()> th_key_handler_func = std::bind(&CKeyHandler::parseKeyMove, &_keyHandler );
    boost::thread workerThreadKeyHandler(th_key_handler_func);

    while(_play)
    {
        //logger.Log("snake pos", _snake->getFrameElements());
        boost::this_thread::sleep(boost::posix_time::milliseconds(_gameTimeout));

        _play = snakeDriver();
        frameDriver();
    }
    std::cout<<"game over\n";
    _keyHandler.stopKeboardRead();
    workerThreadKeyHandler.join();
}



CGameControler::CGameControler()
{
    std::ios::sync_with_stdio(true);
    _play = true;
    _frame.reset( new CFrame());
    _wall.reset( new CBasicWall(_frame->getWidith(), _frame->getHeight()) );
    _eatMe.reset( new CItemToEat(_frame->getWidith()-1, _frame->getHeight()-1) );
    _snake.reset(new CSnake( CPoint(_frame->getWidith()/2, _frame->getHeight()/2), MIN_SNAKE_LENGTH)  );
    _gameTimeout = MAX_TIMEOUT;
}


void CGameControler::addSingleNonColisionElementToEat()
{
    //CLogger l("eatme.txt");
    CPoint newElementToEat;

    do
    {
        newElementToEat = _eatMe->createRandomPoint();
      //  l.Log("randompoint: ", newElementToEat);
        _eatMe->addElementToEat(newElementToEat);
    }while( _colision(*_eatMe, *_wall) || _eatMe->getNumberOfElementsToEat()==0 );
    //l.Log("point at end: ", newElementToEat);

}

void CGameControler::speedUP()
{
    _gameTimeout -= DELTA_TIMEOUT;
    if(_gameTimeout <= MIN_TIMEOUT)
    {
        _gameTimeout = MIN_TIMEOUT;
    }
}

bool CGameControler::snakeEatElement()
{
    if( _colision(*_snake, *_eatMe) )
    {
        const PointsList& snakeBody = _snake->getFrameElements();
        std::for_each(snakeBody.begin(), snakeBody.end(),
                      [&_eatMe](const CPoint p){ _eatMe->removeElementToEat(p); } );
        _snake->addBodyPart();
        return true;
    }
    return false;
}

void CGameControler::frameDriver()
{
    _frame->clearFrame();
    _frame->drawObjIntoFrame(*_snake, GRAPHIC_SNAKE_BODY);
    _frame->drawObjIntoFrame(*_wall, GRAPHIC_WALL);
    _frame->drawObjIntoFrame(*_eatMe, GRAPHIC_ELEMENT_TO_EAT);
    _frame->drawFrame();
}

bool CGameControler::snakeDriver()
{
    std::function<void(PointsList&)> move = std::bind(&CMoveSnake::moveObj,
                                                      &_moveSnakeObj, std::placeholders::_1) ;
    if(_colision( *_wall, *_snake))
    {
        return false;
    }
    if(_eatMe->getNumberOfElementsToEat() == 0)
    {
        addSingleNonColisionElementToEat();
    }
    else
    {
        if(snakeEatElement())
        {
            speedUP();
        }

    }
    _snake->moveSnake(move);
    return true;
}
