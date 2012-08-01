#include "../include/CGameControler.h"

#include "../include/CLogger.h"

void CGameControler::stopKeboardRead()
{
    boost::lock_guard<boost::mutex>  guard( _mtxReadKey);
    _readKey = false;
}

void CGameControler::RunGame()
{
    std::function<void(PointsList&)> move = std::bind(&CMoveSnake::moveObj,
                                                      &_moveSnakeObj, std::placeholders::_1) ;
    std::function<void(CMoveSnake&)> th_key_handler_func =
            std::bind(&CGameControler::parseKeyMove, this, std::placeholders::_1 );
    boost::thread workerThreadKeyHandler(th_key_handler_func, boost::ref(_moveSnakeObj));

    while(_play)
    {
        logger.Log("snake pos", _snake->getFrameElements());
        boost::this_thread::sleep(boost::posix_time::milliseconds(_gameSpeed));
        _snake->moveSnake(move);
        _frame->clearFrame();
        _frame->drawObjIntoFrame(*_snake, GRAPHIC_SNAKE_BODY);
        _frame->drawObjIntoFrame(*_wall, GRAPHIC_WALL);
        _frame->drawObjIntoFrame(*_eatMe, GRAPHIC_ELEMENT_TO_EAT);
        _frame->drawFrame();

        if(_colision( *_wall, *_snake))
        {
            std::cout<<"kolizja\nkoniec gry\n";
            break;
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
    }
    stopKeboardRead();
    workerThreadKeyHandler.join();
}

void CGameControler::parseKeyMove(CMoveSnake &DirectionKeeper)
{
    while(_readKey)
    {
    char k = _keyHandler.getKeyFromKeybord();
    switch (k)
    {
        case LEFT:
        {
            DirectionKeeper.setDirection(LEFT);
            break;
        }
        case RIGHT:
        {
            DirectionKeeper.setDirection(RIGHT);
            break;
        }
        case DOWN:
        {
            DirectionKeeper.setDirection(DOWN);
            break;
        }
        case UP:
        {
            DirectionKeeper.setDirection(UP);
            break;
        }
        case 'q':
        {
            _play = false;
        }
        default:
        {
        }
    }
    }

}

CGameControler::CGameControler(): logger("log_File.txt")
{
    std::ios::sync_with_stdio(true);
    _play = _readKey = true;
    _frame.reset( new CFrame());
    _wall.reset( new CBasicWall(_frame->getWidith(), _frame->getHeight()) );
    _eatMe.reset( new CItemToEat(_frame->getWidith()-1, _frame->getHeight()-1) );
    _snake.reset(new CSnake( CPoint(_frame->getWidith()/2, _frame->getHeight()/2), MIN_SNAKE_LENGTH)  );
    _gameSpeed = START_SPEED;
}


void CGameControler::addSingleNonColisionElementToEat()
{
    CLogger l("eatme.txt");
    CPoint newElementToEat;

    do
    {
        newElementToEat = _eatMe->createRandomPoint();
        l.Log("randompoint: ", newElementToEat);
        _eatMe->addElementToEat(newElementToEat);
    }while( _colision(*_eatMe, *_wall) || _eatMe->getNumberOfElementsToEat()==0 );
    l.Log("point at end: ", newElementToEat);

}

void CGameControler::speedUP()
{
    unsigned int newSpeed = _gameSpeed - SPEED_UP;
    if(newSpeed < _gameSpeed)
    {
        _gameSpeed = newSpeed;
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
